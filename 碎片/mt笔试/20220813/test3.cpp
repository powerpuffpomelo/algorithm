#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
int vis[N], ori[N];

int main(){
    cin >> n;
    int pos = n - 1;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        for(int k = 0; k < 3; k++){
            do pos = (pos + 1) % n;
            while(vis[pos]);
        }
        vis[pos] = 1;
        ori[pos] = a;
    }
    for(int i = 0; i < n; i++) cout << ori[i] << ' ';
    return 0;
}