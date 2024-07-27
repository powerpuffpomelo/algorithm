// 100%
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
string s, a, b;
map<char, int> mps, mpa, mpb;

int main(){
    cin >> s >> a >> b;
    for(auto c : s) mps[c]++;
    for(auto c : a){
        if(c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        mpa[c]++;
    }
    for(auto c : b){
        if(c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        mpb[c]++;
    }
    int cnta = 0;
    int cntb = INT_MAX;
    int ans = 0;
    bool flag = true;
    while(true){
        for(char c = 'a'; c <= 'z'; c++){
            if(mpa[c] * cnta > mps[c]){
                flag = false;
                break;  // 如果无法完成cnta个a字符串，就不考虑了。
            }
            if(mpb[c]) cntb = min(cntb, (mps[c] - mpa[c] * cnta) / mpb[c]);
        }
        if(!flag) break;
        ans = max(ans, cnta + cntb);
        cnta++;
    }
    cout << ans << endl;
    return 0;
}
