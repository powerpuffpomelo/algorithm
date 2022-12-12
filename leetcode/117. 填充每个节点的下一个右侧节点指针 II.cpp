// ###################################################### 版本1 ###################################################### //
// 我的初版
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<Node*> q, newq;
    Node* connect(Node* root) {
        if(!root) return root;
        q.push_back(root);
        while(q.size()){
            for(int i = 0; i < q.size(); i++){
                if(i != q.size() - 1) q[i]->next = q[i + 1];
                if(q[i]->left) newq.push_back(q[i]->left);
                if(q[i]->right) newq.push_back(q[i]->right);
            }
            q = newq;
            newq = vector<Node*>();
        }
        return root;
    }
};