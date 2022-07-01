#include <cmath>
#include <filesystem>
#include <fstream>
#include <sstream>

#include "Template.h"

#define max(a, b) a > b ? a : b

using namespace std::filesystem;

Template::Template() {
    init_();
}

Template::~Template() {
    deinit_();
}

void Template::init_() {
    switch_ = false;
    // run_();
}

void Template::deinit_() {
    // northing to do
}

void Template::run_() {
    // switch_ = true;

    

    // while (switch_) {
    //     // printf("test run\n");
    //     WAIT_TIME
    // }
}

void Template::create_dir_()
{
    path target_dir("./source");
    create_directory(target_dir);
    return;
}

void Template::create_screen_while_() {
    int max_len = 0;
    operator_list_ = {"添加用户", "删除用户", "排序"};
    for (const auto &op : operator_list_)
        max_len = max(max_len, op.length());

    int space = 10;
    int len_of_title = space *2 + max_len;
    std::stringstream buf;

    buf << "cout << \"" << std::string(len_of_title, '*') << "\"<< endl;" << std::endl;
    for (int i = 0; i < operator_list_.size(); ++ i) {
        buf << "cout << \"*" << std::setw(space) << i << ". " << operator_list_[i] << "\"<< endl;" << std::endl;
    }
    buf << "cout << \"" << std::string(len_of_title, '*') << "\" << endl;" << std::endl;
    std::fstream files;
    files.open("./source/screen.txt", std::ios::app);
    std::string buf_str;
    while (getline(buf, buf_str))
    {
        files << buf_str << std::endl;
    }
    buf.clear();
    buf << "while (true) {" << std::endl;
    buf << "char op; cin >> op;" << std::endl;
    buf << "switch(op) {" << std::endl;
    for (int i = 0; i < operator_list_.size(); ++ i)
    {
        buf << "case \'" << i << "\'" << ": {} break;" << std::endl; 
    }
    buf << "default:break;" << std::endl;
    buf << "} }" << std::endl;
    while (getline(buf, buf_str))
    {
        files << buf_str << std::endl;
    }
    files.close();
}

void Template::create_class_() {
    std::stringstream buf;
    std::fstream files;
    std::string buf_str;
    files.open("./source/class.txt", std::ios::app);
    buf << "class " << class_name_ << " {" << std::endl;
    buf << "public:" << std::endl;
    
    // 生成默认的function list 没有参数
    for (const auto& fun: function_member_) {
        buf << fun.first << " " << class_name_ << "::" << fun.second << "();" << std::endl;
    }

    for (auto &data: data_member_) {
        if (data.second) {
            buf << "void get_" << data.first << "();" << std::endl;
            buf << "void set_" << data.first << "();" << std::endl;
        }
    }

    buf << "private:" << std::endl;
    for (auto &data: data_member_) {
        buf << data.first << ";" << std::endl;
    }
    buf << "};";
    while (getline(buf, buf_str))
    {
        files << buf_str << std::endl;
    }
    files.close();
}
