// 构造法
// 递归求得 b * y + (a % b) * x == (a, b) 的解xy，需要整理方程、更新xy，使得 a * x + b * y = (a, b)
// b * y + (a - a / b * b) * x = a * x + b * (y - a / b * x)
#include <iostream>
using namespace std;

int n, a, b, x, y;

void exgcd(int a, int b, int& x, int& y){  // void也可
    if(!b){
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
    return;
}

int main(){
    cin >> n;
    while(n--){
        cin >> a >> b;
        exgcd(a, b, x, y);
        cout << x << ' ' << y << endl;
    }
    return 0;
}