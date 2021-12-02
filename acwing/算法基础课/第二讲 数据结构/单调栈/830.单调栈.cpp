// 单调，是因为舍弃用不到的不单调部分

#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int st[N], top = -1;
int n;

int main(){
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        while(top != -1 && st[top] >= x) top--;
        if(top == -1) cout << -1 << ' ';
        else cout << st[top] << ' ';
        st[++top] = x;
    }
    return 0;
}