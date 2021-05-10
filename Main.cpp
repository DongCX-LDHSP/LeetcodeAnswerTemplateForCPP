#include <iostream>
#include "Tools/Print.hpp"
#include "Tools/ListNode.hpp"
#include "Tools/TreeNode.hpp"
// your include here
#include "Solution/Solution.hpp"
#include "Solution/Solution1.hpp"
#include <vector>

using namespace std;

// redefine Input and Answer here
typedef InputType Input;
typedef AnswerType Answer;
typedef pair<Input, Answer> UseCase;

// 添加用例
void inline addUseCase(vector<UseCase>& useCases) {
    // 如果使用了二叉树，则可以使用setNullNodeValue设置合适的NULLNODE值
    // setNullNodeValue(-2);
    useCases.push_back(UseCase());
}

// 添加解法
void inline addSolution(vector<Solution*>& solutions) {
    solutions.push_back(new Solution1());
}

/**
 * 比较结果的策略，不能使用'=='运算符判断是否相等的结果，
 * 可以在这里编写相应的判等策略
 * @param expected: Answer, 期待结果
 * @param result: Answer, 计算结果
 * @return bool, true：结果相同，false：结果不同
 */
bool inline compareAnswer(Answer expected, Answer result) {
    return expected == result;
}

// 执行解法
void inline runSolution(vector<Solution*>& solutions, vector<UseCase>& useCases) {
    // 用于控制输出
    int i = 0;
    int solutionNum = solutions.size();
    // 用于计算通过和未通过的用例个数
    int useCaseNum = useCases.size();
    int wrongNum = 0;
    for (auto solution : solutions) {
        i += 1;
        wrongNum = 0;
        cout << "Solution" << i << ": " << endl;

        for (auto useCase : useCases) {
            // call solution function here;
            auto result = solution->function(useCase.first);
            // 检验结果
            if (compareAnswer(useCase.second, result) == false) {
                wrongNum += 1;
                cout << "#";
            }
            cout << useCase << ": " << result << endl;
        }
        // 输出统计信息
        cout << "Total: " << useCaseNum << ", "
             << "Pass: " << useCaseNum - wrongNum << ", "
             << "Fail: " << wrongNum << endl;

        // 控制换行的输出
        if (i < solutionNum) {
            cout << endl;
        }
    }
}

// 释放解法使用的动态内存
void inline freeSolution(vector<Solution*>& solutions) {
    for (auto solution : solutions) {
        delete solution;
    }
}

int main() {
    // 用例列表
    vector<UseCase> useCases;
    addUseCase(useCases);
    // 解法列表
    vector<Solution*> solutions;
    addSolution(solutions);
    // 执行解法
    runSolution(solutions, useCases);
    // 释放解法申请的动态内存
    freeSolution(solutions);

    cout << endl << "Process returned 0." << endl;
    return 0;
}
