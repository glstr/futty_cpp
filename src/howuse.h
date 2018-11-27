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

    //asm
    void showAsm();
};
