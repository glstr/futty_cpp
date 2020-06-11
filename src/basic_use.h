#pragma once

#include <cstdint>
#include <string>

namespace snow {
class BasicUser {
public:
    BasicUser(void) {}
    virtual ~BasicUser() {}

    struct Robot {
        std::string& name;
        int32_t& age;
        int32_t& speed;
    };

    void struct_usage(); 

    void struct_as_param(Robot robot);
};

} //end namespace;

