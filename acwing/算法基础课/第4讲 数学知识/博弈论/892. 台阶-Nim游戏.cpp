/*
只需判断奇数级台阶异或起来得到的x是否是0
对于对手的每次操作：
 - 如果对手从奇数级搬了一些石子到偶数级，此时x≠0了，那么参考nim游戏，先手方一定可以一步操作让x=0
 - 如果对手从偶数级搬了一些石子到奇数级，那么对手搬了多少，先手方就原样把对手搬的数量再往下搬一级，这样保持奇数级没有变化

yxc：抓住一点来理解会容易一些：必败态是所有奇数阶台阶的异或和为0，其余的为必胜态。
因为每一个这种定义的必败态不论怎么操作，对手都可以再把你转移回必败态；
反之任何一个必胜态，一定存在一种转移到必败态的方式。

关于为什么偶数级台阶异或和不行：
 - 该方法可以保障奇数级台阶的异或和为0是留给对手的；另外，偶数台阶上的石子要想移动到地面，必然需要经过偶数次移动
 - 因为第一阶拿到地面要拿一次，第二阶拿两次，第三阶拿三次…所以可以看成第二阶有两堆石子，第三阶有三堆....
   因为偶数阶石子为偶数堆，所以异或为0，奇数阶异或后就是原本石子数目，所以可以把原本所有奇数阶的石子进行异或，得到的就是答案
*/
// ###################################################### 版本1 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

int n, a;
int ans;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a;
        if(i % 2) ans ^= a;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}