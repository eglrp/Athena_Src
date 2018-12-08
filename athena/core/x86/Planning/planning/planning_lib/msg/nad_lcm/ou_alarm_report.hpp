/** THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
 * BY HAND!!
 *
 * Generated by lcm-gen
 **/

#include <lcm/lcm_coretypes.h>

#ifndef __nad_lcm_ou_alarm_report_hpp__
#define __nad_lcm_ou_alarm_report_hpp__

#include <string>

namespace nad_lcm
{

/// obu->vui：上报告警
class ou_alarm_report
{
    public:
        std::string alarm_proc;

        std::string alarm_time;

        int32_t    alarm_level;

        int32_t    alarm_type;

        int32_t    alarm_no;

        int32_t    alarm_show;

        std::string alarm;

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
         * Returns "ou_alarm_report"
         */
        inline static const char* getTypeName();

        // LCM support functions. Users should not call these
        inline int _encodeNoHash(void *buf, int offset, int maxlen) const;
        inline int _getEncodedSizeNoHash() const;
        inline int _decodeNoHash(const void *buf, int offset, int maxlen);
        inline static uint64_t _computeHash(const __lcm_hash_ptr *p);
};

int ou_alarm_report::encode(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;
    int64_t hash = (int64_t)getHash();

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->_encodeNoHash(buf, offset + pos, maxlen - pos);
    if (tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int ou_alarm_report::decode(const void *buf, int offset, int maxlen)
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

int ou_alarm_report::getEncodedSize() const
{
    return 8 + _getEncodedSizeNoHash();
}

int64_t ou_alarm_report::getHash()
{
    static int64_t hash = _computeHash(NULL);
    return hash;
}

const char* ou_alarm_report::getTypeName()
{
    return "ou_alarm_report";
}

int ou_alarm_report::_encodeNoHash(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;

    char* alarm_proc_cstr = (char*) this->alarm_proc.c_str();
    tlen = __string_encode_array(buf, offset + pos, maxlen - pos, &alarm_proc_cstr, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    char* alarm_time_cstr = (char*) this->alarm_time.c_str();
    tlen = __string_encode_array(buf, offset + pos, maxlen - pos, &alarm_time_cstr, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->alarm_level, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->alarm_type, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->alarm_no, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->alarm_show, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    char* alarm_cstr = (char*) this->alarm.c_str();
    tlen = __string_encode_array(buf, offset + pos, maxlen - pos, &alarm_cstr, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int ou_alarm_report::_decodeNoHash(const void *buf, int offset, int maxlen)
{
    int pos = 0, tlen;

    int32_t __alarm_proc_len__;
    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &__alarm_proc_len__, 1);
    if(tlen < 0) return tlen; else pos += tlen;
    if(__alarm_proc_len__ > maxlen - pos) return -1;
    this->alarm_proc.assign(((const char*)buf) + offset + pos, __alarm_proc_len__ - 1);
    pos += __alarm_proc_len__;

    int32_t __alarm_time_len__;
    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &__alarm_time_len__, 1);
    if(tlen < 0) return tlen; else pos += tlen;
    if(__alarm_time_len__ > maxlen - pos) return -1;
    this->alarm_time.assign(((const char*)buf) + offset + pos, __alarm_time_len__ - 1);
    pos += __alarm_time_len__;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->alarm_level, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->alarm_type, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->alarm_no, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->alarm_show, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    int32_t __alarm_len__;
    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &__alarm_len__, 1);
    if(tlen < 0) return tlen; else pos += tlen;
    if(__alarm_len__ > maxlen - pos) return -1;
    this->alarm.assign(((const char*)buf) + offset + pos, __alarm_len__ - 1);
    pos += __alarm_len__;

    return pos;
}

int ou_alarm_report::_getEncodedSizeNoHash() const
{
    int enc_size = 0;
    enc_size += this->alarm_proc.size() + 4 + 1;
    enc_size += this->alarm_time.size() + 4 + 1;
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += this->alarm.size() + 4 + 1;
    return enc_size;
}

uint64_t ou_alarm_report::_computeHash(const __lcm_hash_ptr *)
{
    uint64_t hash = 0x2e93ab087999abd0LL;
    return (hash<<1) + ((hash>>63)&1);
}

}

#endif
