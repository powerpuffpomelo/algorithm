// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n;
string str;
int cl[N], cr[N], rcl[N], rcr[N];
int ans;
bool flag[N];

int main(){
    cin >> n >> str;
    for(int i = 0; i < n; i++){
        if(i) cl[i] = cl[i - 1], cr[i] = cr[i - 1];
        if(str[i] == '(') cl[i]++;
        else cr[i]++;
    }
    for(int i = n - 1; i >= 0; i--){
        if(i != n - 1) rcl[i] = rcl[i + 1], rcr[i] = rcr[i + 1];
        if(str[i] == ')') rcl[i]++;
        else rcr[i]++;
    }
    if(cl[n - 1] - cr[n - 1] == 2){
        for(int i = n - 1; i >= 0; i--){
            flag[i] = max(flag[i], flag[i + 1]);
            if(cl[i] - cr[i] < 2) flag[i] = 1;
        }
        for(int i = 0; i < n; i++){
            if(i && cr[i - 1] > cl[i - 1]){
                ans = 0;
                break;
            }
            if(str[i] == '(' && cl[i] - cr[i] >= 2 && !flag[i]) ans++;  // 换的话要保证右边全都 cl - cr >= 2
        }
    }else if(rcl[0] - rcr[0] == 2){
        for(int i = 0; i < n; i++){
            if(i) flag[i] = max(flag[i], flag[i - 1]);
            if(rcl[i] - rcr[i] < 2) flag[i] = 1;
        }
        for(int i = n - 1; i >= 0; i--){
            if(i != n - 1 && rcr[i + 1] > rcl[i + 1]){
                ans = 0;
                break;
            }
            if(str[i] == ')' && rcl[i] - rcr[i] >= 2 && !flag[i]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}