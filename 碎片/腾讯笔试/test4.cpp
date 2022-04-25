// 过90.91%
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
typedef pair<int, int> PII;
int n, m;
vector<int> alls;
int a[N], b[N];
// 离散化！
int A[N], S[N];   // 红+1， 蓝-1
int q, l, r;
vector<PII> query;
int s1, s2, s3;

int find(int x){
    int l = 0, r = alls.size() - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l + 1;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        alls.push_back(a[i]);
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
        alls.push_back(b[i]);
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> l >> r;
        alls.push_back(l);
        alls.push_back(r);
        query.push_back({l, r});
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for(int i = 0; i < n; i++){
        A[find(a[i])] = 1;
    }
    for(int i = 0; i < m; i++){
        A[find(b[i])] = -1;
    }
    for(int i = 1; i <= alls.size(); i++){
        //cout << A[i] << ' ';
        S[i] = S[i - 1] + A[i];
    }
    for(auto item : query){
        l = find(item.first), r = find(item.second);
        if(S[r] - S[l - 1] > 0) s1++;
        else if(S[r] - S[l - 1] == 0) s2++;
        else s3++;
    }
    cout << s1 << ' ' << s2 << ' ' << s3 << endl;
    return 0;
}