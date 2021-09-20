// ###################################################### 版本1 ###################################################### //
#include <iostream>
using namespace std;

const int N = 10;
int n;
int g[N][N];

void show(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(g[i][j] == 1) printf("Q");
            else printf(".");
        }
        puts("");
    }
    puts("");
}

bool can(int i, int j){
    for(int t = 1; t <= n; t++){
        if(g[i][t] == 1 or g[t][j] == 1) return false;
    }
    for(int x = - n + 1; x < n; x++){
        if(i + x >= 1 && i + x <= n && j + x >= 1 && j + x <= n && g[i + x][j + x] == 1) return false;
        if(i + x >= 1 && i + x <= n && j - x >= 1 && j - x <= n && g[i + x][j - x] == 1) return false;
    }
    return true;
}

void dfs(int u){
    if(u > n){
        show();
        return;
    }
    int i = u;    //皇后u在第u行
    for(int j = 1; j <= n; j++){   //枚举这一行的每个位置
        if(can(i, j)){
            g[i][j] = 1;
            dfs(u + 1);
            g[i][j] = 0;
        }
    }
}

int main(){
    scanf("%d", &n);
    dfs(1);
    return 0;
}

// ###################################################### 版本2 ###################################################### //
#include <iostream>
using namespace std;

const int N = 20;
char g[N][N];
int col[N], dg[N], udg[N];  // dg是对角线数组，udg是反对角线数组
int n;

void dfs(int u){
    if(u == n){
        for(int i = 0; i < n; i++) puts(g[i]);   //为了可以puts，数组要从0到n-1，而不能从1到n，不然puts空白
        puts("");
        return;
    }
    for(int j = 0; j < n; j++){
        if(!col[j] && !dg[u + j] && !udg[n - u + j]){   //其实对角线如何定义不重要，只要保证同一对角线对应到同一坐标即可。
            g[u][j] = 'Q';
            col[j] = dg[u + j] = udg[n - u + j] = 1;  // y = x + b  ->  b = y - x   y = -x + b  -> b = y + x
            dfs(u + 1);
            g[u][j] = '.';
            col[j] = dg[u + j] = udg[n - u + j] = 0;  // 比如看一个点(x, y)的dg对角线有没有，就是看这条线（用截距表示）有没有被占领
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < n; j++){
            g[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}
