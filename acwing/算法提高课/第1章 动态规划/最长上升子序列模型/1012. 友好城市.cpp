#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 5010;
int n, ans, dp[N];
vector<pii> vec;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        vec.push_back(make_pair(a, b));
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(vec[i].second > vec[j].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
