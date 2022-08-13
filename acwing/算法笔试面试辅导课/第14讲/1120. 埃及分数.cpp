// ###################################################### 版本1 ###################################################### //
// dfs，迭代加深，推数学公式求上下界
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL a, b;
vector<int> ans, temp;

LL gcd(LL a, LL b){
    return b ? gcd(b, a % b) : a;
}

void dfs(LL x, LL y, int last, int t){
    if(!t){
        if(!x && (!ans.size() || ans.back() > temp.back())) ans = temp;
        return;
    }
    LL d = gcd(x, y);
    x /= d, y /= d;
    int down = max(last, (int)((y + x - 1) / x));  // 下界：从last开始搜，且要 y/x 上取整
    int up = y * t / x;                            // 上界
    for(int i = down; i <= up; i++){
        temp.push_back(i);
        dfs(i * x - y, y * i, i + 1, t - 1);
        temp.pop_back();
    }
}

int main(){
    cin >> a >> b;
    int t = 1;
    while(true){    // 迭代加深，从小到大枚举dfs的深度上限
        dfs(a, b, 1, t);
        if(ans.size()) break;
        t++;
    }
    for(int x : ans) cout << x << ' ';
    return 0;
}