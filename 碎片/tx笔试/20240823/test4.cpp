// 100%
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
int n;
vector<string> leaf;
vector<int> value;

struct node{
    int v;
    node *left, *right;
    node(){
        v = 0;
    }
}*root;

void bfs(node* root, vector<int>& value){
    queue<node*> q;
    q.push(root);
    while(q.size()){
        auto t = q.front();
        q.pop();
        if(!t->left && !t->right){
            t->v = value.back();
            value.pop_back();
        }
        if(t->right) q.push(t->right);
        if(t->left) q.push(t->left);
    }
}

void dfs(node* root){
    if(root->v) return;
    if(root->left){
        dfs(root->left);
        root->v += root->left->v;
    }
    if(root->right){
        dfs(root->right);
        root->v += root->right->v;
    }
}

void print(node* root){  // 打印结果自用
    if(!root){
        cout << "# ";
        return;
    } 
    cout << root->v << ' ';
    print(root->left);
    print(root->right);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        string str;
        cin >> str;
        leaf.push_back(str);
    }
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        value.push_back(x);
    }
    root = new node();
    // 建树
    for(auto s : leaf){
        node* p = root;
        for(auto c : s){
            if(c == '0'){
                if(!p->left) p->left = new node();
                p = p->left;
            }else{
                if(!p->right) p->right = new node();
                p = p->right;
            }
        }
    }
    sort(value.begin(), value.end());
    // 获得叶子节点权值
    bfs(root, value);
    // 获得其它节点权值
    dfs(root);
    // 打印结果
    print(root);
    return 0;
}