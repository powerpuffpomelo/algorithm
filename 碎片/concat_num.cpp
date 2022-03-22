// 一个集合里有很多数，给定数s，需要用集合中的数拼接出不超过s的最大的数，集合中的数可以无限次取用
// 不知道对不对
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, n_len;
vector<int> arr;
string n_s, ans;
vector<string> vv[N];// 每种长度维护一个集合

bool cmp(string a, string b){
    return a > b;
}

int main(){
    n = 98;
    arr = {93, 9, 7};
    n_s = to_string(n);
    n_len = n_s.size();
    for(int x : arr){
        string s = to_string(x);
        vv[s.size()].push_back(s);
        sort(vv[s.size()].begin(), vv[s.size()].end(), cmp);
    }
    vector<string> dp(n_len + 1);  // dp[i] 表示长度不超过i，而且数值不超过n的前i位的最大的数
    vector<string> dp_no_limit(n_len + 1);  // 长度不超过i的最大的数
    for(int i = 0; i <= n_len; i++){
        string temp = n_s.substr(0, i);
        if(i){
            dp_no_limit[i] = dp_no_limit[i - 1];
            dp[i] = dp_no_limit[i - 1];
        }
        for(int j = 0; j < i; j++){
            int k = 0;
            if(vv[i - j].size()) dp_no_limit[i] = max(dp_no_limit[i], dp_no_limit[j] + vv[i - j][0]);
            while(k < vv[i - j].size() && dp[j] + vv[i - j][k] > temp) k++;
            if(k < vv[i - j].size()) dp[i] = max(dp[i], dp[j] + vv[i - j][k]);
        }
    }
    cout << dp[n_len] << endl;
    return 0;
}