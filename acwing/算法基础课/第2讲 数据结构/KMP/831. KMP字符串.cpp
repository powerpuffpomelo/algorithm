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
    
    // 匹配，复杂度O(2m)
    for(int i = 1, j = 0; i <= m; i++){
        while(j && S[i] != P[j + 1]) j = ne[j];
        if(S[i] == P[j + 1]) j++;
        if(j == n){
            cout << i - n << ' ';
            j = ne[j]; // 不要忘记
        }
    }
    return 0;
}