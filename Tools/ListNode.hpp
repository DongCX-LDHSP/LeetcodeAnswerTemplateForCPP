#ifndef LISTNODE
#define LISTNODE


#include <ostream>
#include <vector>


using namespace std;

// TODO：你可以在这里修改链表保存的数据类型
using ListNodeValType = int;

struct ListNode {
    ListNodeValType val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(ListNodeValType x) : val(x), next(nullptr) {}
    ListNode(ListNodeValType x, ListNode *next) : val(x), next(next) {}
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
 * @param list: vector<ListNodeValType>, 构造链表的数据源
 * @return ListNode*, 构造的链表的首地址
 */
ListNode* GenerateAListByVector(vector<ListNodeValType> list) {
    // 若列表为空，则直接返回nullptr
    if (list.size() == 0) {
        return nullptr;
    }
    // 若列表只有一个元素，则直接构建一个元素返回
    else if (list.size() == 1) {
        return new ListNode(list.back());
    }
    // 列表中多于1个元素，迭代构建链表
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

/**
 * @param a: ListNode*, 被比较的链表a
 * @param b: ListNode*, 被比较的链表b
 */
bool ListEqualByValue(ListNode* a, ListNode* b) {
    while (a != nullptr && b != nullptr) {
        if (a->val != b->val) {
            return false;
        }
        a = a->next;
        b = b->next;
    }
    // 结束循环时，a, b两个链表应该同时到达链表结尾
    return a == nullptr && b == nullptr;
}


#endif
