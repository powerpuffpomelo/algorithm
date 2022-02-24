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