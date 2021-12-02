#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int m;
int head, val[N], ne[N], idx;  // 静态链表

void init(){
    head = -1;
    idx = 1;
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
            add(k, x);
        }else{
            cin >> k;
            if(!k) head = ne[head];
            else del(k);
        }
    }
    for(int i = head; i != -1; i = ne[i]){
        cout << val[i] << ' ';
    }
    cout << endl;
    return 0;
}