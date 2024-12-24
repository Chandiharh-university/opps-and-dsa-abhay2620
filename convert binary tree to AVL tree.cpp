#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int height(TreeNode* node) {
    return node ? max(height(node->left), height(node->right)) + 1 : 0;
}
int getBalanceFactor(TreeNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}
TreeNode* rotateRight(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}
TreeNode* rotateLeft(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}
TreeNode* balanceTree(TreeNode* node) {
    int balance = getBalanceFactor(node);
    if (balance > 1 && getBalanceFactor(node->left) >= 0)
        return rotateRight(node);
    if (balance > 1 && getBalanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && getBalanceFactor(node->right) <= 0)
        return rotateLeft(node);
    if (balance < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}
TreeNode* insert(TreeNode* root, int key) {
    if (!root)
        return new TreeNode(key);
    if (key < root->val)
        root->left = insert(root->left, key);
    else if (key > root->val)
        root->right = insert(root->right, key);
    else
        return root;
    return balanceTree(root);
}
void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}
int main() {
    TreeNode* root = nullptr;
    int values[] = {10, 20, 30, 40, 50, 25};
    for (int value : values)
        root = insert(root, value);
    cout << "Inorder traversal of the AVL tree: ";
    inorderTraversal(root);
    cout << endl;
    return 0;
}
