
#pragma once

#include <mutex>
#include <stdint.h>

namespace snow {
class RateLimiter {
public:
    explicit RateLimiter(int32_t rate, int32_t per) : 
         _rate(rate), _per(per), _allowance(0), _last_time(std::chrono::system_clock::now()) {};    
    virtual ~RateLimiter() {};

    virtual bool can_use();
private:
    int32_t _rate;
    int32_t _per;
    float _allowance;
    std::chrono::time_point<std::chrono::system_clock> _last_time;
    std::mutex _mutex;
};

}// end namespace snow;


