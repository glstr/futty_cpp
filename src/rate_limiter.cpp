
#include <iostream>

#include "rate_limiter.h"

namespace snow {

bool RateLimiter::can_use() {
    std::lock_guard<std::mutex> guard(_mutex);    
    auto now = std::chrono::system_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now-_last_time); 
    _last_time = now;
    std::cout << "duration:" << duration.count() << std::endl;
    _allowance += duration.count() * ((float)_rate / _per);
    std::cout << "allowance:" << _allowance << std::endl;
    if (_allowance > _rate) {
        _allowance = _rate;
    }

    if (_allowance - 1 >= 0) {
        _allowance -= 1;
        return true;
    } else {
        return false;
    }
}

}// end namespace snow;
