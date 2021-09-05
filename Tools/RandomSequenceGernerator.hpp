#ifndef RANDOM_SEQUENCE_GERNERATOR
#define RANDOM_SEQUENCE_GERNERATOR

#include <limits>
#include <random>
#include <vector>

using namespace std;
using Range = pair<long long, long long>;

class RandomSequenceGernerator {
public:
    template <typename Integer>
    static vector<Integer> integerGernerator(size_t count, Range range = Range(numeric_limits<Integer>::min(), numeric_limits<Integer>::max())) {
        // 随机数生成准备
        random_device dev;
        mt19937 gen(dev());
        uniform_int_distribution<mt19937::result_type> dist(range.first, range.second);

        // 开始生成随机数
        vector<Integer> randomSequence(count);
        for (size_t i = 0; i < count; i++) {
            randomSequence[i] = dist(gen);
        }

        return randomSequence;
    }
};

#endif
