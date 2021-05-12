#ifndef TIMER
#define TIMER

#include <iostream>
#include <chrono>
#include <string>
#include <stdexcept>

using namespace std;
using namespace std::chrono;

class Timer {
public:
    Timer() {
        // 初始化整个计时过程中总的时间长度
        totalTime = 0;
        // 将是否正在计时的标志置为没有计时
        timing = false;
    }

    // 重置计时器
    void resetTimer() {
        // 如果正在计时，则抛出逻辑错误
        if (timing == true) {
            cerr << endl << "(Timer::resetTimer)逻辑错误：计时器正在计时，无法重置计时器！" << endl;
            throw logic_error("(Timer::resetTimer)逻辑错误：计时器正在计时，无法重置计时器！");
        }
        else {
            totalTime = 0;
            timing = false;
            startTime = high_resolution_clock::now();
            endTime = startTime;
        }
    }

    // 开始计时
    void startTiming() {
        if (timing == false) {
            // 将是否正在计时的标志置为正在计时
            timing = true;
            startTime = high_resolution_clock::now();
        }
        // 如果正在计时，则抛出逻辑错误
        else {
            cerr << endl << "(Timer::startTiming)逻辑错误：计时器正在计时！" << endl;
            throw logic_error("(Timer::startTiming)逻辑错误：计时器正在计时！");
        }
    }

    // 停止计时
    void endTiming() {
        if (timing == true) {
            endTime = high_resolution_clock::now();
            // 将是否正在计时的标志置为没有计时
            timing = false;
            // 累计总的计时时间
            totalTime += duration_cast<microseconds>(endTime - startTime).count();
        }
        // 如果没有正在进行中的计时，则抛出逻辑错误
        else {
            cerr << endl << "(Timer::endTiming)逻辑错误：计时器没有计时！" << endl;
            throw logic_error("(Timer::endTiming)逻辑错误：计时器没有计时！");
        }
    }

    // 获取最后一次计时的时间长度
    double getSingleMicroSeconds() {
        // 如果正在计时，则抛出逻辑错误
        if (timing == true) {
            cerr << endl << "(Timer::getSingleMicroSeconds)逻辑错误：正在计时，无法获取最后一次计时的时间长度！" << endl;
            throw logic_error("(Timer::getSingleMicroSeconds)逻辑错误：正在计时，无法获取最后一次计时的时间长度！");
        }
        // 没有正在进行中的计时，返回最后一次计时的时间长度
        return duration_cast<microseconds>(endTime - startTime).count() * 0.001;
    }

    // 获取所有计时过程的总的时间长度
    double getTotalMicroSeconds() {
        // 如果正在计时，则抛出逻辑错误
        if (timing == true) {
            cerr << endl << "(Timer::getTotalMicroSeconds)逻辑错误：正在计时，无法获取总的时间长度！" << endl;
            throw logic_error("(Timer::getTotalMicroSeconds)逻辑错误：正在计时，无法获取总的时间长度！");
        }
        return totalTime * 0.001;
    }

private:
    // 开始时间
    time_point<high_resolution_clock> startTime;
    // 结束时间
    time_point<high_resolution_clock> endTime;
    // 累计时间
    int64_t totalTime;
    // 是否正在计时的标志
    bool timing;
};

#endif
