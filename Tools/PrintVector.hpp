#ifndef PRINTVECTOR
#define PRINTVECTOR


#include <iostream>
#include <ostream>
#include <vector>


using namespace std;


template <typename Content> void PrintVector(ostream& output, vector<Content> param) {
    auto iter = param.begin();
    auto end = param.end();
    output << "{";
    while(iter < end - 1) {
        output << *iter;
        output << ", ";
        iter += 1;
    }
    output << *iter;
    output << "}";
}

/**
 * 为vector重载<<运算符
 */
template <typename Content> ostream &operator<<(ostream& output, const vector<Content> param) {
    PrintVector(output, param);
}


#endif
