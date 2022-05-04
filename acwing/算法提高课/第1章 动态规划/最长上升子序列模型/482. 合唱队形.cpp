#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, h[N], llis[N], rlis[N], maxlen;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++){
        llis[i] = 1;
        for(int j = 0; j < i; j++){
            if(h[i] > h[j]) llis[i] = max(llis[i], llis[j] + 1);
        }
    }
    for(int i = n - 1; i >= 0; i--){
        rlis[i] = 1;
        for(int j = n - 1; j > i; j--){
            if(h[i] > h[j]) rlis[i] = max(rlis[i], rlis[j] + 1);
        }
    }
    for(int i = 0; i < n; i++){
        maxlen = max(maxlen, llis[i] + rlis[i] - 1);
    }
    cout << n - maxlen << endl;
    return 0;
}