// 暴力20%
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e4 + 10;
int n, l, r;
int a[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    ll mmax = 1;
    
    for(int i = 0; i < n; i++){
        ll temp = 1;
        for(int j = i; j < n; j++){
            if(a[j] == 0) break;
            temp *= a[j];
            if(temp >= mmax){
                mmax = temp;
                if(j - i >= r - l){
                    l = i, r = j;
                }
            }
        }
    }
    cout << l << ' ' << r << endl;
    return 0;
}