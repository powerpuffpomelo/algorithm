// 暴力，18%
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 60;
int m, n;
int x1, y_1, x2, y2;  // 此正方形作为答案候选
vector<pii> vec;

int main(){
    cin >> m >> n;
    x1 = y_1 = INT_MAX, x2 = y2 = INT_MIN;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        vec.push_back({x, y});
        x1 = min(x1, x), y_1 = min(y_1, y);
        x2 = max(x2, x), y2 = max(y2, y);
    }
    int ans = INT_MAX;
    for(int i = x1; i <= x2; i++){
        for(int j = y_1; j <= y2; j++){
            vector<int> temp;
            for(int k = 0; k < n; k++){
                int a = vec[k].first, b = vec[k].second;
                temp.push_back(max(abs(i - a), abs(j - b)));
            }
            sort(temp.begin(), temp.end());
            ans = min(ans, temp[m - 1]);
        }
    }
    cout << ans << endl;
    return 0;
}