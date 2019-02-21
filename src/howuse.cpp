#include "howuse.h"
//#include "address.pb.h"
//
//
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "utils.h"
#include "namespace_use.h"

using namespace std;
using namespace rapidjson;
namespace snow {
using Clock = std::chrono::high_resolution_clock;
using Ms = std::chrono::milliseconds;
using Sec = std::chrono::seconds;

template<class Duration>
using TimePoint = std::chrono::time_point<Clock, Duration>;

int HowUser::version = 1;
std::chrono::time_point<std::chrono::system_clock> HowUser::_last_time =
    std::chrono::system_clock::now();

HowUser::HowUser(void) : 
    example(100),
    _rate_limiter(500, 1000){
}

HowUser::~HowUser(void) {
}

/*
 * basic
 */
void HowUser::show_typedef() {
    t_add_more();
}

void HowUser::show_type() {
    int a;
    decltype(a) b = 2.0;
    cout << b << endl;
}

void HowUser::show_for() {
    vector<int> nums {1, 2, 4, 5};        
    for(const auto& v: nums) {
        cout << v << endl;
    }
}

/*
 * container
 */
void HowUser::show_pair() {
    pair<int, float> p(21, 2.3);    
    cout << p.first << ", " << p.second;
}

void HowUser::show_queue() {
    queue<int> d;
    d.push(2);
    d.push(3);
    while(!d.empty()) {
        cout << d.front() << endl;
        d.pop();
    }
}

void HowUser::show_map() {
    //init      
    map<string, int> students {
        {"Jim", 1},
        {"Tom", 2},
        {"Lucy", 3},
    };  

    //get value 
    cout << students["Jim"] << endl;
    
    //iter
    map<string, int>::iterator it;
    it = students.begin();
    for (; it != students.end(); ++it) {
        cout << it->first << it->second << endl;
    }

    //erase   
    --it;
    students.erase(it);    
    print_map<map<string, int>>(students);

    //swap
    cout << "swap" << endl;
    map<string, int> new_students {
        {"Lily", 2},
        {"LiLei", 3},
        {"HanMei", 4},
    };

    new_students.swap(students);
    print_map(students);
    print_map(new_students);
}

template<typename Map>
void HowUser::print_map(Map& m) {
    for(auto& p: m) {
        cout << p.first << p.second << endl;
    }    
}

/*
 * proto
 */
void HowUser::showUsageOfProto() {
    //::futty::Person person;
    //person.set_name("July");
    //person.set_id(12);

    //::futty::Person_PhoneNumber* phone = person.add_phones();
    //phone->set_number("123");        

    //string data;
    ////person.SerializeToString(&data);
    //cout << data << endl;
}

void HowUser::showUsageRapidjson() {
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;
    d.Parse(json);
    // 2. 利用 DOM 作出修改。
    Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);
    // 3. 把 DOM 转换（stringify）成 JSON。
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;
    return;
}

void HowUser::showReadAndWriteV1() {
    FILE* fp = fopen("test.txt", "w");
    fprintf(fp, "%s %d", "hello world", 2);
    fclose(fp);

    char s[100];
    int a;
    FILE *fp_in = fopen("test.txt", "r");
    fscanf(fp_in, "%s, %d", s, &a);
    printf("%s %d", s, a);
    fclose(fp_in);
}

void HowUser::showReadAndWriteV2() {
    FILE* fp = fopen("test.txt", "r");
    char s[100];
    int a;
    fgets(s, 100, fp);
    printf("%s", s);
    fclose(fp);
}

void HowUser::showReadAndWriteV3() {
    //range image format
    //file_path
    //pose1 pose2 pose3 pose4 pose5 pose6
    
    //write
    const char*  file_path = "1.bls";
    double pose[6] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7};
    FILE* fp = fopen("test.conf", "w");
    if (fp == NULL) {
        printf("[errmsg:open file error]");
        return;            
    }
    fprintf(fp, "%s\n", file_path); 
    int size = sizeof(pose);
    int double_size = sizeof(double);        
    printf("pose:%d double:%d\n", size, double_size);
    for (int i = 0; i < 6; i++) {
        if (i == 5){
            fprintf(fp, "%lf\n", pose[i]);
        } else {
            fprintf(fp, "%lf ", pose[i]);
        }
    }
    fclose(fp);

    //read
    char file[100];
    double pose_in[6];
    FILE *fp_in = fopen("test.conf", "r");
    fgets(file, 100, fp_in);
    //erase '\n' in file_path
    std::string str(file);
    std::size_t len = str.length();
    str.erase(len-1, 1);
    //get pose
    for (int i = 0; i < 6; i++) {
        if (i == 5) {
            fscanf(fp_in, "%lf ", pose + i);
        } else {
            fscanf(fp_in, "%lf\n", pose + i);
        }
    }
    printf("file_path:%s, pose:%lf\n", str.c_str(), pose[0]);
}

void HowUser::showSize() {
    //cpp data type
    //num char bool ptr
    bool* a = new bool[12];
    printf("bool:%lu, array:%lu\n", sizeof(bool), sizeof(a));
    delete []a;
    
    double* b = new double[13];
    printf("double:%lu, array:%lu\n", sizeof(double), sizeof(b));
    delete []b;

    char* c = new char[100];
    printf("char:%lu, array:%lu\n", sizeof(char), sizeof(c));
    delete []c;

    char d[100];
    printf("array:%lu\n", sizeof(d));
}

void HowUser::showReadString() {
    std::string result;
    FILE* fp = fopen("temp.txt", "r");
    while (!feof(fp)) {
        char temp[100] = {};        
        if (fgets(temp, 100, fp) != NULL) {
            result.append(temp);
        } else{
            break;
        }
    }
    fclose(fp);
    std::size_t size = result.length();
    char* data = new char[size];
    memcpy(data, result.data(), result.length());
    printf("%s", data);
    delete []data;
}

void HowUser::showStringLength() {
    std::string str("hello world");
    printf("string len:%lu\n", str.length());
    printf("char length:%lu\n", strlen(str.c_str()));
    //char* temp = new char(11);
    char temp[12] = {};
    memcpy(temp, str.data(), 12);
    printf("temp length:%lu\n", strlen(temp));
    printf("%c\n", temp[10]);
    printf("%s\n", temp);
    char test[2] = {'h', 'w'};
    printf("%s\n", test);
}

void HowUser::stringOperation() {
    std::string str("hello world");
    std::size_t pos = str.find_first_not_of("h");
    if (pos != std::string::npos) {
        cout << str[pos] << endl;        
    }
}

void HowUser::showAsm() {
    //__asm__("movl %esp, orig_stack_pointer");    
}

void HowUser::thread_example() {
    int n = 10;
    std::thread t1(modify_version, n);    
    std::thread t2(print_version);
    t1.join();
    t2.join();
}

void HowUser::modify_version(int n) {
    for (int i = 0; i <= n; ++i) {
        version += i;
        this_thread::sleep_for(chrono::seconds(5));
    }
}

void HowUser::print_version() {
    while (true) {
        cout << version << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void HowUser::ratelimit() {
    std::thread t2(run_static, this);
    std::thread t1(run, this);
    std::thread t3(run, this);
    std::vector<std::thread*> t_v;
    for (int i = 0; i < 1000; ++i) {
        std::thread* t = new thread(run, this);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        t_v.push_back(t);    
    }
    t2.join();
}

void HowUser::statistic() {
    while(true) {
        auto current = _request.load();
        auto rate = current - _last_num;
        _last_num = current;
        auto now = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(now-_last_time); 
        _last_time = now;
        cout << "rate:" << rate << endl;
        cout << "statics:" << duration.count() << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void HowUser::rate_up() {
    while(true) {
        if (_rate_limiter.can_use()) {
            _request++;
        } else {
            cout << "hit max" << endl;
        } 
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

//chrono
void HowUser::get_ts() {
    auto t = std::chrono::system_clock::now().time_since_epoch();
    auto ts_s = std::chrono::duration_cast<std::chrono::seconds>(t).count();
    auto ts_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t).count();
    auto ts_us = std::chrono::duration_cast<std::chrono::microseconds>(t).count();
    cout << "ts:" << ts_s << endl;
    cout << "ts_ms:" << ts_ms << endl;
    cout << "ts_us:" << ts_us << endl;
}

void HowUser::get_duration() {
    auto start = std::chrono::system_clock::now();    
    std::this_thread::sleep_for(std::chrono::seconds(2));
    auto end = std::chrono::system_clock::now();
    auto duration = 
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    cout << "duration:" << duration << endl;
}

void HowUser::get_date() {
    std::time_t result = std::time(nullptr);
    std::cout << std::asctime(std::localtime(&result))
              << result << " seconds since the Epoch\n";
}

//stream
void HowUser::show_ifstream() {
    const char* file_name = "/Users/pengbaojiang/pengbaojiang/code/cpp_src/futty_cpp/build/src/test.off";
    std::ifstream stream(file_name);

    char b[255];
    stream.getline(b, 100);
    stream.getline(b, 200);
    cout << b << endl;
}

//cgal
void HowUser::cgal_test() {
    _cgal.simple_test();
}

//mutex
//workersgroup
void HowUser::show_wg() {
    std::vector<Task> tasks;
    for (int i = 0; i < 10; ++i) {
        Task task(std::rand(), std::rand());
        tasks.push_back(task); 
    }

    WorkersGroup wg(2);
    wg.start();
    while(true) {
        Task task(std::rand(), std::rand());
        wg.post(std::move(task));
        //std::chrono::milliseconds ms{10};
        //std::this_thread::sleep_for(ms);
        cout << "post" << endl;
    }
}


} //end namespace snow;
