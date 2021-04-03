#ifndef PRINT
#define PRINT


#include <iostream>
#include <ostream>
#include <vector>
#include <map>


using namespace std;


/**
 * 为vector重载'<<'运算符
 */
template <typename Content>
ostream& operator<<(ostream& output, const vector<Content> param) {
    output << "{";
    if (param.size() > 0) {
        auto iter = param.begin();
        auto end = param.end();
        while(iter < end - 1) {
            output << *iter;
            output << ", ";
            iter += 1;
        }
        output << *iter;
    }
    output << "}";
    return output;
}


/**
 * 为pair重载'<<'运算符
 */
template <typename element1, typename element2>
ostream& operator<<(ostream& output, pair<element1, element2> data) {
    output << "(";
    output << data.first;
    output << ", ";
    output << data.second;
    output << ")";
    return output;
}


/**
 * 为map重载'<<'运算符
 */
template <typename key, typename value>
ostream& operator<<(ostream& output, map<key, value> data) {
    output << "{";
    auto size = data.size();
    for (auto temp : data) {
        size -= 1;
        if (size > 0) {
            output << temp.first << ": " << temp.second << ", ";
        }
        else {
            output << temp.first << ": " << temp.second;
        }
    }
    output << "}";
    return output;
}


#endif
