#pragma once

class HowUser {
public:
    HowUser(void);
    virtual ~HowUser(void);
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

    HowUser operator+(const HowUser& t){
        HowUser new_user;
        new_user.example = example + t.example;
        return new_user;
    }

    //asm
    void showAsm();
public:
    static int version;
private:
    //const int a; 
    int example;
};
