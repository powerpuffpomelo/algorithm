#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
string str;
int n;
vector<int> diff;

int main(){
    cin >> str;
    n = str.size();
    str = ' ' + str;
    for(int i = 1, j = n; i < j; i++, j--){
        if(str[i] != str[j]) diff.push_back(i);
    }
    if(diff.size() == 0){
        // 从头开始把一处改到最小
        for(int i = 1; i <= n / 2; i++){
            if(str[i] != 'a'){
                str[i] = str[n - i + 1] = 'a';
                break;
            }
        }
    }else if(diff.size() == 1){
        // 该处改到最小
        int i = diff[0], j = n - i + 1;
        str[i] = str[j] = 'a';
    }else{
        // 两处分别改到相对小的字母
        for(int a = 0; a < 2; a++){
            int i = diff[0], j = n - i + 1;
            str[i] = str[j] = min(str[i], str[j]);
        }
    }
    cout << str.substr(1) << endl;
    return 0;
}