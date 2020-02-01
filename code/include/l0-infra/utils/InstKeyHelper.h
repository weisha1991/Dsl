#ifndef CODE_INCLUDE_L0_INFRA_UTILS_INSTKEYHELPER_H_
#define CODE_INCLUDE_L0_INFRA_UTILS_INSTKEYHELPER_H_

#include <string>
#include <sstream>

template<typename T>
std::string make_key(T t)
{
    std::ostringstream out;
    out << t;
    return out.str();
}

template<typename T, typename ... Arg>
std::string make_key(T key, Arg ...arg)
{
    std::ostringstream out;
    out << key << "." << make_key(arg ...);
    return out.str();
}


#endif /* CODE_INCLUDE_L0_INFRA_UTILS_INSTKEYHELPER_H_ */
