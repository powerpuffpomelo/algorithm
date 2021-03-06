// ###################################################### 版本2 ###################################################### //
// 
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, k;
int a[N];

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    n = unique(a + 1, a + n + 1) - a - 1;   // unique函数返回数组去重后尾地址
    for(int i = 1; i <= k; i++){
        if(i <= n) cout << a[i] - a[i - 1] << endl;
        else cout << 0 << endl;
    }
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, k;
set<int> se;

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int ai;
        cin >> ai;
        se.insert(ai);
    }
    int pre = 0;
    
    while(se.size() && k){
        int top = *se.begin();
        cout << top - pre << endl;
        pre = top;
        se.erase(top);
        k--;
    }
    while(k--) cout << 0 << endl;
    return 0;
}