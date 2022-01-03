#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;

bool is_prime(int x){
    if(x < 2) return false;
    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
    scanf("%d", &n);
    while(n--){
        int a;
        scanf("%d", &a);
        if(is_prime(a)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}