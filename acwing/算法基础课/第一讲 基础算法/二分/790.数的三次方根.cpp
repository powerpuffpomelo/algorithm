#include <iostream>
using namespace std;

const double eps = 1e-8;
double n;

double binary_search(double l, double r){
    while(r - l > eps){
        double mid = (l + r) / 2 ;
        if(mid * mid * mid < n) l = mid;
        else r = mid;
    }
    return l;
}

int main(){
    scanf("%lf", &n);
    printf("%.6f", binary_search(-10001, 10001));
    
    return 0;
}