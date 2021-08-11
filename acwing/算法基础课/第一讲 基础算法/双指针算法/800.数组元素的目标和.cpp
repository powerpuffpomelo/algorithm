#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m, x;
int A[N], B[N];

int main(){
    scanf("%d%d%d", &n, &m, &x);
    for(int i = 0; i < n; i++) scanf("%d", &A[i]);
    for(int i = 0; i < m; i++) scanf("%d", &B[i]);

    //版本1
    int i = 0, j = m - 1;
    while(i < n && j >= 0){
        if(A[i] + B[j] == x){
            printf("%d %d\n", i, j);
            return 0;
        }else if(A[i] + B[j] > x) j--;
        else i++;
    }

    //版本2
    for(int i = 0, j = 0; i < n; i++){
        while(A[i] + B[j] < x && j < m - 1) j++;
        while(A[i] + B[j] > x && j > 0) j--;
        //printf("a %d %d ", i, j);
        if(A[i] + B[j] == x){
            printf("%d %d\n", i, j);
            return 0;
        }
    }

    return 0;
}