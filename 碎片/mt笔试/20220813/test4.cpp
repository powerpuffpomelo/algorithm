#include <bits/stdc++.h>
using namespace std;

const int N = 4010;
unordered_map<int, int> cnt;
int n;
int a[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0;
    cnt[a[0]] = 1;
    for(int j = 1; j < n - 1; j++){
        for(int k = j + 1; k < n;){
            int rep = 1;
            while(k + 1 < n && a[k] == a[k + 1]){
                k++;
                rep++;
            }
            int temp = 3 * a[j] - a[k];
            if(cnt.count(temp)) ans += cnt[temp] * rep;
            k++;
        }
        if(!cnt.count(a[j])) cnt[a[j]] = 0;
        cnt[a[j]]++;
    }
    cout << ans << endl;
    return 0;
}