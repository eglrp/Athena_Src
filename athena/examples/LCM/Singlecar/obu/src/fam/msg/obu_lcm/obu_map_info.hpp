/** THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
 * BY HAND!!
 *
 * Generated by lcm-gen
 **/

#include <lcm/lcm_coretypes.h>

#ifndef __obu_lcm_obu_map_info_hpp__
#define __obu_lcm_obu_map_info_hpp__

#include <vector>
#include "obu_lcm/nav_control_points.hpp"
#include "obu_lcm/map_line.hpp"
#include "obu_lcm/map_line.hpp"
#include "obu_lcm/map_line.hpp"

namespace obu_lcm
{

/// obu_planning每秒下发的路径规划指令
class obu_map_info
{
    public:
        obu_lcm::nav_control_points center_line;

        obu_lcm::map_line left_line;

        obu_lcm::map_line right_line;

        int32_t    num_of_lane_lines;

        std::vector< obu_lcm::map_line > lane_lines;

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
         * Returns "obu_map_info"
         */
        inline static const char* getTypeName();

        // LCM support functions. Users should not call these
        inline int _encodeNoHash(void *buf, int offset, int maxlen) const;
        inline int _getEncodedSizeNoHash() const;
        inline int _decodeNoHash(const void *buf, int offset, int maxlen);
        inline static uint64_t _computeHash(const __lcm_hash_ptr *p);
};

int obu_map_info::encode(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;
    int64_t hash = (int64_t)getHash();

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->_encodeNoHash(buf, offset + pos, maxlen - pos);
    if (tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int obu_map_info::decode(const void *buf, int offset, int maxlen)
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

int obu_map_info::getEncodedSize() const
{
    return 8 + _getEncodedSizeNoHash();
}

int64_t obu_map_info::getHash()
{
    static int64_t hash = _computeHash(NULL);
    return hash;
}

const char* obu_map_info::getTypeName()
{
    return "obu_map_info";
}

int obu_map_info::_encodeNoHash(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;

    tlen = this->center_line._encodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->left_line._encodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->right_line._encodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->num_of_lane_lines, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    for (int a0 = 0; a0 < this->num_of_lane_lines; a0++) {
        tlen = this->lane_lines[a0]._encodeNoHash(buf, offset + pos, maxlen - pos);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    return pos;
}

int obu_map_info::_decodeNoHash(const void *buf, int offset, int maxlen)
{
    int pos = 0, tlen;

    tlen = this->center_line._decodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->left_line._decodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->right_line._decodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->num_of_lane_lines, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    this->lane_lines.resize(this->num_of_lane_lines);
    for (int a0 = 0; a0 < this->num_of_lane_lines; a0++) {
        tlen = this->lane_lines[a0]._decodeNoHash(buf, offset + pos, maxlen - pos);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    return pos;
}

int obu_map_info::_getEncodedSizeNoHash() const
{
    int enc_size = 0;
    enc_size += this->center_line._getEncodedSizeNoHash();
    enc_size += this->left_line._getEncodedSizeNoHash();
    enc_size += this->right_line._getEncodedSizeNoHash();
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    for (int a0 = 0; a0 < this->num_of_lane_lines; a0++) {
        enc_size += this->lane_lines[a0]._getEncodedSizeNoHash();
    }
    return enc_size;
}

uint64_t obu_map_info::_computeHash(const __lcm_hash_ptr *p)
{
    const __lcm_hash_ptr *fp;
    for(fp = p; fp != NULL; fp = fp->parent)
        if(fp->v == obu_map_info::getHash)
            return 0;
    const __lcm_hash_ptr cp = { p, (void*)obu_map_info::getHash };

    uint64_t hash = 0xf8d81cba8b046ad8LL +
         obu_lcm::nav_control_points::_computeHash(&cp) +
         obu_lcm::map_line::_computeHash(&cp) +
         obu_lcm::map_line::_computeHash(&cp) +
         obu_lcm::map_line::_computeHash(&cp);

    return (hash<<1) + ((hash>>63)&1);
}

}

#endif
