// 有问题，还需要改
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];
int ansh, ansl;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int high = 0, low = 0;
    int h = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == 1) h++;
        else h--;
        high = max(high, h);
        low = min(low, h);
        ansh = max(ansh, high - h);
        ansl = max(ansl, h - low);
    }
    cout << max(ansh, ansl) + 1 << endl;
    return 0;
}