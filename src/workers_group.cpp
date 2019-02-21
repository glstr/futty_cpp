#include "workers_group.h"

#include <cstdlib>
#include <mutex>

namespace snow {
void Worker::start() {
    _thread = std::thread(&Worker::thread_func, this);
}

void Worker::thread_func() {
    while (!_is_done.load()) {
        std::lock_guard<std::mutex> lock(_mutex);
        if (!_task_queue.empty()) {
            auto task = _task_queue.front();            
            task();
            _task_queue.pop();
            std::chrono::milliseconds ms{10};
            std::this_thread::sleep_for(ms);
        } else {
            std::cout << "no work" << std::endl;
            std::chrono::milliseconds ms{300};
            std::this_thread::sleep_for(ms);
        }
    }
}

void Worker::stop() {
    _is_done.store(true);
}

void Worker::post(Task&& task) {
    std::lock_guard<std::mutex> lock(_mutex);
    if (_task_queue.size() < _queue_size) {
        _task_queue.push(task);
    }
}

void WorkersGroup::start() {
    for(auto& worker : _workers) {
        worker.reset(new Worker(100));
    }

    for(size_t i = 0; i < _workers.size(); ++i) {
        _workers[i]->start();
    }
}

void WorkersGroup::stop() {
    for(auto& work_ptr : _workers) {
        work_ptr->stop();
    }   
}

void WorkersGroup::post(Task&& task) {
    int index = std::rand() % _workers.size();        
    _workers[index]->post(std::move(task));
}

} // end namespace snow




