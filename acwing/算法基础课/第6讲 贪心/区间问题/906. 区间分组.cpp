// ###################################################### 版本1 ###################################################### //
// 贪心，小根堆
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
int n;
struct Range{
    int l, r;
    bool operator< (const Range &W)const{
        return l < W.l;
    }
}range[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d%d", &range[i].l, &range[i].r);
    sort(range, range + n);
    priority_queue<int, vector<int>, greater<int>> heap;  // 维护小根堆
    for(int i = 0; i < n; i++){
        auto rr = range[i];
        if(heap.empty() || heap.top() >= rr.l) heap.push(rr.r);
        else{
            heap.pop();
            heap.push(rr.r);
        }
    }
    printf("%d\n", heap.size());
    return 0;
}

// ###################################################### 版本2 ###################################################### //
/*
本题也可以理解为 求最大区间厚度。想象一根竖线，从前往后移动，看它最多能同时穿透几个区间。
思路：把所有开始时间和结束时间放在一起排序，从前往后遍历，
遇到开始时间就新开一个组，遇到结束时间就删一个组；组数的峰值就是最多同时存在的区间数，即为答案
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 10;
int n;
vector<pii> vec;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        vec.push_back({l, 0});  // 0表示左端点
        vec.push_back({r, 1});  // 1表示右端点
    }
    sort(vec.begin(), vec.end());
    int ans = 0, t = 0;    // t表示当前时刻需要的组数
    for(int i = 0; i < vec.size(); i++){
        if(vec[i].second == 0) t++; 
        else t--;
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}