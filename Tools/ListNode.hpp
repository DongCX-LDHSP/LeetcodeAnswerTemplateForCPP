#ifndef LISTNODE
#define LISTNODE


#include <ostream>
#include <vector>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * 向output指定的输出流逐个输出链表中的值，以','分隔
 * @param output: ostream, 输出流
 * @param head: ListNode*, 待输出的链表首地址
 */
void PrintListNode(ostream& output, ListNode* head) {
    while(head->next != nullptr) {
        output << head->val;
        output << ", ";
        head = head->next;
    }
    output << head->val;
}

/**
 * 基于list中的数据，按顺序构造一个链表
 * @param list: vector<int>, 构造链表的数据源
 * @return ListNode*, 构造的链表的首地址
 */
ListNode* GenerateAListByVector(vector<int> list) {
    ListNode* followElement = new ListNode(list.back());
    list.pop_back();
    ListNode* tempElement;
    while(!list.empty()) {
        tempElement = new ListNode(list.back(), followElement);
        followElement = tempElement;
        list.pop_back();
    }
    return tempElement;
}

/**
 * 释放链表使用的动态空间
 * @param head: ListNode*, 待释放空间的链表首地址
 */
void FreeList(ListNode* head) {
    ListNode* temp = nullptr;
    while(head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


#endif
