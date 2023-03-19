// 90.91%
#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
int n, x;
int sum;
bool flag = false;

void dfs(int u, int s, int cnt){
    if(flag) return;
    if(u >= n) return;
    dfs(u + 1, s, cnt);
    s += nums[u], cnt += 1;
    double x = (double)s / cnt, y = ((double)sum - s) / (n - cnt);
    if(x == y && cnt != 0){
        flag = true;
        return;
    }
    dfs(u + 1, s, cnt);
}

int main(){
    while(cin >> x){
        nums.push_back(x);
        sum += x;
    }
    n = nums.size();
    dfs(0, 0, 0);
    if(flag) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}