// ###################################################### 版本1 ###################################################### //
// 我的初版, string
#include <bits/stdc++.h>
using namespace std;

string st, ed;
unordered_map<string, int> dist;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int bfs(string st, string ed){
    if(st == ed) return 0;
    queue<string> q;
    q.push(st);
    dist[st] = 0;
    while(q.size()){
        string t = q.front();
        int dd = dist[t];
        q.pop();
        for(int i = 0; i < 16; i++){
            int x = i / 4, y = i % 4;
            for(int d = 0; d < 4; d++){
                int a = x + dx[d], b = y + dy[d];
                int k = a * 4 + b;
                if(a < 0 || a >= 4 || b < 0 || b >= 4 || t[i] == t[k]) continue;
                //if(k < 0 || k >= 16 || t[i] == t[k]) continue;
                swap(t[i], t[k]);
                if(!dist.count(t)){
                    dist[t] = dd + 1;
                    if(t == ed) return dist[t];
                    q.push(t);
                }
                swap(t[i], t[k]);
            }
        }
    }
    return -1;
}

int main(){
    for(int i = 0; i < 4; i ++){
        string temp;
        cin >> temp;
        st += temp;
    }
    for(int i = 0; i < 4; i++){
        string temp;
        cin >> temp;
        ed += temp;
    }
    cout << bfs(st, ed) << endl;
    return 0;
}