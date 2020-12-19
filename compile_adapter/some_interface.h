#ifndef SOME_INTERFACE_H
#define SOME_INTERFACE_H

#include <map>
#include <string>
#include <vector>
class some_interface
{
public:
    virtual std::map<std::string,std::string> some_method(std::vector<std::string> list ) = 0;
};
#endif /* SOME_INTERFACE_H */
