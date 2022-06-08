// ###################################################### 版本2 ###################################################### //
// 很优雅的方法！如果遇到cnt<0的情况，则此前的右括号数量就是可选项。然后检查一下后边是否合法就可
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n;
char s[N];

int work(){
    int cnt = 0, r = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') cnt++;
        else{
            cnt--;
            r++;
            if(cnt < 0){
                cnt += 2;
                for(int j = i + 1; j < n; j++){
                    if(s[j] == '(') cnt++;
                    else{
                        cnt--;
                        if(cnt < 0) return 0;
                    }
                }
                return r;
            }
        }
    }
    return 0;
}

int main(){
    scanf("%d%s", &n, s);
    int l = 0, r = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') l++;
        else r++;
    }
    if(r - l == 2) cout << work() << endl;
    else if(l - r == 2){
        reverse(s, s + n);
        for(int i = 0; i < n; i++){
            if(s[i] == '(') s[i] = ')';
            else s[i] = '(';
        }
        cout << work() << endl;
    }else cout << 0 << endl;
    return 0;
}

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