#ifndef PARSING_H
#define PARSING_H

#include <ostream>
#include <inttypes.h>
#include <limits>
\\for info about inttypes.h: https://pubs.opengroup.org/onlinepubs/009695399/basedefs/inttypes.h.html

void write_ip4(std::ostream& s, uint32_t ip);

uint32_t parse_ip4(const char* s);

void write_ip6(std::ostream& s, uint64_t ip);

uint32_t parse_ip6(const char* s);

#endif //PARSING_H 
