/*思路
所有见过的数字都维护进并查集p[N]，不是同一类一个集合，而是只要有关系都放到一个集合；
维护距离d[N]，代表每个数字和自己所在集合的根节点之间的距离，
这样只要有一个并查集树就能推断出树中所有节点之间的关系。
如果两个节点xy在一棵树上，而且距离根节点的距离之差是3的倍数，那么xy同类；如果d[x]-d[y]=1则x吃y；
*/

#include <iostream>
using namespace std;

const int N = 50010;
int n, k;
int p[N], d[N];
int ans = 0;

int root(int x){
    if(p[x] != x){          //这里无须担心p[x]!=x但p[x]是根节点的情况，因为根节点d[x]一定是0
        int r = root(p[x]);
        d[x] += d[p[x]];    //p[x]和d[x]路径压缩
        p[x] = r;
    }
    return p[x];
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) p[i] = i;
    while(k--){
        int t, x, y;
        cin >> t >> x >> y;
        if(x > n || y > n) ans++;
        else{
            int px = root(x), py = root(y);
            if(t == 1){
                if(px == py && (d[x] - d[y]) % 3) ans++;
                else if(px != py){
                    p[px] = py;
                    d[px] = d[y] - d[x];   // 修改d[px]满足关系 (d[x] + d[px] - d[y]) % 3 == 0
                }
            }else if(t == 2){
                if(px == py && (d[x] - d[y] - 1) % 3) ans++;   //括号必要，%和*/是同一优先级
                else if(px != py){
                    p[px] = py;
                    d[px] = d[y] - d[x] + 1;   // 修改d[px]满足关系 (d[x] + d[px] + 1 - d[y]) % 3 == 0
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}