// ###################################################### 版本1 ###################################################### //
// 我的初版，结构体
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, x;
struct ship{
    int t, k;
    vector<int> nat;
};
queue<ship*> q;
unordered_map<int, int> cnt;
int ans = 0;

int main(){
    cin >> n;
    while(n--){
        auto p = new ship;
        cin >> p->t >> p->k;
        for(int i = 0; i < p->k; i++){
            cin >> x;
            p->nat.push_back(x);
            if(!cnt[x]) ans++;
            cnt[x]++;
        }
        q.push(p);
        while(q.front()->t + 86400 <= p->t){
            auto qf = q.front();
            q.pop();
            auto vv = qf->nat;
            for(int i = 0; i < qf->k; i++){
                cnt[vv[i]]--;
                if(!cnt[vv[i]]) ans--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 每艘船拆开
#include <iostream>
#include <cstdio>

using namespace std;
typedef long long LL;

const int N = 300010;
int q[N][2]; //循环队列，q[i][0]保存时刻，q[i][1]保存国籍
LL cnt[N]; //每个国籍的人数

int main()
{
    int n;
    scanf("%d", &n);
    int hh = 0, tt = 0; //循环队列，tt指向队尾元素的下一个位置
    int ans = 0;
    while(n --)
    {
        int t, k;
        scanf("%d%d", &t, &k);

        //注意，这里是>= 86400，不包含第24小时这个时刻
        while(hh != tt && t - q[hh][0] >= 86400) 
        {
            int nation = q[hh][1];
            cnt[nation] --;
            if(cnt[nation] == 0) ans --;

            hh ++;
            if(hh == N) hh = 0; 
        }

        for(int i = 1; i <= k; i ++)
        {
            int x;
            scanf("%d", &x);

            if(cnt[x] == 0) ans ++;
            cnt[x] ++;

            q[tt][0] = t, q[tt][1] = x;
            tt ++;
            if(tt == N) tt = 0;
        }

        cout << ans << endl;
    }

    return 0;
}
