#include "parsing.h"
#include <string.h>

void write_ip4(std::ostream& s, uint32_t ip)
{
    uint8_t* add = (uint8_t*) & ip;
    for (size_t i = 0; i < 4; ++i) {
        if (i != 0) s << ".";
        s << (int) add[3 - i];
    }
}

uint32_t parse_ip4(const char* s)
{
    if (s == nullptr)
        return std::numeric_limits<uint32_t>::max();
    uint32_t res;
    uint8_t* add = (uint8_t*) & res;
    size_t j = 0;
    size_t n = 0;
    auto len = strlen(s);
    for (size_t i = 0; i < len; ++i) {
        if (s[i] == '.' || i == len - 1) {
            if (i == len - 1)
                ++i;
            auto v = std::atoi(&(s[j]));
            add[3 - n] = v;
            j = i + 1;
            ++n;
            if(n > 3) break;
        }
    }
    return res;
}

void write_ip6(std::ostream& s, uint64_t ip)
{
    uint8_t* add = (uint8_t*) & ip;
    for (size_t i = 0; i < 8; ++i) {
        if (i != 0) s << ":";
        s << (int) add[3 - i];
    }
}

uint32_t parse_ip6(const char* s)
{
    if (s == nullptr)
        return std::numeric_limits<uint32_t>::max();
    uint32_t res;
    uint8_t* add = (uint8_t*) & res;
    size_t j = 0;
    size_t n = 0;
    auto len = strlen(s);
    for (size_t i = 0; i < len; ++i) {
        if (s[i] == ':' || i == len - 1) {
            if (i == len - 1)
                ++i;
            char *end;
            auto v = std::strtol(&(s[j]), &end, 16);
            add[7 - n] = v;
            j = i + 1;
            ++n;
            if(n > 7) break;
        }
    }
    return res;
}
