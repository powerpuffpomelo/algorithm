#include <iostream>
#include <cstring>
using namespace std;

// =============================== 开放寻址法 =============================== 
// 开一个比元素数大2-3倍的数组，如果位置冲突就找下一个坑位。优点：只需开一个数组
const int N = 2e5 + 3, null = 0x3f3f3f3f; // 2e5+3是事先找好的比2e5大的第一个质数，质数不容易冲突；null是一个比1e9大的数
int h[N];
int n;

// 返回x应该在的位置，结果可能是x，可能是null
int find(int x){
    int k = (x % N + N) % N; // 用%取模来哈希定位，由于c++中取模结果可能为负，所以+N再%去掉负号
    while(h[k] != null && h[k] != x){
        k++;
        if(k == N) k = 0;
    }
    return k;
}

int main(){
    memset(h, 0x3f, sizeof(h));   // memset按字节来memset，一个int有四个字节
    scanf("%d", &n);
    while(n--){
        char op[2];
        int x;
        scanf("%s%d", op, &x);  // 读入字符数组（而不是字符），避免读入奇怪符号如换行符
        if(*op == 'I'){
            h[find(x)] = x;
        }else{
            if(h[find(x)] == null) puts("No");   // puts函数自带换行
            else puts("Yes");
        }
    }
    return 0;
}

// =============================== 拉链法 =============================== 
// 每个哈希位置维护一个链表，把所有映射到该位置的元素串起来
/*
const int N = 1e5 + 3;
int h[N], val[N], ne[N], idx;
int n;

void insert(int x){
    int k = (x % N + N) % N;
    val[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

// 能否找到x
bool find(int x){
    int k = (x % N + N) % N;
    for(int i = h[k]; i != -1; i = ne[i]){
        if(val[i] == x) return true;
    }
    return false;
}

int main(){
    memset(h, -1, sizeof(h));
    scanf("%d", &n);
    while(n--){
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if(*op == 'I'){
            insert(x);
        }else{
            if(find(x)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}*/