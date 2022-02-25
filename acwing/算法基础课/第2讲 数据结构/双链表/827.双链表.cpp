// 双链表
// 为了避免节点不存在等问题，直接先生成两个头尾节点，这个思路很好！

// ###################################################### 版本2 ###################################################### //
// 动态链表
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, k, x, id;
string op;
struct node{
    int val;
    node *left, *right;
    node(int x): val(x), left(nullptr), right(nullptr) {}
};
unordered_map<int, node*> hashh;

void insert_right(node* p, int x){
    node* q = p->right;
    node* cur = new node(x);
    hashh[++id] = cur;
    cur->left = p, p->right = cur;
    cur->right = q, q->left = cur;
}

void del(int k){
    node* t = hashh[k];
    node *ll = t->left, *rr = t->right;
    delete(t);
    ll->right = rr, rr->left = ll;
}

int main(){
    cin >> n;
    auto headl = new node(0), headr = new node(0);
    headl->right = headr, headr->left = headl;
    while(n--){
        cin >> op;
        if(op == "L"){
            cin >> x;
            insert_right(headl, x);
        }else if(op == "R"){
            cin >> x;
            insert_right(headr->left, x);
        }else if(op == "D"){
            cin >> k;
            del(k);
        }else if(op == "IL"){
            cin >> k >> x;
            insert_right(hashh[k]->left, x);
        }else{
            cin >> k >> x;
            insert_right(hashh[k], x);
        }
    }
    for(node* p = headl->right; p != headr; p = p->right){
        cout << p->val << ' ';
    }
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 静态链表
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int val[N], l[N], r[N], idx, m;

//初始化，0 1分别代表head tail
void init(){
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

//在idx为k的节点右边插入x
void add(int k, int x){
    val[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    r[k] = idx;
    l[r[idx]] = idx;
    idx++;
}

//删除idx为k的节点
void del(int k){
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main(){
    init(); //链表记得初始化
    ios::sync_with_stdio(false);
    cin >> m;
    while(m--){
        string op;
        int k, x;
        cin >> op;
        if(op == "L"){
            cin >> x;
            add(0, x);
        }else if(op == "R"){
            cin >> x;
            add(l[1], x);
        }else if(op == "D"){
            cin >> k;
            del(k + 1);  //索引偏移
        }else if(op == "IL"){
            cin >> k >> x;
            add(l[k + 1], x);
        }else if(op == "IR"){
            cin >> k >> x;
            add(k + 1, x);
        }
    }
    for(int i = r[0]; i != 1; i = r[i]) cout << val[i] << ' ';
    cout << endl;
    return 0;
}