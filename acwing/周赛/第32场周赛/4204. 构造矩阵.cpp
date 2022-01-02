#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int a[N][N];
int n;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++){
            a[i][j] = (i + j) % (n - 1) + 1;
        }
    }
    for(int i = 0; i < n - 1; i++){
        a[i][n - 1] = a[n - 1][i] = a[i][i];
        a[i][i] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", a[i][j]);
        }
        puts("");
    }
    return 0;
}

/* 构造方法

1 2 3 4 5
2 3 4 5 1
3 4 5 1 2
4 5 1 2 3
5 1 2 3 4

->

0 2 3 4 5 1
2 0 4 5 1 3
3 4 0 1 2 5
4 5 1 0 3 2
5 1 2 3 0 4
1 3 5 2 4 0

*/