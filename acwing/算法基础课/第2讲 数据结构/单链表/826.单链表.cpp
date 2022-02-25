// ###################################################### 版本2 ###################################################### //
// 结构体指针
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int m, x, k, id;
string op;
struct node{
    int val;
    node* next;
    node(int x): val(x), next(nullptr) {}
}*root;
unordered_map<int, node*> hashh;

void insert(node* p, int x){
    node* t = new node(x);
    hashh[++id] = t;
    t->next = p->next;
    p->next = t;
}

void del(int k){
    if(k == 0) root = root->next;
    else{
        node* t = hashh[k];
        node* dd = t->next;
        t->next = dd->next;
        delete(dd);
    }
}

int main(){
    cin >> m;
    root = new node(0);
    while(m--){
        cin >> op;
        if(op == "H"){
            cin >> x;
            insert(root, x);
        }else if(op == "D"){
            cin >> k;
            del(k);
        }else{
            cin >> k >> x;
            insert(hashh[k], x);
        }
    }
    for(node* i = root->next; i; i = i->next){
        cout << i->val << ' ';
    }
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 静态链表
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int m;
int head, val[N], ne[N], idx;  // 静态链表

void init(){
    head = -1;
    idx = 0;
}

void add_to_head(int x){
    val[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void add(int k, int x){
    val[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

void del(int k){
    ne[k] = ne[ne[k]];
}

int main(){
    cin >> m;
    init();
    while(m--){
        char op;
        int k, x;
        cin >> op;
        if(op == 'H'){
            cin >> x;
            add_to_head(x);
        }else if(op == 'I'){
            cin >> k >> x;
            add(k - 1, x);
        }else{
            cin >> k;
            if(!k) head = ne[head];
            else del(k - 1);
        }
    }
    for(int i = head; i != -1; i = ne[i]){
        cout << val[i] << ' ';
    }
    cout << endl;
    return 0;
}
