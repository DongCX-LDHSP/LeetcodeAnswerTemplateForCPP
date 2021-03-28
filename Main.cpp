#include <iostream>
#include "Tools/Print.hpp"
#include "Tools/ListNode.hpp"
#include "Tools/TreeNode.hpp"


// include here
#include "Solution.hpp"
#include <vector>


using namespace std;


int main() {
    // Input code here
    // redefine input and answer here
    typedef inputDataType input;
    typedef answerDataType answer;
    typedef pair<input, answer> UseCase;
    vector<UseCase> inputAndAnswer;

    // add use case here
    inputAndAnswer.push_back();

    {
        Solution solution;
        bool allPassed = true;
        cout << "Solution: " << endl;
        for (auto useCase : inputAndAnswer) {
            cout << useCase << ": ";

            // call solution function here;
            auto result = solution.function();
            
            cout << result;
            if (result != useCase.second) {
                allPassed = false;
                cout << "    Fail" << endl;
            }
            else {
                cout << "    Pass" << endl;
            }
        }
        cout << (allPassed == true ? "All passed!" : "Some case failed!") << endl;
    }

    cout << endl << "Process returned 0." << endl;
    return 0;
}
