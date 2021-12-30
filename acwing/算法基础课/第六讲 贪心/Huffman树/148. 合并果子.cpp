// ###################################################### 版本1 ###################################################### //
// 小根堆
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, ans;

int main(){
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> heap;
    while(n--){
        int x;
        cin >> x;
        heap.push(x);
    }
    while(heap.size() > 1){
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        ans += a + b;
        heap.push(a + b);
    }
    cout << ans << endl;
    return 0;
}

