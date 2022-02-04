// 贪心，基于分析

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int n, a[N], b[N];

int judge(int x, int y){
    if(a[x] > b[y]) return 1;
    if(a[x] < b[y]) return -1;
    return 0;
}

int main(){
    while(cin >> n, n){
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        sort(a, a + n, greater<int>());
        sort(b, b + n, greater<int>());
        int ans = 0;
        int f1 = 0, f2 = 0, s1 = n - 1, s2 = n - 1;
        while(f1 <= s1){
            if(judge(s1, s2) > 0) ans++, s1--, s2--;
            else if(judge(s1, s2) < 0) ans += judge(s1, f2), s1--, f2++;
            else{
                if(judge(f1, f2) > 0) ans++, f1++, f2++;
                else ans += judge(s1, f2), s1--, f2++;
            }
        }
        cout << ans * 200 << endl;
    }
    return 0;
}