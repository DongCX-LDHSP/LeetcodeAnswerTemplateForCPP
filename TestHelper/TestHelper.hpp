#ifndef TESTHELPER_H
#define TESTHELPER_H

// 内部库
#include <iostream>

// 输出的辅助代码
#include "../Tools/Print.hpp"
// 链表的辅助代码
#include "../Tools/ListNode.hpp"
// 二叉树的辅助代码
#include "../Tools/TreeNode.hpp"
// 计时器的功能
#include "../Tools/Timer.hpp"
// 解决方案的代码
#include "../Solution/Solution.hpp"
// 引入实际的解决方案代码
#include "../Solution/Solution1.hpp"

using namespace std;

template <typename Input, typename Answer, typename UseCase=pair<Input, Answer>>
class TestHelper {
public:
    /**
     * 测试类的构造函数
     * @param output: ostream&, 修改输出流
     * @param freeUseCase: void (*)(UseCase&), 外部实现的释放用例占用的内存的方法
     * @param compareFunction: bool (*)(Answer, Answer), 比较执行结果的方法
     */
    TestHelper(ostream &output, bool (*compareFunction)(Answer, Answer) = nullptr, void (*freeUseCase)(UseCase& useCase) = nullptr)
        : output(output) {
        init(compareFunction, freeUseCase);
    }

    // 析构函数，释放测试用例和解决方案占用的动态内存
    ~TestHelper() {
        // 释放测试用例占用的动态内存
        freeUseCases();
        // 释放解决方案占用的动态内存
        freeSolutions();
    }

    // 设置比较用例结果的函数指针
    void setCompareFunction(bool (*compareFunctionImplement)(Answer expexted, Answer result)) {
        this->compareFunction = compareFunctionImplement;
    }

    // 设置释放用例的函数指针
    void setFreeUseCaseFunction(void (*freeUseCaseImplement)(UseCase& useCase)) {
        this->freeUseCase = freeUseCaseImplement;
    }

    // 设置代表树结点空结点的值
    void setTreeNullNodeValue(TreeValueType nullNodeValue) {
        SetNullNodeValue(nullNodeValue);
    }

    // 添加用例
    void addUseCase(UseCase useCase) {
        useCases.push_back(useCase);
        useCaseNum += 1;
    }

    // 添加解决方案
    void addSolution(Solution* solution) {
        solutions.push_back(solution);
        solutionNum += 1;
    }

    // 执行所有的解决方案
    void runSolutions() {
        // 遍历所有的解决方案并执行
        for (size_t index = 0; index < solutionNum; index++) {
            output << "解决方案" << index + 1 << ": " << endl;
            // 执行index指向的解决方案
            runSolutionAt(index);
            // 控制换行的输出
            if (index < solutionNum - 1) {
                output << endl;
            }
        }
    }

    // 执行指定的解决方案，为了适应测试某一个解决方案的要求
    void runSolutionAt(size_t index) {
        // 如果超出了索引范围则执行else分支抛出异常
        if (index < solutionNum) {
            // 执行失败的用例数
            size_t wrongNum = 0;
            // 重置计时器
            timer.resetTimer();
            // 考察所有的用例
            for (auto& useCase : useCases) {
                // 开始计时
                timer.startTiming();
                // 执行解决方案
                auto result = solutions[index]->function(useCase.first);
                // 结束计时
                timer.endTiming();
                if (compareAnswer(useCase.second, result) == false) {
                    wrongNum += 1;
                    output << "#";
                }
                // 输出用例的执行结果以及执行用时
                output << useCase << ": " << result << ", "
                    << "用时: " << timer.getSingleMicroSeconds() << "ms" << endl;
            }
            // 输出针对所有测试用例的统计信息
            output << "用例数: " << useCaseNum << endl
                << "通过数: " << useCaseNum - wrongNum << endl
                << "失败数: " << wrongNum << endl
                << "总时间: " << timer.getTotalMicroSeconds() << "ms" << endl;
        }
        else {
            cerr << endl << "(TestHelper::runSolutionAt)索引超出范围：请检查代码逻辑！" << endl;
            throw out_of_range("(TestHelper::runSolutionAt)索引超出范围：请检查代码逻辑！");
        }
    }

// 私有方法
private:
    // 初始化测试类
    void init(bool (*compareFunction)(Answer, Answer), void (*freeUseCase)(UseCase& useCase)) {
        // 设置执行结果的比较方法
        this->compareFunction = compareFunction;
        // 设置释放用例占用的动态内存的方法
        this->freeUseCase = freeUseCase;
        // 初始化用例数量
        useCaseNum = useCases.size();
        // 初始化解决方案数量
        solutionNum = solutions.size();
    }

    /**
     * 比较结果的策略，不能使用'=='运算符判断是否相等的结果，
     * 可以在这里编写相应的判等策略
     * @param expected: Answer, 期待结果
     * @param result: Answer, 计算结果
     * @return bool, true：结果相同，false：结果不同
     */
    bool compareAnswer(Answer expected, Answer result) {
        if (compareFunction == nullptr) {
            return expected == result;
        }
        return compareFunction(expected, result);
    }

    // 释放动态生成的解决方案占用的动态内存
    void freeSolutions() {
        for (auto solution : solutions) {
            delete solution;
        }
    }

    // 释放用例占用的动态内存
    void freeUseCases() {
        if (freeUseCase == nullptr) {
            return;
        }
        for (auto& useCase : useCases) {
            // 在这里调用释放用例的方法
            freeUseCase(useCase);
        }
    }

private:
    // 所有的用例
    vector<UseCase> useCases;
    // 所有的解决方案
    vector<Solution*> solutions;
    // 指向的输出流
    ostream& output;
    // 测试用例的数量
    size_t useCaseNum;
    // 解决方案的数量
    size_t solutionNum;

    // 计时器
    Timer timer;

    // 指向执行结果比较方法的指针
    bool (*compareFunction)(Answer expected, Answer result);
    // 释放用例占用的动态内存的函数指针
    void (*freeUseCase)(UseCase& useCase);
};

#endif
