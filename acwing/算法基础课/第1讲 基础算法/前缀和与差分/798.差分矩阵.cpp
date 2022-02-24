#include <iostream>
using namespace std;

const int N = 1010;
int n, m, q;
int a[N][N], s[N][N];

void insert(int x1, int y1, int x2, int y2, int c){
    a[x1][y1] += c;
    a[x1][y2 + 1] -= c;
    a[x2 + 1][y1] -= c;
    a[x2 + 1][y2 + 1] += c;
}

int main(){
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            scanf("%d", &s[i][j]);
            insert(i, j, i, j, s[i][j]);
        }
    }
    while (q--){
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
    return 0;
}