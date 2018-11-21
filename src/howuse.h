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
};
