#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
int n, k;
int color[N];
unordered_map<int, int> cnt;


int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> color[i];
    int temp_cnt = 0, ans = 0;
    int l = 1;
    for(int i = 1; i <= n; i++){
        cnt[color[i]]++;
        if(cnt[color[i]] == 1) temp_cnt++;
        while(temp_cnt > k){
            cnt[color[l]]--;
            if(cnt[color[l]] == 0) temp_cnt--;
            l++;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans << endl;
    return 0;
}