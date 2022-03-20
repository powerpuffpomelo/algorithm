/*
两个只包含01的串a和b，输入整数k，b[i] = a[i-k] | a[i+k]，现在给定b和k，要求还原a，因为a可能有很多，输入字典序最小的那一个
这个代码只过了72%样例，不太对
刚刚想到，如果b[i] == 1，不能直接a[i + k] = 1，因为如果a[i + k] = 1的话，b[i + 2k] 也一定=1，要根据条件来判断！
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int k;
string strb;

int main(){
    cin >> k >> strb;
    int n = strb.size();
    string stra;
    for(int i = 0; i < n; i++) stra += '0';
    // 希望尽可能多地把a变成0，而且0要尽可能靠前
    for(int i = 0; i < n; i++){
        if(strb[i] == '1'){
            if(i - k >= 0 && stra[i - k] == '1') continue;
            if(i + k < n) stra[i + k] = '1';
            else stra[i - k] = '1';
        }
    }
    cout << stra << endl;
    return 0;
}
