//creating the stopwatch header file

#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <ctime>
#include <sstream>
#include <chrono>


class stopwatch {
    using clock = std::chrono::high_resolution_clock;
    bool _running = false;
    
    clock::time_point _start;
    clock::time_point _stop;

public:
    auto started() const { return _start; }
    auto stopped() const { return _stop; }
    bool running() const { return _running; }
    stopwatch(bool r = true) : _running(r), _start(clock::now()), _stop(clock::now()){}
    void start() {
        if(!_running)
        {
            _running = true;
            _start = clock::now() - (_stop - _start);
        }
    }
    void stop() {
        if(_running)
        {
            _stop = clock::now();
            _running = false;
        }
    }
    
    double duration() const { return std::chrono::duration_cast<std::chrono::duration<double>>(_stop-_start).count(); }

    std::ostream &operator<<(std::ostream &os){
        os << duration() << " s";
        return os;
    }
};

#endif // STOPWATCH_H
