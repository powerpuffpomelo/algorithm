#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, t;
vector<int> vv;

int main(){
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        vv.push_back(x);
    }
    sort(vv.begin(), vv.end());
    int now = 0, ans = 0;
    for(int i = 0; i < n;){
        now += t;
        while(i < n && vv[i] < now) i++;
        if(i < n){
            ans++;
            i++;
        }
    }
    cout << n - ans << endl;
    return 0;
}