#include<iostream>
using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeFromInPost(string inOrder, string postOrder) {
    if (inOrder.empty() || postOrder.empty() || inOrder.length() != postOrder.length()) {
        return NULL;
    }

    char rootVal = postOrder[postOrder.length() - 1]; // 后序遍历序列的最后一个节点为根节点
    TreeNode* root = new TreeNode(rootVal);

    int rootIndex = inOrder.find(rootVal); // 在中序遍历序列中找到根节点的索引

    string leftInOrder = inOrder.substr(0, rootIndex);
    string leftPostOrder = postOrder.substr(0, rootIndex);

    string rightInOrder = inOrder.substr(rootIndex + 1);
    string rightPostOrder = postOrder.substr(rootIndex, postOrder.length() - rootIndex - 1);

    root->left = buildTreeFromInPost(leftInOrder, leftPostOrder); // 递归构造左子树
    root->right = buildTreeFromInPost(rightInOrder, rightPostOrder); // 递归构造右子树

    return root;
}

void printInOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    printInOrder(root->left); // 先打印左子树
    cout << root->val << " "; // 打印当前节点
    printInOrder(root->right); // 最后打印右子树
}

int main() {
    string inOrder = "BDCAFEG";
    string postOrder = "DCBFGEA";

    TreeNode* root = buildTreeFromInPost(inOrder, postOrder);

    cout << "中序遍历结果为: ";
    printInOrder(root);

    return 0;
}