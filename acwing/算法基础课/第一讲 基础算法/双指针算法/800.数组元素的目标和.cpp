#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m, x;
int A[N], B[N];

int main(){
    scanf("%d%d%d", &n, &m, &x);
    for(int i = 0; i < n; i++) scanf("%d", &A[i]);
    for(int i = 0; i < m; i++) scanf("%d", &B[i]);
    int i = 0, j = m - 1;
    while(i < n && j >= 0){
        if(A[i] + B[j] == x){
            printf("%d %d\n", i, j);
            return 0;
        }else if(A[i] + B[j] > x) j--;
        else i++;
    }
    return 0;
}