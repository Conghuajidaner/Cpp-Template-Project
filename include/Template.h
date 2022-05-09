#ifndef _INCLUDE_TEMPLATE_
#define _INCLUDE_TEMPLATE_

#include <string>
#include <unordered_map>

#include "common.h"

using DATA_MEMBER = std::unprdered_map<string, string>;
using FUNCTION_MEMBER = std::unordered_map<string, string>;

class Template
{
private:
    /* data */
    DATA_MEMBER data_member_;
    FUNCTION_MEMBER function_member_;
public:
    Template(/* args */)=default;
    ~Template();

    void init_();
    void deinit_();
};

#endif // _INCLUDE_TEMPLATE_
