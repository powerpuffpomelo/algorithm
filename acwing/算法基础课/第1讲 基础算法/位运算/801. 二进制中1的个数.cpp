#include <iostream>
using namespace std;

int n;

int lowbit(int x){    // x的二进制表达式中最低位的1所对应的值
    return x & -x;
}

int main(){
    cin >> n;
    while(n--){
        int x, ans = 0;
        cin >> x;
        while(x){
            x -= lowbit(x);
            ans++;
        }
        cout << ans << ' ';
    }
    return 0;
}