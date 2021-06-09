#ifndef TREENODE
#define TREENODE

/**
 * 模块使用说明
 * 1. 按需修改结点中存储的数据类型
 * 2. 按需求设置代表空结点的值，实现树从先序序列的自动构造
 */
#include <stack>
#include <vector>
#include <iostream>

// TODO：在这里修改结点中存储的数据类型
typedef int TreeValueType;

// 代表空结点的值
TreeValueType NULLNODE = -1;

struct TreeNode {
    TreeValueType val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(NULLNODE), left(nullptr), right(nullptr) {}
    TreeNode(TreeValueType x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(TreeValueType x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 修改空结点的值
void SetNullNodeValue(TreeValueType newNullNodeValue) {
    NULLNODE = newNullNodeValue;
}

// 获取空结点的值
TreeValueType GetNullNodeValue() {
    return NULLNODE;
}

/**
 * 构建树时某一个结点的状态
 * left 表示期待一个左子结点
 * right 表示期待一个右子结点
 * end 表示构建完毕
 */
enum Status {left, right, end};
// 第一个维度使用指针常量，避免误修改
typedef std::pair<TreeNode* const, Status> NodeStatus;

// 基于value值构建树的结点
TreeNode* ConstructNode(TreeValueType value) {
    return value == NULLNODE ? nullptr : new TreeNode(value);
}

// 基于根节点的状态，链接它与子节点，同时更新父节点的状态
void LinkNode(NodeStatus& parent, TreeNode* child) {
    switch (parent.second) {
    case Status::left:
        parent.first->left = child;
        parent.second = Status::right;
        break;
    case Status::right:
        parent.first->right = child;
        parent.second = Status::end;
        break;
    default:
        std::cout << "错误：这个父节点：" << parent.first << "（指针）不再需要子节点" << std::endl;
        break;
    }
}

// 基于树的先序遍历构造树
TreeNode* ConstructTree(const std::vector<TreeValueType>& values) {
    // 临时保存构建出的树节点
    std::vector<TreeNode*> nodePointers;
    nodePointers.reserve(values.size());

    // 构建所有的结点
    for (const auto& value : values) {
        nodePointers.push_back(ConstructNode(value));
    }

    // 构建树时，临时存储根节点的指针
    std::stack<NodeStatus> tempRoot;

    // 构建出树的结构
    // 第一步，取出一个结点
    for (const auto& nodePointer : nodePointers) {
        // 第二步，链接树的结构
        // 栈非空，链接树的结构，栈为空时，直接考察是否需要入栈
        if (tempRoot.empty() == false) {
            LinkNode(tempRoot.top(), nodePointer);
            // 第三步，检查栈顶结点的子节点是否已经全找到，若全找到则出栈
            if (tempRoot.top().second == Status::end) {
                tempRoot.pop();
            }
        }
        // 第四步，检查新增节点是否需要入栈
        if (nodePointer != nullptr) {
            tempRoot.push(NodeStatus(nodePointer, Status::left));
        }
    }

    // 返回根节点
    return nodePointers.front();
}

// 以先序遍历的形式打印树
void PrintTreeInFirstOrder(std::ostream& output, TreeNode* root) {
    if (root != nullptr) {
        output << root->val << ", ";
        if (root->left != nullptr || root->right != nullptr) {
            PrintTreeInFirstOrder(output, root->left);
            PrintTreeInFirstOrder(output, root->right);
        }
    }
    else {
        output << "NULL, ";
    }
}

// 释放动态生成的树节点占用的空间
void FreeTree(TreeNode* root) {
    if (root != nullptr) {
        FreeTree(root->left);
        FreeTree(root->right);
        delete root;
    }
}

#endif
