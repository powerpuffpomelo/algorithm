// ###################################################### 版本2 ###################################################### //
// 简洁一点的写法，string还有 .back()  .pop_back() 功能
#include <iostream>
#include <string>
using namespace std;

string num, ans;
int k;

int main(){
    cin >> num >> k;
    ans = "0";  // 事先补一位，能省很多麻烦
    for(int i = 0; i < num.size(); i++){
        while(k && num[i] < ans.back()){
            ans.pop_back();
            k--;
        }
        ans += num[i];
    }
    while(k--) ans.pop_back();
    int i = 0;
    while(i < ans.size() && ans[i] == '0') i++;
    if(i == ans.size()) cout << '0' << endl;
    else cout << ans.substr(i) << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <iostream>
#include <string>
using namespace std;

string str, ans;
int k;

void del_k(string &str, int k){
    ans += str[0];
    for(int i = 1; i < str.size(); i++){
        while(k && ans.size() && str[i] < ans[ans.size() - 1]){
            ans = ans.substr(0, ans.size() - 1);
            k--;
        }
        ans += str[i];
    }
    if(k) ans = ans.substr(0, ans.size() - k);
    while(ans.size() && ans[0] == '0') ans = ans.substr(1, ans.size() - 1);
}

int main(){
    cin >> str >> k;
    del_k(str, k);
    if(ans.size()) cout << ans << endl;
    else cout << '0' << endl;
    return 0;
}