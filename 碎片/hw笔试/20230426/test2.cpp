// 通过率未知
#include <bits/stdc++.h>
using namespace std;

int l, r, n;
struct node{
    int val;
    node *next, *pre;
    node(int _x): val(_x), next(nullptr), pre(nullptr) {}
};
unordered_map<int, node*> mp;
unordered_map<int, int> state;  // 1空闲 -1繁忙

int main(){
    node *dummy = new node(0), *rear = new node(0);
    cin >> l >> r >> n;
    node* cur = dummy;
    for(int i = l; i <= r; i++){
        auto t = new node(i);
        cur->next = t;
        t->pre = cur;
        cur = cur->next;
        mp[i] = t;
        state[i] = 1;
    }
    cur->next = rear;
    rear->pre = cur;
    
    int size = r - l + 1;
    while(n--){
        int x, y;
        cin >> x >> y;
        if(x == 1){
            if(y <= size){
                cur = dummy->next;
                while(y--){
                    state[cur->val] = -1;
                    cur = cur->next;
                }
                dummy->next = cur;
                cur->pre = dummy;
            }
        }else if(x == 2){
            auto t = mp[y];
            if(state[t->val] == -1 || t->val < l || t->val > r) continue;
            state[t->val] = -1;
            t->pre->next = t->next;
            t->next->pre = t->pre;
        }else{
            auto t = mp[y];
            if(state[t->val] == 1 || t->val < l || t->val > r) continue;
            state[t->val] = 1;
            rear->pre->next = t;
            t->pre = rear->pre;
            t->next = rear;
            rear->pre = t;
        }
    }
    cout << dummy->next->val << endl;
    return 0;
}