/*
每堆的数量异或起来的结果 a1 ^ a2 ^ ... ^ an = x
若x≠0则必胜，若x=0则必败
≠0一定可以通过一步操作变成=0：
    a1 ^ a2 ^ ... ^ an ^ x = 0 
    假设x的二进制表示中最高的一位在第k位，则a1到an中必然存在一个ai的第k位是1
    则ai^x < ai （因为把第k位从1变成0了）
    所以只要从ai那堆拿走(ai - (ai^x)) 这么多，把ai变成ai^x，就可以了
=0不论怎样操作都会变成≠0：
    反证法，比如把ai变成aj能保持=0：
    a1 ^ a2 ^ ... ^ ai ^ ... ^ an = 0  
    a1 ^ a2 ^ ... ^ aj ^ ... ^ an = 0 
    两式一起异或，两两相消，只剩ai ^ aj = 0，则ai = aj
*/
// ###################################################### 版本1 ###################################################### //
// 
#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main(){
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        ans ^= x;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}