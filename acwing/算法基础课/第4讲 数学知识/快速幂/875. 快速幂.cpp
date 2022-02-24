// 反复平方法，k次幂不用O(k)，只需O(logk)
#include <iostream>
using namespace std;

typedef long long lld;
int n, a, b, p;

lld qmi(int a, int b, int p){
    lld ret = 1;
    while(b){
        if(b & 1) ret = ret * a % p;
        b >>= 1;
        a = (lld)a * a % p;
    }
    return ret;
}

int main(){
    cin >> n;
    while(n--){
        cin >> a >> b >> p;
        cout << qmi(a, b, p) << endl;
    }
    return 0;
}