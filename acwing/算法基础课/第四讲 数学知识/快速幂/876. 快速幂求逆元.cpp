#include <iostream>
using namespace std;

typedef long long lld;
int n, a, p;

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
        cin >> a >> p;
        if(a % p == 0) cout << "impossible" << endl;
        else cout << qmi(a, p - 2, p) << endl;
    }
    return 0;
}