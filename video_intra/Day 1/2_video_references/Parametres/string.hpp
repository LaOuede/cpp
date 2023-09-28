#ifndef STRING_H
# define STRING_H

#include <string>

void byPtr(std::string *str);
void byConstPtr(std::string const *str);
void byRef(std::string &str);
void byConstRef(std::string const &str);

#endif