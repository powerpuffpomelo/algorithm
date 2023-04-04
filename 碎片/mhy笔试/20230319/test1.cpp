// 91.67%
#include <bits/stdc++.h>
using namespace std;

string str;

int main(){
    cin >> str;
    int n = str.size();
    int i = 0;
    for(; i < n - 1; i++){
        if(str[i] < str[i + 1]) break;
    }
    if(i != n - 1){
        swap(str[i], str[i + 1]);

    }else{
        swap(str[n - 2], str[n - 1]);
    }
    cout << str << endl;
    return 0;
}