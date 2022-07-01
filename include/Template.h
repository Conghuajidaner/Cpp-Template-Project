#ifndef _INCLUDE_TEMPLATE_
#define _INCLUDE_TEMPLATE_

#include <chrono>
#include <string>
#include <vector>
#include <thread>
#include <unordered_map>

#include "common.h"

// first: date name 类型需要自己补充
// second: 是否生成get set function
using DATA_MEMBER = std::unordered_map<std::string, bool>;

// 函数的返回值  函数名
using FUNCTION_MEMBER = std::unordered_map<std::string, std::string>;

// 
using OPERATOR_LIST = std::vector<std::string>;

#define WAIT_TIME std::this_thread::sleep_for(std::chrono::milliseconds(100));

class Template
{
private:
    /* data */
    DATA_MEMBER data_member_;
    FUNCTION_MEMBER function_member_;
    OPERATOR_LIST operator_list_;
    bool switch_;
    std::string class_name_;
public:
    Template(/* args */);
    ~Template();

    void create_dir_();
    void create_screen_while_();
    void create_class_();

private:
    void init_();
    void deinit_();
    void run_();
};

#endif // _INCLUDE_TEMPLATE_
