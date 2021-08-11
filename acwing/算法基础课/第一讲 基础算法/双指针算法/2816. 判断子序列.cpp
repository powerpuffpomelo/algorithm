#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m;
int A[N], B[N];

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &A[i]);
    for(int i = 0; i < m; i++) scanf("%d", &B[i]);
    int i = 0, j = 0;
    while(i < n && j < m){
        if(A[i] == B[j]) i++;
        j++;
    }
    if(i == n) puts("Yes");
    else puts("No");
    return 0;
}