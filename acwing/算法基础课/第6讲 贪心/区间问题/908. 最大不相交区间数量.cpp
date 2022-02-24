/* 代码和区间选点一样，如何证明
合理性：选出来的cnt个区间一定是没有交集的；
最优性：反证，假如存在更多的不相交区间(比如cnt+1个)，则区间选点至少cnt+1个才能都覆盖掉；可是我们已经证明了当前选出来的区间能被cnt个点覆盖
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, ans, ed = -2e9;
struct Range{
    int l,r;
}range[N];

bool cmp(Range a, Range b){
    return a.r < b.r;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> range[i].l >> range[i].r;
    sort(range, range + n, cmp);
    for(int i = 0; i < n; i++){
        if(ed < range[i].l){
            ed = range[i].r;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}