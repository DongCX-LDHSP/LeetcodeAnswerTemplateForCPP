#include <iostream>
#include <vector>
#include <exception>
// 引入测试类
#include "TestHelper/TestHelper.hpp"

using namespace std;

// TODO: 在这里重定义输入输出类型
typedef InputType Input;
typedef AnswerType Answer;
// 这个定义不建议修改，这里定义仅是为了主函数编写的便利性
typedef pair<Input, Answer> UseCase;

// TODO: 在这里定义你自己的结果比较方法，一般不需修改
bool compareFunction(Answer a, Answer b) {
    return a == b;
}

int main() {
    // TODO: 在这里设置输出流，默认为标准输出流
    ostream& output = cout;
    try {
        // 定义测试类
        TestHelper<Input, Answer, UseCase> test(output, compareFunction);

        // 添加测试用例
        {
            test.addUseCase(
                UseCase(
                    Input(), 
                    Answer()));
        }

        // 添加解决方案
        {
            test.addSolution(new Solution1());
        }

        // 执行解决方案
        test.runSolutions();

        output << endl << "程序正常退出！" << endl;
    }
    // 执行过程中产生异常
    catch (exception e) {
        output << e.what();
        output << endl << "####程序异常退出！####" << endl;
    }
    return 0;
}
