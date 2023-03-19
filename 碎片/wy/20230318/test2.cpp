#include <bits/stdc++.h>
using namespace std;

int n, m;
string src, tgt;

int main(){
    while(cin >> src >> tgt){
        n = src.size(), m = tgt.size();
        bool flag = false;
        for(int i = 0; i + m - 1 < n; i++){
            if(src.substr(i, m) == tgt){
                cout << i << endl;
                flag = true;
                break;
            }
        }
        if(!flag) cout << -1 << endl;
    }
    return 0;
}