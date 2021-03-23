#ifndef PRINTVECTOR
#define PRINTVECTOR


#include <iostream>
#include <ostream>
#include <vector>
#include "PrintPair.hpp"


using namespace std;


/**
 * 为vector重载<<运算符
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


#endif
