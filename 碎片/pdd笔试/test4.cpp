/*
如果字符串（只包含小写字母）中每个字母的出现次数都相同，且出现次数可以被k整除，那么称为漂亮串，
再输入一个比较串s，输出比s字典序大且满足k的字典序最小的漂亮串，不存在输出-1
这个代码暴力只过了32%
*/

#include <bits/stdc++.h>
using namespace std;

int T;
int n, k;
string str;

bool check(string s, int k){
    unordered_map<char, int> cnt;
    for(auto c : s) cnt[c]++;
    for(auto c : s){
        if(cnt[c] % k) return false;
    }
    return true;
}

string ne(string s, int n){
    int k = n - 1;
    while(s[k] == 'z') k--;
    s[k] += 1;
    for(int i = k + 1; i < n; i++) s[i] = 'a';
    return s;
}

int main(){
    cin >> T;
    while(T--){
        cin >> n >> k >> str;
        if(n % k){
            cout << -1 << endl;
            continue;
        }
        if(k == 1){
            cout << str << endl;
            continue;
        }
        string ans;
        for(int i = 0; i < n; i++) ans += str[i];
        while(!check(ans, k)) ans = ne(ans, n);
        cout << ans << endl;
    }
    return 0;
}