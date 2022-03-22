#include <bits/stdc++.h>
using namespace std;

string str, ans;
int k;

string cal(string str, int k){
    string ret;
    //cout << k << endl;
    for(int i = 0; i < str.size(); i++){
        //cout << ret << endl;
        while(k > 0 && ret.size() && ret.back() < str[i]){
            ret.pop_back();
            k--;
        }
        ret += str[i];
    }
    //cout << "here" << endl;
    //cout << ret << endl;
    return ret.substr(0, ret.size() - k);
}

int main(){
    cin >> str;
    k = str[0] - '0';
    ans = cal(str, k);
    cout << ans << endl;
    return 0;
}