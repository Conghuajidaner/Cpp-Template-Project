#include "Template.h"

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
    switch_ = true;
    while (switch_) {
        // printf("test run\n");
        WAIT_TIME
    }
}
