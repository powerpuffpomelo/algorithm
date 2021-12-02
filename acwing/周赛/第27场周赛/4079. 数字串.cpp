// 因为数据范围小，所以可以采用暴力简单做法

#include <iostream>
#include <string>
using namespace std;

const int N = 1010;
int n, t;
string str;

int main(){
    for(int i = 1; i <= 1000; i++){
        str += to_string(i);  // 数字转字符串
    }
    cin >> t;
    while(t--){
        cin >> n;
        cout << str[n - 1] << endl;
    }
    return 0;
}