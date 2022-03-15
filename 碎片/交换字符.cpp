/*
阿里笔试：给出一个字符串，可以选择任意两个不同位置的字符进行两两交换，且只能交换一次，
问可以得到多少不同的字符串
思路：组合数学，所有交换的方案数 - 维持不变的方案数
然后，维持不变的方案还是要+1的，就是说去重，但要留一个
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
int main(){
    string s;
    cin >> s;
    lld n = s.size();
    map<char, lld> cnt;
    for(auto c : s) cnt[c]++;
    lld ans = n * (n - 1) / 2;    // 所有交换的方案数
    for(auto [k, v] : cnt) ans -= v * (v - 1) / 2;  // 一些效果相同的交换
    // 特殊情况：如果字符串中存在两个相同数字，那么答案需要+1，因为效果相同的交换也是一种交换，就是说交换会得到原串。
    // 但如果不含相同数字比如abc，由于题意必须交换一次，它是得不到abc的，所以不+1
    for(auto [k, v] : cnt){
        if(v >= 2){
            ans++;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}