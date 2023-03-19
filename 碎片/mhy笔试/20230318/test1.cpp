// 只能过80%
#include <bits/stdc++.h>
using namespace std;

string str, ans;
vector<vector<int>> g;

int main(){
    cin >> str;
    vector<int> vec;
    for(int i = 1; i < (int)str.size() - 1; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            int x = 0;
            while(str[i] >= '0' && str[i] <= '9'){
                x = x * 10 + str[i] - '0';
                i++;
            }
            vec.push_back(x);
        }
        if(str[i] == ']'){
            g.push_back(vec);
            vec = vector<int>();
        }
    }
    int n = g.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n / 2; j++){
            swap(g[i][j], g[i][n - j - 1]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            swap(g[i][j], g[j][i]);
        }
    }
    ans += '[';
    for(int i = 0; i < n; i++){
        ans += '[';
        for(int j = 0; j < n; j++){
            ans += to_string(g[i][j]);
            if(j != n - 1) ans += ',';
        }
        ans += ']';
        if(i != n - 1) ans += ',';
    }
    ans += ']';
    cout << ans << endl;
    return 0;
}