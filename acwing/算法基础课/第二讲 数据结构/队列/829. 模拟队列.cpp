#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e6 + 10;
int m;
int q[N];
int front = -1, rear = -1;

int main(){
    cin >> m;
    while(m--){
        string op;
        int x;
        cin >> op;
        if(op == "push"){
            cin >> x;
            q[++rear] = x;
        }else if(op == "pop"){
            front++;
        }else if(op == "empty"){
            cout << (front == rear ? "YES":"NO") << endl;  // 此处要加括号，不然编译错误
        }else if(op == "query"){
            cout << q[front + 1] << endl;
        }
    }
    return 0;
}