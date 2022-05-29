// ###################################################### 版本2 ###################################################### //
// 优化，'0'的ascii码是48，刚好能被4整除，所以直接用ascii码判断即可
#include <bits/stdc++.h>
using namespace std;

string str;
long long ans = 0;

int main(){
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] % 4 == 0) ans++;
        if(i && (str[i - 1] * 10 + str[i]) % 4 == 0) ans += i;    // 等价于((x + 48) * 10 + (y + 48)) % 4 == 0
    }
    cout << ans << endl;
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

string str;
long long ans = 0;

int main(){
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        int x = str[i] - '0';
        if(x % 4 == 0) ans++;
        if(i){
            int y = str[i - 1] - '0';
            if((y * 10 + x) % 4 == 0) ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}