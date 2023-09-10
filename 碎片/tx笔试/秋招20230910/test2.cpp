#include <bits/stdc++.h>
using namespace std;

const int N = 11;
double A[N][N];
double v[N], newv[N];
int n;
bool flag = true;
double pre = -1e9, epsilon = 1e-3, ans, x, y, z;
double avg;

void cal(){
    avg = 0;
    for(int i = 0; i < n; i++){
        newv[i] = 0;
        for(int j = 0; j < n; j++){
            newv[i] += A[i][j] * v[j];
        }
        avg += newv[i] / v[i];
    }
    avg /= n;
    if(avg - pre < epsilon){
        flag = false;
        ans = avg;
        return;
    }
    pre = avg;
    for(int i = 0; i < n; i++) v[i] = newv[i];
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }
    for(int i = 0; i < n; i++) cin >> v[i];
    while(flag){
        cal();
    }
    printf("%.2f\n", ans);
    return 0;
}