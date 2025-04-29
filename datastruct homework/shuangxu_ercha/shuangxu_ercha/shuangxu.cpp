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

    char rootVal = postOrder[postOrder.length() - 1]; // ����������е����һ���ڵ�Ϊ���ڵ�
    TreeNode* root = new TreeNode(rootVal);

    int rootIndex = inOrder.find(rootVal); // ����������������ҵ����ڵ������

    string leftInOrder = inOrder.substr(0, rootIndex);
    string leftPostOrder = postOrder.substr(0, rootIndex);

    string rightInOrder = inOrder.substr(rootIndex + 1);
    string rightPostOrder = postOrder.substr(rootIndex, postOrder.length() - rootIndex - 1);

    root->left = buildTreeFromInPost(leftInOrder, leftPostOrder); // �ݹ鹹��������
    root->right = buildTreeFromInPost(rightInOrder, rightPostOrder); // �ݹ鹹��������

    return root;
}

void printInOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    printInOrder(root->left); // �ȴ�ӡ������
    cout << root->val << " "; // ��ӡ��ǰ�ڵ�
    printInOrder(root->right); // ����ӡ������
}

int main() {
    string inOrder = "BDCAFEG";
    string postOrder = "DCBFGEA";

    TreeNode* root = buildTreeFromInPost(inOrder, postOrder);

    cout << "����������Ϊ: ";
    printInOrder(root);

    return 0;
}