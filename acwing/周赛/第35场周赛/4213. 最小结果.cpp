// 递归搜索树，每个dfs是树的一个节点

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long lld;
vector<lld> a(4);
char op[3];
lld ans = 2e12;

void dfs(vector<lld> v, int u){
    if(v.size() == 1){
        ans = min(ans, v[0]);
        return;
    }
    for(int i = 0; i < v.size(); i++){
        for(int j = i + 1; j < v.size(); j++){
            vector<lld> tmp;
            for(int k = 0; k < v.size(); k++){
                if(k != i && k != j) tmp.push_back(v[k]);
            }
            if(op[u] == '*') tmp.push_back(v[i] * v[j]);
            else tmp.push_back(v[i] + v[j]);
            dfs(tmp, u + 1);
        }
    }
}

int main(){
    for(int i = 0; i < 4; i++) cin >> a[i];
    for(int i = 0; i < 3; i++) cin >> op[i];
    dfs(a, 0);
    cout << ans << endl;
    return 0;
}