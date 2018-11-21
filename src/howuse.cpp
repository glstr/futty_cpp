#include "howuse.h"
//#include "address.pb.h"
//

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
using namespace rapidjson;

HowUser::HowUser(void) {
}

HowUser::~HowUser(void) {
}

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
