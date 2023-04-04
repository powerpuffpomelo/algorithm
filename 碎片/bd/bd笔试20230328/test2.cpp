#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e4 + 10;
int n, m;
int a[N], kind[N];

vector<double> people, mall;
vector<double> Right, Left;
vector<int> ans;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n + m; i++) cin >> a[i];
    for(int i = 0; i < n + m; i++) cin >> kind[i];
    for(int i = 0; i < n + m; i++){
        if(kind[i] == 0) people.push_back(a[i]);
        else mall.push_back(a[i]);
    }
    Left.resize(m), Right.resize(m), ans.resize(m);
    for(int i = 0; i < m - 1; i++){
        Right[i] = (mall[i] + mall[i + 1]) / 2;
    }
    for(int i = 1; i < m; i++){
        Left[i] = (mall[i - 1] + mall[i]) / 2;
    }
    Right[m - 1] = INT_MAX;
    Left[0] = 0;
    for(int i = 0, j = 0; i < n; i++){
        while(people[i] > Right[j]) j++;
        if(people[i] <= Right[j]) ans[j]++;
        else{
            ans[++j]++;
        }
    }
    for(int i = 0; i < m; i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}