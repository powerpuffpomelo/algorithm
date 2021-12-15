/*

001~abc-1, 999

abc
    1. num[i] < x, 0
    2. num[i] == x, 0~efg
    3. num[i] > x, 0~999

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e8 + 10;
int a, b;

int get(vector<int> num, int l, int r){
    int ans = 0;
    for(int i = l; i >= r; i--){
        ans = ans * 10 + num[i];
    }
    return ans;
}

int power10(int i){
    int ans = 1;
    while(i--){
        ans *= 10;
    }
    return ans;
}

int count(int a, int i){   // 计算从1到整数a，一共出现过多少次数字i
    int ans = 0;
    vector<int> num;   // 存放整数a的每一位，方便计算
    int t = a;
    while(t){
        num.push_back(t % 10);
        t /= 10;
    }
    int len = num.size();
    for(int pos = 0; pos < len - !i; pos++){  //从末位到首位，0不可能在首位
        ans += (max(get(num, len - 1, pos + 1) - !i, 0)) * power10(pos);  // 如果是0的话，pos之前不能都是0，不然pos处就首位是0了
        if(num[pos] > i) ans += power10(pos);
        else if(num[pos] == i){
            ans += get(num, pos - 1, 0) + 1;
        }
    }
    return ans;
}

int main(){
    while(true){
        cin >> a >> b;
        if(!a) return 0;
        if(a > b) swap(a, b);
        for(int i = 0; i <= 9; i++){
            cout << count(b, i) - count(a - 1, i) << ' ';
        }
        cout << endl;
    }
    return 0;
}