#include "basic_use.h"

#include <stdio.h>

namespace snow {
void BasicUser::struct_usage() {
    std::string name("snow");
    int age_origin = 3;
    int32_t& age = age_origin;
    int32_t speed = 12;
    
    Robot robot{name, age, speed};
    robot.name = "sweety snow";
    robot.age = 4;
    robot.speed = 5;
    std::printf("name:%s, age:%d, speed:%d\n", name.c_str(), age, speed);

    struct_as_param(robot);
    std::printf("name:%s, age:%d, speed:%d\n", name.c_str(), age, speed);
}

void BasicUser::struct_as_param(Robot robot) {
    robot.name = "glstr snow";
    robot.age = 5;
    robot.speed = 6;
}

} //end namespace;
