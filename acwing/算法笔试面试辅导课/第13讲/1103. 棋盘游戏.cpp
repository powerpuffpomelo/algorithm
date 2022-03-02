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

// ###################################################### 版本2 ###################################################### //
// 二进制
#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 16;
int st, ed;
int dist[N];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int input(){
    int ret = 0;
    for(int i = 0; i < 16; i++){
        char c;
        cin >> c;
        if(c == '1') ret += 1 << i;
    }
    return ret;
}

int bit_swap(int t, int x, int y){
    int ret = t;
    int a = t >> x & 1, b = t >> y & 1;
    ret -= a << x, ret -= b << y;
    ret += a << y, ret += b << x;
    return ret;
}

int bfs(int st, int ed){
    if(st == ed) return 0;
    queue<int> q;
    q.push(st);
    memset(dist, -1, sizeof dist);
    dist[st] = 0;
    while(q.size()){
        int t = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                for(int d = 0; d < 4; d++){
                    int a = i + dx[d], b = j + dy[d];
                    if(a < 0 || a >= 4 || b < 0 || b >= 4) continue;
                    int tmp = bit_swap(t, i * 4 + j, a * 4 + b);
                    if(dist[tmp] != -1) continue;
                    if(tmp == ed) return dist[t] + 1;
                    q.push(tmp);
                    dist[tmp] = dist[t] + 1;
                }
            }
        }
    }
    return -1;
}

int main(){
    st = input();
    ed = input();
    cout << bfs(st, ed) << endl;
    return 0;
}