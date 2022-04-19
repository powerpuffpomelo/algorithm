// ###################################################### 版本2 ###################################################### //
// 队列模拟
#include <bits/stdc++.h>
using namespace std;

int n, k;
queue<int> q;

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) q.push(i);
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        x %= (n - i);  // 或 x %= q.size()
        while(x--){
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ' ';
        q.pop();
    }
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, k;
int out[N];
int leader = 1;

int main(){
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        x %= (n - i);
        while(x){
            leader = leader + 1;
            if(leader > n) leader = 1;
            while(out[leader]){
                leader = leader + 1;
                if(leader > n) leader = 1;
            }
            x--;
        }
        out[leader] = 1;
        cout << leader << ' ';
        while(out[leader]){
            leader = leader + 1;
            if(leader > n) leader = 1;
        }
    }
    return 0;
}