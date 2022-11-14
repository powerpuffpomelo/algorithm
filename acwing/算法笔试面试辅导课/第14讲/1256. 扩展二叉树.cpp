// ###################################################### 版本2 ###################################################### //
// 无需构建树，直接在遍历过程中即可得到中序和后序
#include <bits/stdc++.h>
using namespace std;

string pre, in, post;

void dfs(int& k){
    char c = pre[k++];
    if(c == '.') return;
    dfs(k);
    in += c;
    dfs(k);
    post += c;
}

int main(){
    cin >> pre;
    int k = 0;
    dfs(k);
    cout << in << endl << post << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

string str;
int id;
struct node{
    char val;
    node *left, *right;
    node(char _val): val(_val), left(nullptr), right(nullptr) {}
};

node* dfs(string &str, int &u){
    if(str[u] == '.'){
        u++;
        return nullptr;
    }
    node* root = new node(str[u]);
    u++;
    root->left = dfs(str, u);
    root->right = dfs(str, u);
    return root;
}

void inorder(node* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->val;
    inorder(root->right);
}

void postorder(node* root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val;
}

int main(){
    cin >> str;
    node* root = dfs(str, id);
    inorder(root);
    cout << endl;
    postorder(root);
    return 0;
}