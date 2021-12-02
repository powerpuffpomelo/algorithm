// ###################################################### 版本1 ###################################################### //
// 先读入堆内所有元素，然后一起排序
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], cnt;  // h[N] 存放堆，cnt 是堆的元素数（不同于n）

void down(int i){  // 一路向下到该呆的位置
    int t = i;
    if(i * 2 <= cnt && h[i * 2] < h[t]) t = i * 2;
    if(i * 2 + 1 <= cnt && h[i * 2 + 1] < h[t]) t = i * 2 + 1;    // 与左右子节点比较
    if(i != t){
        swap(h[i], h[t]);
        down(t);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> h[i];
    cnt = n;
    for(int i = n / 2; i; i--) down(i);
    while(m--){
        cout << h[1] << ' ';
        h[1] = h[cnt--];
        down(1);
    }
    return 0;
}


// ###################################################### 版本2 ###################################################### //
// 一边读入一边排序
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, m, x;
int h[N];
int cnt;

void up(int i){
    if(i / 2 && h[i] < h[i / 2]){
        swap(h[i], h[i / 2]);
        up(i / 2);
    }
}

void down(int i){
    int t = i;
    if(i * 2 <= cnt && h[i * 2] < h[t]) t = i * 2;
    if(i * 2 + 1 <= cnt && h[i * 2 + 1] < h[t]) t = i * 2 + 1;
    if(t != i){
        swap(h[i], h[t]);
        down(t);
    }
}

int main(){
    cin >> n >> m;
    while(n--){
        cin >> h[++cnt];
        up(cnt);
    }
    while(m--){
        cout << h[1] << ' ';
        h[1] = h[cnt--];
        down(1);
    }
    return 0;
}