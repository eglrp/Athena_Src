#ifndef __ne_msg_t_hpp__
#define __ne_msg_t_hpp__

//#include "nad_base.h"
#include "ne_msg_base_t.hpp"

#include "config/nad_config.h"

//目前暂定默认消息版本号是1
#define MSG_VER_1 1

namespace nad_lcm
{

//ne_msg_t仅用于网元间通讯，使用publish_nemsg发消息，不能直接使用ne_msg_base_t通讯!!
//网元内通讯lcm原生的方法publsh，不要使用ne_msg_t
template <class T>
class ne_msg_t : public ne_msg_base_t
{
public:
    //消息体，如:fam/msg/nad_msg_co中的消息
    T body;

public:
    //构造函数
    ne_msg_t() : ne_msg_base_t()
    {
        //header.version = MSG_VER_1;
        header.version = 1;                //暂未使用
        header.peer_ne_name = "";                   //接受者的网元名，如obu_name、rsu_name、csu_name
        header.peer_channel = "";                   //对方的信道名，默认与消息名相同，如cr_info_report
        header.local_ne_name = "";                  //默认使用全局配置中的本网元名称
        header.local_channel = "";                  //暂未使用
        header.session_name = "";                   //暂未使用
        header.type = 0;                            //暂未使用
        header.time = 0;                            //暂未使用
        header.opt = 0;                             //暂未使用
    }

    //构造函数
    ne_msg_t(std::string peer_ne_name, std::string peer_channel) : ne_msg_base_t()
    {
        header.version = MSG_VER_1;                 //暂未使用
        header.peer_ne_name = peer_ne_name;         //接受者的网元名，如obu_name、rsu_name、csu_name
        header.peer_channel = peer_channel;         //对方的信道名，默认与消息名相同，如cr_info_report
        header.local_ne_name = "";                  //默认使用全局配置中的本网元名称
        header.local_channel = "";                  //暂未使用
        header.session_name = "";                   //暂未使用
        header.type = 0;                            //暂未使用
        header.time = 0;                            //暂未使用
        header.opt = 0;                             //暂未使用
    }

    //把ne_msg_t.body数据写入ne_msg_t.data
    inline void encode_body()
    {
        //body->data
        int len = body.getEncodedSize();
        char buf2[len];
        data_len = body.encode(buf2, 0, len);
        if (data_len != len)
        {
            std::cout << "nad_msg::encode error!" << std::endl;
        }
        data.assign(buf2, buf2 + len);
    }

    //从消息流读数据到ne_msg_t
    inline int decode(const void *buf, int offset, int maxlen)
    {
        //调用父类的decode
        int pos = ne_msg_base_t::decode(buf, offset, maxlen);
        if (pos <= 0)
        {
            return pos;
        }

        //data->body
        int len = 0;
        std::string buf2(data.begin(), data.end());

        len = body.decode((void *)buf2.c_str(), 0, data_len);
        if (len < 0)
        {
            std::cout << "ne_msg_t::decode chan=" << header.peer_channel << std::endl;
            std::cout << "ne_msg_t::decode name=" << header.local_ne_name<< std::endl;
            std::cout << "nad_msg::decode error!" << std::endl;
        }

        return pos;
    }

    //从消息流读数据到ne_msg_t
    inline void decode_body(T &msg_body) const
    {
        //data->body
        int len = 0;
        std::string buf2(data.begin(), data.end());
        len = msg_body.decode((void *)buf2.c_str(), 0, data_len);
        if (len < 0)
        {
            std::cout << "nad_msg::decode error!" << std::endl;
            std::cout << "ne_msg_t body::decode chan=" << header.peer_channel << std::endl;
        }
    }

};

}

#endif // __ne_msg_t_hpp__
