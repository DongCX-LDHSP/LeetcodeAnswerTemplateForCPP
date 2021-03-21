#ifndef PRINTPAIR
#define PRINTPAIR


#include <ostream>
#include "PrintVector.hpp"


using namespace std;


template <typename element1, typename element2>
ostream& operator<<(ostream& output, pair<element1, element2> data) {
    output << "(";
    output << data.first;
    output << ", ";
    output << data.second;
    output << ")";
}


#endif
