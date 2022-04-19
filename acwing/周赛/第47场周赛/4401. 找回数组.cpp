#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, a[N];
vector<int> ans;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = n; i > 1; i--) a[i] -= a[i - 1];
    for(int i = 1; i <= n; i++){
        bool flag = true;
        for(int j = i + 1; j <= n; j ++){
            if(a[j] != a[j - i]){
                flag = false;
                break;
            }
        }
        if(flag) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(int k : ans) cout << k << ' ';
    return 0;
}