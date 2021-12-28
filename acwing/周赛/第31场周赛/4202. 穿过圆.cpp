#include <iostream>
#include <bitset>
#include <cmath>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int N = 1010;

int n, m, k;
PII dot[N], circle[N];
int r[N];
bitset<N> st[N];  // 长度为N的bitset，一共N个，记录每个点，在每个圆的内外关系

int check(int i, int j){
    LL dx = dot[i].x - circle[j].x, dy = dot[i].y - circle[j].y;
    if(pow(dx, 2) + pow(dy, 2) < pow(r[j], 2)) return 1;
    return 0;
}

int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) scanf("%d%d", &dot[i].x, &dot[i].y);
    for(int i = 0; i < m; i++) scanf("%d%d%d", &r[i], &circle[i].x, &circle[i].y);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            st[i][j] = check(i, j);
        }
    }
    while(k--){
        int a, b;
        scanf("%d%d", &a, &b);
        cout << (st[a] ^ st[b]).count() << endl;  // 异或 数有多少个1就可以
    }
    return 0;
}