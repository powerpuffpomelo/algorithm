// ###################################################### 版本1 ###################################################### //
// 任何大于等于2的正整数都可以表示成质数的乘积
// n中最多只包含一个大于sqrt(n)的质因子
// 时间复杂度 O(sqrt(n))    其实最坏 O(sqrt(n)) 最好 O(log(n))
#include <iostream>
using namespace std;

int n;

void divide(int x){
    for(int i = 2; i <= x / i; i++){
        if(x % i == 0){
            int s = 0;
            while(x % i == 0){
                s++;
                x /= i;
            }
            printf("%d %d\n", i, s);
        }
    }
    if(x > 1) printf("%d %d\n", x, 1);
    puts("");
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        divide(a);
    }
    return 0;
}

// ###################################################### 版本2 ###################################################### //
#include <iostream>
using namespace std;

int n;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int a, s;
        scanf("%d\n", &a);
        for(int i = 2; i <= a / i; i++){
            s = 0;
            while(a % i == 0){
                s++;
                a /= i;
            }
            if(s){
                printf("%d %d\n", i, s);
            }
        }
        if(a > 1) printf("%d %d\n", a, 1);
        puts("");
    }
    return 0;
}