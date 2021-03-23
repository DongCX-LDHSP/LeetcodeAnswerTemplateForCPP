#ifndef PRINT
#define PRINT


#include <iostream>
#include <ostream>
#include <vector>


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
}


#endif
