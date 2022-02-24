// ###################################################### 版本1 ###################################################### //
// 朴素筛法，埃式筛法，时间复杂度 O(nloglogn)，和 O(n)基本一个级别
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, cnt;
int primes[N];
bool st[N];

void get_primes(int n){
    for(int i = 2; i <= n; i++){
        if(st[i]) continue;
        primes[cnt++] = i;
        for(int j = i + i; j <= n; j += i) st[j] = true;
    }
}

int main(){
    scanf("%d", &n);
    get_primes(n);
    printf("%d\n", cnt);
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 线性筛法 O(n)
// i是质数就筛掉i与primes中所有质数的乘积；i是非质数筛掉i与primes中所有<=最小质因子的乘积
// 关于break的点: i % primes[j] == 0，则 i = x * primes[j]，如果要筛 i * primes[j + 1] 的话，就相当于筛 x * primes[j] * primes[j + 1]；
// 而这个数本应被更小的 primes[j] 筛掉
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, cnt;
int primes[N];
bool st[N];

void get_primes(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;  // 保证每个数都被它最小的质因子筛掉
        }
    }
}

int main(){
    scanf("%d", &n);
    get_primes(n);
    printf("%d\n", cnt);
    return 0;
}