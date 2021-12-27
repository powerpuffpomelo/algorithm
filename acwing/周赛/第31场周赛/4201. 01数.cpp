// ###################################################### 版本1 ###################################################### //
// 我的初始做法，启发式
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> num;
int ans;

int main(){
    cin >> n;
    while(n){
        num.push_back(n % 10);
        n /= 10;
    }
    for(int i = num.size() - 1; i >= 0; i--){
        if(num[i] > 1){
            ans += int(pow(2, i + 1));
            break;
        }else if(num[i] == 1){
            ans += int(pow(2, i));
            if(!i) ans++;
        }else{
            if(!i) ans++;
        }
    }
    ans--;
    
    cout << ans << endl;
    
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 枚举每个二进制数，判断是否在范围内
#include <iostream>
#include <algorithm>
using namespace std; 

int n, ans;

int main(){
    cin >> n;
    for(int i = 1; i < (1 << 10); i++){
        int x = 0;
        for(int j = 0; j <= 9; j++){
            x = x * 10 + (i >> j & 1);
        }
        if(x <= n) ans++;
    }
    cout << ans << endl;
    return 0;
}