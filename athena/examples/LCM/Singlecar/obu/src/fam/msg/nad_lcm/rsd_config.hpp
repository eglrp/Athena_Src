/** THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
 * BY HAND!!
 *
 * Generated by lcm-gen
 **/

#include <lcm/lcm_coretypes.h>

#ifndef __nad_lcm_rsd_config_hpp__
#define __nad_lcm_rsd_config_hpp__

#include <string>

namespace nad_lcm
{

/// rsd配置
class rsd_config
{
    public:
        std::string rsd_name;

        std::string rsd_type;

        std::string rsd_ip;

    public:
        /**
         * Encode a message into binary form.
         *
         * @param buf The output buffer.
         * @param offset Encoding starts at thie byte offset into @p buf.
         * @param maxlen Maximum number of bytes to write.  This should generally be
         *  equal to getEncodedSize().
         * @return The number of bytes encoded, or <0 on error.
         */
        inline int encode(void *buf, int offset, int maxlen) const;

        /**
         * Check how many bytes are required to encode this message.
         */
        inline int getEncodedSize() const;

        /**
         * Decode a message from binary form into this instance.
         *
         * @param buf The buffer containing the encoded message.
         * @param offset The byte offset into @p buf where the encoded message starts.
         * @param maxlen The maximum number of bytes to reqad while decoding.
         * @return The number of bytes decoded, or <0 if an error occured.
         */
        inline int decode(const void *buf, int offset, int maxlen);

        /**
         * Retrieve the 64-bit fingerprint identifying the structure of the message.
         * Note that the fingerprint is the same for all instances of the same
         * message type, and is a fingerprint on the message type definition, not on
         * the message contents.
         */
        inline static int64_t getHash();

        /**
         * Returns "rsd_config"
         */
        inline static const char* getTypeName();

        // LCM support functions. Users should not call these
        inline int _encodeNoHash(void *buf, int offset, int maxlen) const;
        inline int _getEncodedSizeNoHash() const;
        inline int _decodeNoHash(const void *buf, int offset, int maxlen);
        inline static uint64_t _computeHash(const __lcm_hash_ptr *p);
};

int rsd_config::encode(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;
    int64_t hash = (int64_t)getHash();

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->_encodeNoHash(buf, offset + pos, maxlen - pos);
    if (tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int rsd_config::decode(const void *buf, int offset, int maxlen)
{
    int pos = 0, thislen;

    int64_t msg_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &msg_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (msg_hash != getHash()) return -1;

    thislen = this->_decodeNoHash(buf, offset + pos, maxlen - pos);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int rsd_config::getEncodedSize() const
{
    return 8 + _getEncodedSizeNoHash();
}

int64_t rsd_config::getHash()
{
    static int64_t hash = _computeHash(NULL);
    return hash;
}

const char* rsd_config::getTypeName()
{
    return "rsd_config";
}

int rsd_config::_encodeNoHash(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;

    char* rsd_name_cstr = (char*) this->rsd_name.c_str();
    tlen = __string_encode_array(buf, offset + pos, maxlen - pos, &rsd_name_cstr, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    char* rsd_type_cstr = (char*) this->rsd_type.c_str();
    tlen = __string_encode_array(buf, offset + pos, maxlen - pos, &rsd_type_cstr, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    char* rsd_ip_cstr = (char*) this->rsd_ip.c_str();
    tlen = __string_encode_array(buf, offset + pos, maxlen - pos, &rsd_ip_cstr, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int rsd_config::_decodeNoHash(const void *buf, int offset, int maxlen)
{
    int pos = 0, tlen;

    int32_t __rsd_name_len__;
    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &__rsd_name_len__, 1);
    if(tlen < 0) return tlen; else pos += tlen;
    if(__rsd_name_len__ > maxlen - pos) return -1;
    this->rsd_name.assign(((const char*)buf) + offset + pos, __rsd_name_len__ - 1);
    pos += __rsd_name_len__;

    int32_t __rsd_type_len__;
    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &__rsd_type_len__, 1);
    if(tlen < 0) return tlen; else pos += tlen;
    if(__rsd_type_len__ > maxlen - pos) return -1;
    this->rsd_type.assign(((const char*)buf) + offset + pos, __rsd_type_len__ - 1);
    pos += __rsd_type_len__;

    int32_t __rsd_ip_len__;
    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &__rsd_ip_len__, 1);
    if(tlen < 0) return tlen; else pos += tlen;
    if(__rsd_ip_len__ > maxlen - pos) return -1;
    this->rsd_ip.assign(((const char*)buf) + offset + pos, __rsd_ip_len__ - 1);
    pos += __rsd_ip_len__;

    return pos;
}

int rsd_config::_getEncodedSizeNoHash() const
{
    int enc_size = 0;
    enc_size += this->rsd_name.size() + 4 + 1;
    enc_size += this->rsd_type.size() + 4 + 1;
    enc_size += this->rsd_ip.size() + 4 + 1;
    return enc_size;
}

uint64_t rsd_config::_computeHash(const __lcm_hash_ptr *)
{
    uint64_t hash = 0x819301215cd32be9LL;
    return (hash<<1) + ((hash>>63)&1);
}

}

#endif
