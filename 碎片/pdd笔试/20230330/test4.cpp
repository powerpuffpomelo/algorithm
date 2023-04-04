#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int t, n;
int a[N];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        set<int> se;
        stack<int> stk;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n - 1; i++){
            if(a[i + 1] < a[i] || se.count(a[i + 1])){
                if(se.count(a[i + 1])) a[i + 1] = 0;
                if(a[i]) se.insert(a[i]);
                while(stk.size()){
                    se.insert(stk.top());
                    stk.pop();
                }
            }else{
                if(a[i]) stk.push(a[i]);
            }
        }
        cout << se.size() << endl;
    }
    return 0;
}