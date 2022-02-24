#include <iostream>
using namespace std;

const int N = 110;
int arr[N][N];
int n, m;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int main(){
    cin >> n >> m;
    for(int x = 0, y = 0, idx = 1, d = 0; idx <= n * m; idx++){
        arr[x][y] = idx;
        int newx = x + dx[d], newy = y + dy[d];
        if(newx < 0 || newx >= n || newy < 0 || newy >= m || arr[newx][newy]){
            d = (d + 1) % 4;
            newx = x + dx[d], newy = y + dy[d];
        }
        x = newx, y = newy;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}