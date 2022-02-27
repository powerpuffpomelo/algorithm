// ###################################################### 版本1 ###################################################### //
// 
#include <bits/stdc++.h>
using namespace std;

string a, b, ans;
int cnt[10];

string check(int x){
    string ret;
    ret += to_string(x);
    cnt[x]--;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < cnt[i]; j++){
            ret += to_string(i);
        }
    }
    cnt[x]++;
    return ret;
}

int main(){
    cin >> a >> b;
    for(char c : a) cnt[c - '0']++;
    if(b.size() > a.size()){
        sort(a.begin(), a.end(), greater<int>());
        cout << a << endl;
        return 0;
    }
    for(int i = 0; i < a.size(); i++){
        for(int j = 9; j >= 0; j--){
            if(cnt[j] && ans + check(j) <= b){
                ans += to_string(j);
                cnt[j]--;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}