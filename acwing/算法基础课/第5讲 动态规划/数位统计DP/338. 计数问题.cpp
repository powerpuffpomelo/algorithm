/*
abcdefg，依次考虑某个数字在某位上出现次数，假如考虑x在d这一位的出现次数

001~abc-1, 999

abc
    1. num[i] < x, 0
    2. num[i] == x, 0~efg
    3. num[i] > x, 0~999

*/

// ###################################################### 版本1 ###################################################### //
// 
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
    while(cin >> a >> b, a){   // 逗号表达式 从左往右依次执行语句，并返回最后一个语句的结果
        if(a > b) swap(a, b);
        for(int i = 0; i <= 9; i++){
            cout << count(b, i) - count(a - 1, i) << ' ';
        }
        cout << endl;
    }
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 
#include <bits/stdc++.h>
using namespace std;

int a, b;

int power10(int x){
    int ret = 1;
    while(x--) ret *= 10;
    return ret;
}

int get(vector<int>& num, int l, int r){
    int ret = 0;
    for(int i = l; i >= r; i--){
        ret = ret * 10 + num[i];
    }
    return ret;
}

int count(int a, int x){
    // 从1到a中，出现了多少次x这个数字
    vector<int> num;
    while(a){
        num.push_back(a % 10);
        a /= 10;
    }
    int len = num.size();
    int ret = 0;
    for(int pos = 0; pos < len - !x; pos++){  // 0不可能在最高位
        if(pos != len - 1){
            ret += (get(num, len - 1, pos + 1) - !x) * power10(pos);
        }
        if(num[pos] == x) ret += get(num, pos - 1, 0) + 1;
        else if(num[pos] > x) ret += power10(pos);
    }
    return ret;
}

int main(){
    while(cin >> a >> b, a || b){
        if(a > b) swap(a, b);
        for(int i = 0; i < 10; i++){
            cout << count(b, i) - count(a - 1, i) << ' ';
        }
        cout << endl;
    }
    return 0;
}