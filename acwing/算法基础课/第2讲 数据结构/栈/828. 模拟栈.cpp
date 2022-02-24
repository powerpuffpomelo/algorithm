#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int st[N], top = -1;
int m;

void push(int x){
    st[++top] = x;
}

void pop(){
    top--;
}

bool empty(){
    if(top == -1) return true;
    else return false;
}

int query(){
    return st[top];
}

int main(){
    cin >> m;
    while(m--){
        string op;
        int x;
        cin >> op;
        if(op == "push"){
            cin >> x;
            push(x);
        }else if(op == "pop"){
            pop();
        }else if(op == "empty"){
            if(empty()) cout << "YES" << endl;
            else cout << "NO" << endl;
        }else if(op == "query"){
            cout << query() << endl;
        }
    }
    return 0;
}