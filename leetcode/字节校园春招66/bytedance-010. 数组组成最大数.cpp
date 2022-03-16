#include <bits/stdc++.h>
using namespace std;

string str;
vector<string> vv;

bool cmp(string a, string b){
    return a + b <= b + a;
}
/* 一开始cmp麻烦了，不用自己算其实
bool cmp(string a, string b){
    int i = 0, j = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] != b[i]) return a[i] < b[i];
        i++, j++;
    }
    if(j < b.size()){
        return b[j] > b[0];
    }else if(i < a.size()){
        return a[i] <= a[0];
    }
    return true;
}
*/

void get_input(string str){
    string temp;
    for(int i = 1; i < str.size(); i++){
        if(str[i] != ',' && str[i] != ']'){
            temp += str[i];
        }else{
            vv.push_back(temp);
            temp = "";
        }
    }
}

int main(){
    cin >> str;
    get_input(str);
    sort(vv.begin(), vv.end(), cmp);
    string ans;
    for(int i = vv.size() - 1; i >= 0; i--) ans += vv[i];
    while(ans.size() > 1 && ans[0] == '0') ans = ans.substr(1);
    cout << ans << endl;
    return 0;
}