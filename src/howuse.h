#pragma once

#include <iostream>

#include "rate_limiter.h"
#include "cgal_explorer.h"

namespace snow {
class HowUser {
public:
    HowUser(void);
    virtual ~HowUser(void);
    //basic
    void show_typedef();

    //proto
    void showUsageOfProto();

    //rapidjson
    void showUsageRapidjson();
    
    //io 
    void showReadAndWriteV1();
    void showReadAndWriteV2();
    void showReadAndWriteV3();

    //mem
    void showSize();

    //char & string
    //read arbitrarily length string
    void showReadString();
    void showStringLength();
    void stringOperation();

    //overloaded operator
    operator int() const {
        return example;
    }

    HowUser& operator=(const HowUser& t){
        example = t.example;
        return *this;
    }

    //HowUser operator+(const HowUser& t){
    //    HowUser new_user;
    //    new_user.example = example + t.example;
    //    return new_user;
    //}

    //asm
    void showAsm();

    //thread
    void thread_example();  

    //ratelimit
    void ratelimit();
    void rate_up();
    void statistic();        

    //chrono & time
    void get_ts();
    void get_duration();
    void get_date();

    //stream
    void show_ifstream();
    
    //cgal
    void cgal_test();

    //mutex
    
    //namespace
    void namespace_test();
public:
    static int version;
private:
    static void print_version(); 
    static void modify_version(int n);
    static void run(void* arg) {
        HowUser* how_user = (HowUser*)arg;
        how_user->rate_up();
    }
    static void run_static(void* arg) {
        HowUser* how_user = (HowUser*)arg;
        how_user->statistic();
    }
private:
    static std::chrono::time_point<std::chrono::system_clock> _last_time;
    //const int a; 
    int example;
    std::atomic<int32_t> _qps;
    std::atomic<int32_t> _request;
    int32_t _last_num;
    RateLimiter _rate_limiter;
    CgalExplorer _cgal;    
};

} //end namespace snow;
