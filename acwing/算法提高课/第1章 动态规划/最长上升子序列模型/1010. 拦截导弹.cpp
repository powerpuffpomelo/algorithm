// ###################################################### 版本2 ###################################################### //
// 根本不需要priority_queue，只要普通数组就可以了！因为找到要直接替换的位置，替换后不改变单调性！
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, h[N];
int dp[N], max_num;
int q[N], cnt;

int main(){
    while(cin >> h[n]) n++;
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(h[i] <= h[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_num = max(max_num, dp[i]);
        
        int k = 0;  // q是单调不下降队列，从前往后找第一个 >=当前高度的值，替换
        while(k < cnt && q[k] < h[i]) k++;
        if(k == cnt) q[cnt++] = h[i];
        else q[k] = h[i];
    }
    cout << max_num << endl << cnt << endl;
}

// ###################################################### 版本3 ###################################################### //
// stringstream用法
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

const int N = 1010;
int n, h[N];
int dp[N], max_num;
int q[N], cnt;

int main(){
    string line;
    getline(cin, line);
    stringstream ssin(line);
    while(ssin >> h[n]) n++;
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(h[i] <= h[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_num = max(max_num, dp[i]);
        
        int k = 0;
        while(k < cnt && q[k] < h[i]) k++;
        if(k == cnt) q[cnt++] = h[i];
        else q[k] = h[i];
    }
    cout << max_num << endl << cnt << endl;
}

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