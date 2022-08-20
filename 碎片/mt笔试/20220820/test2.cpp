#include <bits/stdc++.h>
using namespace std;

int n;
int x1, x2, x3, y_1, y2, y3;
int d1, d2, d3;
int a, b;
typedef pair<int, int> pii;
int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, -1, 1};

int main(){
    cin >> n >> x1 >> y_1 >> x2 >> y2 >> x3 >> y3 >> d1 >> d2 >> d3;
    set<pii> se1, se2, se3;
    for(int i = 0; i <= d1; i++){
        for(int d = 0; d < 4; d++){
            a = x1 + i * dx[d], b = y_1 + (d1 - i) * dy[d];
            if(a >= 1 && a <= n && b >= 1 && b <= n) se1.insert({a, b});
        }
    }
    for(int i = 0; i <= d2; i++){
        for(int d = 0; d < 4; d++){
            a = x2 + i * dx[d], b = y2 + (d2 - i) * dy[d];
            if(a >= 1 && a <= n && b >= 1 && b <= n && se1.count({a, b})) se2.insert({a, b});
        }
    }
    for(int i = 0; i <= d3; i++){
        for(int d = 0; d < 4; d++){
            a = x3 + i * dx[d], b = y3 + (d3 - i) * dy[d];
            if(a >= 1 && a <= n && b >= 1 && b <= n && se2.count({a, b})) se3.insert({a, b});
        }
    }
    cout << se3.begin()->first << ' ' << se3.begin()->second << endl;
    return 0;
}
