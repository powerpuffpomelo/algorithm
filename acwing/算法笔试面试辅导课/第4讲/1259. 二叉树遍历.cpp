// ###################################################### 版本1 ###################################################### //
// 我的版本
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

struct node{
    char val;
    node *left, *right;
    node(char _val): val(_val), left(nullptr), right(nullptr) {}
};
queue<node*> q;
int bidx, vis[30];
unordered_map<char, int> pos;
string a, b;

void rebuild(){
    while(q.size()){
        auto t = q.front();
        q.pop();
        int p = pos[t -> val];
        if(p - 1 >= 0 && !vis[p - 1]){
            node *ll = new node(b[bidx++]);
            vis[pos[ll -> val]] = 1;
            q.push(ll);
            t -> left = ll;
        }
        if(p + 1 < a.size() && !vis[p + 1]){
            node *rr = new node(b[bidx++]);
            vis[pos[rr -> val]] = 1;
            q.push(rr);
            t -> right = rr;
        }
    }
}

void preorder(node *nn){
    if(nn == nullptr) return;
    cout << nn -> val;
    preorder(nn -> left);
    preorder(nn -> right);
}

int main(){
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++) pos[a[i]] = i;
    node* root = new node(b[bidx++]);
    vis[pos[b[0]]] = 1;
    q.push(root);
    rebuild();
    preorder(root);
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 
#include <bits/stdc++.h>
using namespace std;

string inorder, layerorder;
struct node{
    char val;
    node *left, *right;
    node(char _val): val(_val), left(nullptr), right(nullptr) {}
};
unordered_map<char, int> pos;
node* q[30];
int st[30];

void preorder(node* p){
    if(!p) return;
    cout << p -> val;
    preorder(p -> left);
    preorder(p -> right);
}

int main(){
    cin >> inorder >> layerorder;
    for(int i = 0; i < inorder.size(); i++) pos[inorder[i]] = i;
    q[0] = new node(layerorder[0]);
    for(int i = 0, j = 1; j < layerorder.size();){
        for(int end = j; i < end; i++){
            int p = pos[q[i] -> val];
            st[p] = 1;
            if(p && !st[p - 1]){
                q[i] -> left = q[j] = new node(layerorder[j]);
                j++;
            }
            if(p + 1 < layerorder.size() && !st[p + 1]){
                q[i] -> right = q[j] = new node(layerorder[j]);
                j++;
            }
        }
    }
    preorder(q[0]);
    return 0;
}