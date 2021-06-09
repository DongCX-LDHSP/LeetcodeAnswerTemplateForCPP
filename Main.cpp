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
// bool compareFunction(Answer a, Answer b);
// TODO: 这这里定义释放测试用例占用的动态内存的方法
// void freeUseCaseFunction(UseCase& useCase);

int main() {
    // TODO: 在这里设置输出流，默认为标准输出流
    ostream& output = cout;
    // 设置bool变量的输出为字符串形式
    output << boolalpha;
    try {
        // 定义测试类
        TestHelper<Input, Answer, UseCase> testHelper(output);

        // 调用设置一些测试类的属性的方法，比如设置自定义的比较方法
        {
            // 设置比较计算结果与期待结果的方法
            // testHelper.setCompareFunction(compareFunction);
            // 设置释放用例占用的动态内存的方法
            // testHelper.setFreeUseCaseFunction(freeUseCaseFunction);
            // 设置空树结点的值
            // testHelper.setTreeNullNodeValue(nullNodeValue);
        }

        // 添加测试用例
        {
            testHelper.addUseCase(
                UseCase(
                    Input(), 
                    Answer()));
        }

        // 添加解决方案
        {
            testHelper.addSolution(new Solution1());
        }

        // 执行解决方案
        testHelper.runSolutions();

        output << endl << "程序正常退出！" << endl;
    }
    catch (out_of_range& e) {
        output << e.what() << endl;
        output << endl << "####程序异常退出！####" << endl;
    }
    // 执行过程中产生异常
    catch (logic_error& e) {
        output << e.what() << endl;
        output << endl << "####程序异常退出！####" << endl;
    }
    catch(exception& e) {
        output << e.what() << endl;
        output << endl << "####程序异常退出！####" << endl;
    }
    return 0;
}
