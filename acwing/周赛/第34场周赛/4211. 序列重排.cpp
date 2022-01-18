// ###################################################### 版本2 ###################################################### //
// 构造思路，双关键字排序
// 必要性：判断解满足什么性质；由于满足该性质的解唯一，所以充分
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long lld;
const int N = 110;
int n;
vector<lld> q[N];

int get(lld a, int b){  // a有多少个b因子
    int ret = 0;
    while(a % b == 0) ret++, a /= b;
    return ret;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        lld a;
        cin >> a;
        q[i] = {get(a, 2), -get(a, 3), a};  // 可以这样赋值vector
    }
    sort(q, q + n);
    for(int i = 0; i < n; i++) cout << q[i][2] << ' ';
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版，暴搜
#include <iostream>
#include <vector>
using namespace std;

typedef long long lld;
const int N = 110;
int n;
lld a[N];
vector<int> temp, ans;
int vis[N];
bool found = false;

void dfs(int i){
    if(temp.size() == n){
        found = true;
        ans = temp;
        return;
    }
    lld pre = a[i];
    for(int j = 0; j < n; j++){
        if(!vis[j] && (a[j] == pre * 2 || a[j] * 3 == pre)){
            temp.push_back(j);
            vis[j] = 1;
            dfs(j);
            temp.pop_back();
            vis[j] = 0;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        temp.push_back(i);
        vis[i] = 1;
        dfs(i);
        temp.pop_back();
        vis[i] = 0;
        if(found) break;
    }
    for(int i = 0; i < n; i++) cout << a[ans[i]] << ' ';
    return 0;
}