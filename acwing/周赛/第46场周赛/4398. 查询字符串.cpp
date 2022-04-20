// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, unordered_set<string>> mp;
int n, q;
string str;

void process(string str){
    for(int len = 1; len <= str.size(); len++){
        for(int i = 0; i + len - 1 < str.size(); i++){
            mp[str.substr(i, len)].insert(str);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        process(str);
    }
    cin >> q;
    while(q--){
        cin >> str;
        if(mp.count(str)) cout << mp[str].size() << ' ' << *mp[str].begin() << endl;
        else cout << "0 -" << endl;
    }
    return 0;
}