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