// 90.91%
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
string str;
int cnt[N][3];
int ans = 0;
typedef pair<int, int> pii;
map<pii, int> ma;

int main(){
    cin >> str;
    int n = str.size();
    ma[{0, 0}] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++) cnt[i][j] = cnt[i - 1][j];
        if(str[i - 1] == 'r') cnt[i][0]++;
        else if(str[i - 1] == 'e') cnt[i][1]++;
        else cnt[i][2]++;
        pii p = {cnt[i][0] - cnt[i][1], cnt[i][1] - cnt[i][2]};
        ans += ma[p];
        ma[p]++;
    }
    cout << ans << endl;
    return 0;
}
