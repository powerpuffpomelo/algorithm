// 贪心证明：第一，这种方法一定能产生合理解，即所有区间都有点在内；第二，这种方法一定能产生最优解，因为选点的区间没有交集
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, ans, ed = -2e9;
struct Range{
    int l, r;
    bool operator< (const Range &w)const{  // 运算符重载，括号内const表示可以调用const，括号右const表示可以被const调用
        return r < w.r;
    }
}range[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }
    sort(range, range + n);
    for(int i = 0; i < n; i++){
        if(ed < range[i].l){
            ed = range[i].r;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}