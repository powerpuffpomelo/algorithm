/*
010101组成的串，
最长的区间，两个区间，返回四个坐标
这两个区间的01数量相同*/

#include <bits/stdc++.h>
using namespace std;

string str;
int l1, r1, l2, r2;

void cal(string str){
    int n = str.size();
    for(int len = n - 1; len > 0; len--){
        unordered_map<int, int> se;
        int s = 0;
        for(int i = 0; i < len; i++){
            if(str[i] == '1') s++;
            else s--;
        }
        se[s] = 0;
        for(int i = 1; i + len - 1 < n; i++){
            if(str[i + len - 1] == '1') s++;
            else s--;
            if(str[i - 1] == '1') s--;
            else s++;
            if(se.count(s)){
                l1 = se[s], l2 = i;
                r1 = l1 + len - 1, r2 = l2 + len - 1;
                return;
            }else{
                se[s] = i;
            }
        }
    }
}

int main(){
    cin >> str;
    cal(str);
    cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << endl;
    return 0;
}