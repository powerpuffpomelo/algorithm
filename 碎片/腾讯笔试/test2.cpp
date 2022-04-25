#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int c;
double f[N], a[N][N];

int main(){
    cin >> c;
    double mmax = -1e9, ret = -1;
    for(int i = 0; i < c; i++) cin >> f[i];
    for(int i = 0; i < c; i++){
        double s = 0;
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
            s += a[i][j] * f[j];
        }
        if(s > mmax){
            mmax = s;
            ret = i;
        }
    }
    cout << ret << endl;
    return 0;
}