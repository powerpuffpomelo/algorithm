#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, M = 3e6 + 10;
int son[M][2], idx = 0;
int arr[N];
int n;
int ans = 0;

void insert(int a){
    int p = 0;
    for(int i = 30; i >= 0; i--){
        int &x = son[p][a >> i & 1];
        if(!x) x = ++idx;
        p = x;
    }
}

int search(int a){
    int p = 0, ans = 0;
    for(int i = 30; i >= 0; i--){
        int x = a >> i & 1;
        if(son[p][!x]){
            ans += 1 << i;
            p = son[p][!x];
        }else{
            p = son[p][x];
        }
    }
    return ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        insert(arr[i]);
    } 
    for(int i = 0; i < n; i++){
        ans = max(ans, search(arr[i]));
    }
    cout << ans << endl;
    return 0;
}