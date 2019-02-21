#pragma once

#include <atomic>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

namespace snow {
class Task {
public:
    explicit Task(int a, int b) : 
        _a(a),
        _b(b) {}
    virtual ~Task(void) {}
    int operator ()() {
        int res = _a + _b;
        std::cout << res << std::endl;
        return res;
    }

private:
    int _a;
    int _b;
};

class Worker {
public:
    explicit Worker(int queue_size) : 
        _queue_size(queue_size),
        _is_done(false) {}
    virtual ~Worker(void) {}
   
    void start(); 
    void stop();

    void post(Task&& task);

private:
    void thread_func();

private:
    int _queue_size;
    std::atomic<bool> _is_done; 
    std::mutex _mutex;
    std::queue<Task> _task_queue;
    std::thread _thread;
};

class WorkersGroup {
public:
    WorkersGroup(int workers_num) : 
        _workers(workers_num) {}
    virtual ~WorkersGroup(void) {} 

    void start();
    void stop();
    void post(Task&& task);

private:
    std::vector<std::unique_ptr<Worker>> _workers; 
};

} //end namespace snow


