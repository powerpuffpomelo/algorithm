// floyd算法，算法笔记上的例子

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 210, INF = 0x3fffffff;
int n, m;
int d[N][N];

void floyd(){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(){
    fill(d[0], d[0] + N * N, INF);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        d[i][i] = 0;
    }
    while(m--){
        int u, v;
        cin >> u >> v;
        cin >> d[u][v];
    }
    floyd();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << d[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}