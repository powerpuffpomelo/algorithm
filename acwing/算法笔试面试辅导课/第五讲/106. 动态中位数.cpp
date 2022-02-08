#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int p, id, m;

int main(){
    scanf("%d", &p);  // 本题cin cout会超时
    while(p--){
        scanf("%d%d", &id, &m);
        printf("%d %d", id, (m + 1) / 2);
        priority_queue<int> down;
        priority_queue<int, vector<int>, greater<int>> up;
        int cnt = 0;
        for(int i = 0; i < m; i++){
            int x;
            scanf("%d", &x);
            if(!down.size() || x <= down.top()) down.push(x);
            else up.push(x);
            if(down.size() > up.size() + 1) up.push(down.top()), down.pop();
            if(up.size() > down.size()) down.push(up.top()), up.pop();
            if(!(i % 2)){
                if(!(cnt % 10)) puts("");
                cnt++;
                printf("%d ", down.top());
            }
        }
        puts("");
    }
    return 0;
}