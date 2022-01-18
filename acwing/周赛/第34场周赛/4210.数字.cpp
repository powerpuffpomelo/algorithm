#include <iostream>
using namespace std;

int a;

int cal_sum(int a, int i){
    int ret = 0;
    while(a){
        ret += a % i;
        a /= i;
    }
    return ret;
}

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    cin >> a;
    int ans_up = 0;
    for(int i = 2; i < a; i++) ans_up += cal_sum(a, i);
    int gg = gcd(ans_up, a - 2);
    printf("%d/%d\n", ans_up / gg, (a - 2) / gg);
    return 0;
}