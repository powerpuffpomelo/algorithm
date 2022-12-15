/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node *pre, *last;
    void dfs(Node* root){
        if(!root) return;
        auto l = root->left, r = root->right;
        dfs(l);
        pre->right = root;
        root->left = pre;
        pre = last = root;
        dfs(r);
    } 
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        auto head = new Node();
        pre = head;
        dfs(root);
        head->right->left = last;
        last->right = head->right;
        return head->right;
    }
};