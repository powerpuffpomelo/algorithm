#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e6 + 10;
int n, m;
int A[N], S[N];
vector<int> alls;
vector<PII> add, query;

int find(int x){   //寻找映射索引
    int l = 0, r = alls.size() - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l + 1;  // 前缀和索引从1开始方便
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});  // pair用{}括起来
        alls.push_back(x);
    }
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for(auto item : add){
        A[find(item.first)] += item.second;
    }
    for(int i = 1; i <= alls.size(); i++){
        S[i] = S[i - 1] + A[i];
    }
    for(auto item : query){
        cout << S[find(item.second)] - S[find(item.first) - 1] << endl;
    }
    return 0;
}