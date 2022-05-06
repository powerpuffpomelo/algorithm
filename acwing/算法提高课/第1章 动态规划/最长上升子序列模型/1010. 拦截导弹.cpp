// ###################################################### 版本1 ###################################################### //
// 我的初版，贪心思路：维护一个小根堆，每次如果能插入现有堆的话就插最小的（高度>=当前高度的最小值），不能的话就开一个新的
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, h[N], x;
int dp[N], max_num;
priority_queue<int, vector<int>, greater<int>> q, temp;

int main(){
    while(cin >> x){
        h[n++] = x;
    }
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(h[i] <= h[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_num = max(max_num, dp[i]);
        
        while(q.size()){
            int t = q.top();
            q.pop();
            if(t >= h[i]){
                break;
            }
            temp.push(t);
        }
        q.push(h[i]);
        while(temp.size()){
            q.push(temp.top());
            temp.pop();
        }
    }
    cout << max_num << endl << q.size() << endl;
}