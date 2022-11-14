#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
struct node{
    int x, v, id;
}nodes[N];

bool cmpv(node a, node b){
    return a.v < b.v;
}

bool cmpid(node a, node b){
    return a.id < b.id;
}

int main(){
    cin >> n;
    vector<int> xv(n);
    for(int i = 0; i < n; i++){
        cin >> xv[i] >> nodes[i].v;
        nodes[i].id = i;
    }
    sort(xv.begin(), xv.end());
    sort(nodes, nodes + n, cmpv);
    for(int i = 0; i < n; i++){
        nodes[i].x = xv[i];
    }
    sort(nodes, nodes + n, cmpid);
    for(int i = 0; i < n; i++){
        cout << nodes[i].x << ' ' << nodes[i].v << endl;
    }
    return 0;
}