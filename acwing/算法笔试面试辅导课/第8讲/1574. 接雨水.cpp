// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, h[N], lmax[N], rmax[N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n - 1; i++){
        lmax[i + 1] = max(lmax[i], h[i]);
    }
    for(int i = n; i >= 2; i--){
        rmax[i - 1] = max(rmax[i], h[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += max(min(lmax[i], rmax[i]) - h[i], 0);
    }
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 单调栈1
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, h[N];
stack<int> stk;

int cal(){
    int ret = 0;
    for(int i = 1; i <= n; i++){
        while(stk.size() && h[i] >= h[stk.top()]){
            int t = stk.top();
            stk.pop();
            if(stk.empty()) break;
            int left = stk.top();
            int hh = min(h[i], h[left]) - h[t];
            ret += hh * (i - left - 1);
        }
        stk.push(i);
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    cout << cal() << endl;
    return 0;
}

// ###################################################### 版本3 ###################################################### //
// 单调栈2
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, h[N];
stack<int> stk;

int cal(){
    int ret = 0;
    for(int i = 1; i <= n; i++){
        int last = 0;
        while(stk.size() && h[i] >= h[stk.top()]){
            int t = stk.top();
            stk.pop();
            ret += (h[t] - last) * (i - t - 1);
            last = h[t];
        }
        if(stk.size()){
            ret += (h[i] - last) * (i - stk.top() - 1);
        }
        stk.push(i);
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    cout << cal() << endl;
    return 0;
}