// you can use includes, for example:
// #include <algorithm>
#include <bits/stdc++.h>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
const int mod = 1e9 + 7;
int ans = 0;
typedef pair<int, int> pii;
map<pii, int> cnt;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int solution(vector<int> &X, vector<int> &Y) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    int n = X.size();
    for(int i = 0; i < n; i++){
        int a = X[i], b = Y[i];
        if(a > b) continue;
        int gg = gcd(a, b);
        a /= gg, b /= gg;
        int c = b - a;
        if(cnt.count({c, b})) ans = (ans + cnt[{c, b}]) % mod;
        cnt[{a, b}]++;
    }
    return ans;
}
