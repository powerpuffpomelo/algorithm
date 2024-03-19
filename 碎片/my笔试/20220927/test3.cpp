// 85%
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int T;
int n, k, x, y;

int main(){
    cin >> T;
    while(T--){
        vector<vector<int>> food(4, vector<int>());
        cin >> n >> k;
        k /= 2;
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            if(!y && x < 0 && -x <= k) food[0].push_back(-x);
            else if(!y && x >= 0 && x <= k) food[1].push_back(x);
            else if(!x && y < 0 && -y <= k) food[2].push_back(-y);
            else if(!x && y >= 0 && y <= k) food[3].push_back(y);
        }
        int ans = 0;
        for(int i = 0; i < 4; i++){
            sort(food[i].begin(), food[i].end());
            ans = max(ans, (int)food[i].size());   // 这里应该 找到k以内的food的个数，可能是这里扣的分
            // for(int j = 0; j < food[i].size(); j++){
            //     cout << food[i][j] << ' ';
            // }
            // cout << endl;
        }
        for(int a = 0; a <= food[0].size(); a++){
            int s1 = (a ? food[0][a - 1] : 0);
            int num1 = a;
            //cout << s1 << ' ';
            for(int b = 0; b <= food[1].size(); b++){
                int s2 = b ? food[1][b - 1] : 0;
                int num2 = b;
                //cout << s2 << ' ';
                if(num1 + num2 > k) break;
                for(int c = 0, d = food[3].size(); c <= food[2].size(); c++){
                    int s3 = c ? food[2][c - 1] : 0;
                    int num3 = c;
                    int rem = k - s1 - s2 - s3;
                    if(rem < 0) break;
                    while(d && food[3][d - 1] > rem) d--;
                    int num4 = d;
                    //cout << num1 << ' ' << num2 << ' ' << num3 << ' ' << num4 << endl;
                    ans = max(ans, num1 + num2 + num3 + num4);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}