// ###################################################### 版本2 ###################################################### //
// cell另一种
#include <bits/stdc++.h>
using namespace std;

const int N = 10;
char g[N][N];
int row[N][N], col[N][N], cell[N][N][N];

void dfs(int i, int j){
    if(j == 9){
        i++, j = 0;
    }
    if(i == 9){
        for(int i = 0; i < 9; i++) puts(g[i]);
        return;
    }
    if(g[i][j] != '.') dfs(i, j + 1);
    else{
        for(int x = 1; x <= 9; x++){
            if(!row[i][x] && !col[j][x] && !cell[i / 3][j / 3][x]){
                row[i][x] = col[j][x] = cell[i / 3][j / 3][x] = 1;
                g[i][j] = x + '0';
                dfs(i, j + 1);
                row[i][x] = col[j][x] = cell[i / 3][j / 3][x] = 0;
                g[i][j] = '.';
            }
        }
    }
}

int main(){
    for(int i = 0; i < 9; i++){
        cin >> g[i];
        for(int j = 0; j < 9; j++){
            if(g[i][j] != '.'){
                int t = g[i][j] - '0';
                row[i][t] = col[j][t] = cell[i / 3][j / 3][t] = 1;
            }
        }
    }
    dfs(0, 0);
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 11;
char g[N][N];
int row[N][N], col[N][N], sq[N][N];

void dfs(int i, int j){
    if(j == 9){
        j = 0, i++;
    }
    if(i == 9){
        for(int x = 0; x < 9; x++){
            for(int y = 0; y < 9; y++){
                cout << g[x][y];
            }
            cout << endl;
        }
        return;
    }
    if(g[i][j] != '.') dfs(i, j + 1);
    else{
        int s = i / 3 * 3 + j / 3;
        for(int x = 1; x <= 9; x++){
            if(!row[i][x] && !col[j][x] && !sq[s][x]){
                row[i][x] = col[j][x] = sq[s][x] = 1;
                g[i][j] = '0' + x;
                dfs(i, j + 1);
                row[i][x] = col[j][x] = sq[s][x] = 0;
                g[i][j] = '.';
            }
        }
    }
}

int main(){
    for(int i = 0; i < 9; i++) cin >> g[i];
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(g[i][j] != '.'){
                int x = g[i][j] - '0';
                row[i][x] = 1;
                col[j][x] = 1;
                int s = i / 3 * 3 + j / 3;
                sq[s][x] = 1;
            }
        }
    }
    dfs(0, 0);
    return 0;
}

