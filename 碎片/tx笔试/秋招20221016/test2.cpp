#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;
double t;

int main(){
    cin >> T;
    while(T--){
        cin >> n >> m >> t;
        vector<double> input(n);
        double x;
        vector<double> f(m), g(m);
        for(int i = 0; i < n; i++) cin >> input[i];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> x;
                f[i] += input[j] * x;
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> x;
                g[i] += input[j] * x;
            }
        }
        double temp = 0;
        for(int i = 0; i < m; i++){
            temp += (f[i] - g[i]) * (f[i] - g[i]);
        }
        if(t * t < temp) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}