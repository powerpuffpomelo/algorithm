// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
int n, k;
vector<int> vv;
lld ans;

void dfs(int id, int k_num, lld last, lld prod){
    last = last * 10 + vv[id];
    if(id == n - 1){
        if(k_num == k){
            prod *= last;
            ans = max(ans, prod);
        }
        return;
    }
    if(k_num < k){
        dfs(id + 1, k_num + 1, 0, prod * last);
    }
    dfs(id + 1, k_num, last, prod);
}

int main(){
    cin >> n >> k;
    string str;
    cin >> str;
    for(char c : str) vv.push_back(c - '0');
    dfs(0, 0, 0, 1);
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 更简洁一点的版本
#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
int n, k;
string str;

lld dfs(int id, int k_num, lld last, lld prod){
    if(id == n){
        if(k_num == k + 1) return prod;
        return -1;
    }
    last = last * 10 + str[id] - '0';
    return max(dfs(id + 1, k_num + 1, 0, prod * last), dfs(id + 1, k_num, last, prod));
}

int main(){
    cin >> n >> k >> str;
    cout << dfs(0, 0, 0, 1) << endl;
    return 0;
}