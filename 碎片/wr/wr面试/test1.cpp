#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // you can write to stdout for debugging purposes, e.g.
    // std::cout << "This is a debug message" << std::endl;
    // [1, 3, 2, 8, 7]  [3, 2, 1, 8, 7]  [1, 8, 3, 2, 7]
    vector<int> ori = {1, 2, 3, 7, 8};
    vector<int> reo = {8, 7, 1, 2, 3};
    unordered_map<int, int> num2pos;
    map<int, int> pre;
    int n = ori.size();
    for(int i = 0; i < n; i++) num2pos[ori[i]] = i;
    vector<int> dp(n + 1, 1);
    int ans = 0, ansp = -1;
    for(int i = 0; i < n; i++){
        int xp = num2pos[reo[i]];
        for(int j = 0; j < i; j++){
            if(num2pos[reo[j]] < xp && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                pre[i] = j;  // 保存前一个
                if(dp[i] > ans){
                    ans = dp[i];
                    ansp = i;
                }
            }
        }
    }
    cout << n - ans << endl;
    set<int> se;
    se.insert(reo[ansp]);
    int k = ansp;
    while(pre.count(k)){
        k = pre[k];
        se.insert(reo[k]);
    }
    //for(auto x : se) cout << x << ' ';
    //cout << endl;
    for(int i = 0; i < n; i++){
        if(!se.count(ori[i])) cout << ori[i] << ' ';
    }
    return 0;
}
