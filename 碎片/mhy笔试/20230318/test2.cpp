#include <bits/stdc++.h>
using namespace std;

string str;

int cal(string a, string b){
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(a[i - 1] == b[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    return dp[n][m];
}

int main(){
    while(cin >> str){
        bool flag = true;
        int n = str.size();
        if(n <= 8){
            cout << "NG" << endl;
            continue;
        }
        set<int> se;
        for(auto c : str){
            if(c >= 'A' && c <= 'Z') se.insert(1);
            else if(c >= 'a' && c <= 'z') se.insert(2);
            else if(c >= '0' && c <= '9') se.insert(3);
            else if(c != ' ') se.insert(4);
        }
        if(se.size() < 3){
            cout << "NG" << endl;
            continue;
        }
        string cpy = str;
        for(int i = 1; i < n; i++){
            string a = str.substr(0, i);
            string b = str.substr(i);
            int len = cal(a, b);
            if(len > 2){
                flag = false;
            }
        }
        if(flag) cout << "OK" << endl;
        else cout << "NG" << endl;
    }
    return 0;
}