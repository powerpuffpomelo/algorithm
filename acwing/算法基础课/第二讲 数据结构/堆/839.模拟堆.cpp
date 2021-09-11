#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, k, x;
int h[N], k2p[N], p2k[N];  // h[N]堆；k2p[N]第k个插入的对应堆中哪个位置；p2k[N]每个位置对应第几个插入
int cnt, id;  // cnt堆中元素数量；id插入序号
string op;

void h_swap(int a, int b){
    swap(h[a], h[b]);
    swap(p2k[a], p2k[b]);
    swap(k2p[p2k[a]], k2p[p2k[b]]);
}

void up(int i){
    while(i / 2 && h[i] < h[i / 2]){
        h_swap(i, i / 2);
        i /= 2;
    }
}

void down(int i){
    int t = i;
    if(i * 2 <= cnt && h[i * 2] < h[t]) t = i * 2;
    if(i * 2 + 1 <= cnt && h[i * 2 + 1] < h[t]) t = i * 2 + 1;
    if(i != t){
        h_swap(i, t);
        down(t);
    }
}

int main(){
    cin >> n;
    while(n--){
        cin >> op;
        if(op == "I"){
            cin >> x;
            h[++cnt] = x;
            k2p[++id] = cnt;
            p2k[cnt] = id;
            up(cnt);
        }else if(op == "PM"){
            cout << h[1] << endl;
        }else if(op == "DM"){
            h_swap(1, cnt--);
            down(1);
        }else if(op == "D"){
            cin >> k;
            int p = k2p[k];
            h_swap(p, cnt--);
            down(p);
            up(p);
        }else if(op == "C"){
            cin >> k >> x;
            int p = k2p[k];
            h[p] = x;
            down(p);
            up(p);
        }
    }
    return 0;
}