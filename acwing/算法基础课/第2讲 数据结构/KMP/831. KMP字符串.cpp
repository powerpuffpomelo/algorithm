// next[i] 表示 以i为结尾的子串 与 前缀子串 相同 的最大长度
// next[i] = j 意味着 p[1 ~ j] = p[i-j+1 ~ i]
#include <iostream>
using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;
int n, m;
char S[M], P[N];
int ne[N];

int main(){
    cin >> n >> P + 1 >> m >> S + 1;
    
    // 求next数组
    for(int i = 2, j = 0; i <= n; i++){
        while(j && P[i] != P[j + 1]) j = ne[j];
        if(P[i] == P[j + 1]) j++;
        ne[i] = j;
    }
    
    // kmp匹配过程，复杂度O(2m) 因为j每次最多+1，而如果j进入while循环则最少-1，因此进入while循环最多m次
    for(int i = 1, j = 0; i <= m; i++){
        while(j && S[i] != P[j + 1]) j = ne[j]; // 每次跳到ne[j]就是看模式串最少往后移动多少
        if(S[i] == P[j + 1]) j++;
        if(j == n){
            cout << i - n << ' '; // 下标从零开始
            j = ne[j]; // 不要忘记
        }
    }
    return 0;
}