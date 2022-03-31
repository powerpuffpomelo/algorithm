// 一个集合里有很多数，给定数n，需要用集合中的数拼接出不超过n的最大的数，集合中的数可以无限次取用
// 不知道对不对
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, n_len;
vector<int> arr;
string n_s, ans;
vector<string> vv[N];   // 集合中每种长度的数维护一个列表，而且列表降序排列，如果集合是{93, 7, 9}的话，长度为1的数维护的列表就是{9, 7}

bool cmp(string a, string b){
    return a > b;
}

int main(){
    n = 98;
    arr = {93, 9, 7};    // 随便设置一个场景
    n_s = to_string(n); 
    n_len = n_s.size(); 
    for(int x : arr){    // 读入集合中的每个数，并按长度归类，每个长度类别下降序排列
        string s = to_string(x);
        vv[s.size()].push_back(s);
        sort(vv[s.size()].begin(), vv[s.size()].end(), cmp);
    }

    // 同时维护两个dp数组：普通的dp和没有数值限制的dp_no_limit
    vector<string> dp(n_len + 1);    // dp[i] 表示长度不超过i，而且数值不超过n的前i位的最大的数，那么显然最终答案是dp[n_len]
    vector<string> dp_no_limit(n_len + 1);  // dp_no_limit[i] 表示长度不超过i的最大的数，无数值限制
    // 之所以要构造上面这个没有限制版本的dp_no_limit，是因为：
    // 如果集合无法刚好拼接出长度和n一样的数，那么不能直接取出dp[i - 1]，而应该在长度为i-1中的数中找尽可能大的
    // 比如，n=100，arr={10, 9}，则dp[2]=10, 但显然答案应该取99而不是10

    for(int i = 0; i <= n_len; i++){    // 枚举拼接数的长度i
        string temp = n_s.substr(0, i);   // 原始n的前i位拎出来
        if(i){
            dp_no_limit[i] = dp_no_limit[i - 1];
            dp[i] = dp_no_limit[i - 1];
        }
        for(int j = 0; j < i; j++){    // 拼接到长度为j的数后面，看能不能更大一点
            int k = 0;
            // vv[i - j]表示长度为i-j的列表，看有没有元素，如果有的话就试试把它拼接到长度为j的数后面；
            // vv[i - j][0]就是长度为i-j的列表中最大的那个（因为降序排列），dp_no_limit没有大小限制，所以可以直接拼最大的
            if(vv[i - j].size()) dp_no_limit[i] = max(dp_no_limit[i], dp_no_limit[j] + vv[i - j][0]);
            // 但是dp数组要考虑数值限制，所以如果一开始超过n的话，就在这个列表里依次找更小的长度为i-j的数，直到满足拼接后不超过n
            while(k < vv[i - j].size() && dp[j] + vv[i - j][k] > temp) k++;
            if(k < vv[i - j].size()) dp[i] = max(dp[i], dp[j] + vv[i - j][k]);  // 如果存在的话，就max一下取最大的
        }
    }
    cout << dp[n_len] << endl;
    return 0;
}
