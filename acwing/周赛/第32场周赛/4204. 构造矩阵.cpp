// ###################################################### 版本1 ###################################################### //
// yxc
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

// ###################################################### 版本2 ###################################################### //
// 抽风的，暂时看不懂
#include <stdio.h>
const int N = 1005;
bool r[N][N], c[N][N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    r[i][0] = c[i][0] = true;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        printf("0 ");
      } else if (i + j < n) {
        printf("%d ", i + j);
        r[i][i + j] = c[j][i + j] = true;
      } else {
        int v = 0;
        while (r[i][v] || c[j][v]) ++v;
        r[i][v] = c[j][v] = true;
        printf("%d ", v);
      }
    }
    puts("");
  }
  return 0;
}

/*
0 1 4 2 5 3
1 0 2 5 3 4
4 2 0 3 1 5
2 5 3 0 4 1
5 3 1 4 0 2
3 4 5 1 2 0
*/
