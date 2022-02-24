// 欧几里得算法，辗转相除法，时间复杂度O(logn)
#include <iostream>
using namespace std;

int n, a, b;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    return 0;
}