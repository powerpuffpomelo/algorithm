#include <iostream>
using namespace std;

int n;

bool is_prime(int x){
    if(x < 2) return false;
    for(int i = 2; i <= x / i; i++){   // 不会溢出的写法。不推荐 i * i <= x，会溢出；不推荐 i <= sqrt(x)，每次都要算一遍
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