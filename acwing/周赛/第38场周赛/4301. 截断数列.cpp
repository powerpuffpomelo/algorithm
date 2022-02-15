// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

string str;
int n, a[110], s[110];

bool check(){
    for(int i = 1; i < n; i++){
        int sum = s[i];
        int p = i, q = i + 1;
        while(q <= n){
            while(q <= n && s[q] - s[p] < sum) q++;
            if(q <= n && s[q] - s[p] > sum) break;
            if(q <= n && s[q] - s[p] == sum){
                while(q + 1 <= n && a[q + 1] == 0) q++;
                p = q, q++;
            }
        }
        if(p < n) continue;
        return true;
    }
    return false;
}

int main(){
    cin >> n;
    cin >> str;
    for(int i = 1; i <= n; i++){
        a[i] = str[i - 1] - '0';
        s[i] = s[i - 1] + a[i];
    }
    if(check()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 简单一点的思路
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, sum;
char d[N];

int main(){
    cin >> n >> d;
    for(int i = 0; i < n; i++){
        d[i] -= '0';
        sum += d[i];
    }
    for(int k = 2; k <= n; k++){  // 枚举每种可能的分组
        if(sum % k != 0) continue;
        int s = sum / k;
        bool flag = true;
        for(int j = 0, t = 0; j < n; j++){
            t += d[j];
            if(t > s){
                flag = false;
                break;
            }
            else if(t == s) t = 0;
        }
        if(flag){    // 因为能整除，所以最后一组不会出现t<s的情况
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}