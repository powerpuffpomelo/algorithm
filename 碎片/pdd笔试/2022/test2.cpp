/*
有n片瓜田，第i片瓜田在[ai, bi]时间段内可以结ki个瓜，只能在这个时间段内去摘瓜，且每天总共只能摘v个瓜，问最多能摘多少个瓜
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 3010;
int T, n, v, k, a, b;
struct node{
    int k, a, b;
    node(int _k, int _a, int _b): k(_k), a(_a), b(_b) {}
};

bool cmp(node* a, node* b){   // 终止日期升序
    return a->b < b->b;
}

int main(){
    cin >> T;
    while(T--){
        cin >> n >> v;
        vector<node*> vv;
        int st = 3010, ed = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            cin >> k >> a >> b;
            auto t = new node(k, a, b);
            vv.push_back(t);
            if(a < st) st = a;
            if(b > ed) ed = b;
        }
        sort(vv.begin(), vv.end(), cmp);
        // 每一天
        for(int d = st; d <= ed; d++){
            int rem = v;  // 今天还能采多少
            for(int i = 0; i < n; i++){
                auto p = vv[i];
                if(p->a <= d && p->b >= d && p->k > 0){
                    int pick = min(rem, p->k);
                    p->k -= pick;
                    rem -= pick;
                    ans += pick;
                }
                //if(p->a > d || rem == 0) break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}