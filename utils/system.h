#include <string>

#ifndef SYSTEM_H
#define SYSTEM_H

std::string exec(const char* cmd);
std::string get_env_var( std::string const & key );
std::string get_env_var( const char* key );

#endif /* SYSTEM_H */
