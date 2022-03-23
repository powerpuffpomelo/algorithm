#include <bits/stdc++.h>
using namespace std;

string str, ans;
map<string, int> cnt;    // 存储各个元素数量

map<string, int> cal(string str){
    map<string, int> cnt;
    for(int i = 0; i < str.size();){
        if(str[i] >= 'A' && str[i] <= 'Z'){    // 如果遇到普通元素就计算个数，并在map中添加
            string elm;
            elm += str[i];
            int k = i + 1;
            if(k < str.size() && str[k] >= 'a' && str[k] <= 'z') elm += str[k++];
            int num = 0;
            while(k < str.size() && str[k] >= '0' && str[k] <= '9') num = num * 10 + str[k++] - '0';
            if(!num) num = 1;
            i = k;
            cnt[elm] += num;
        }else if(str[i] == '[' || str[i] == '('){     // 如果遇到左括号的话就找到其对应的右括号
            int k = i + 1;
            int s = 0;
            while(s >= 0){
                if(str[k] == '[' || str[k] == '(') s++;
                else if(str[k] == ']' || str[k] == ')') s--;
                k++;
            }
            auto temp_cnt = cal(str.substr(i + 1, k - i - 2));    // 递归计算出括号内部字符串的map
            int num = 0;
            while(k < str.size() && str[k] >= '0' && str[k] <= '9') num = num * 10 + str[k++] - '0';
            if(!num) num = 1;
            for(auto item : temp_cnt){
                cnt[item.first] += item.second * num;     // 将括号内字符串的计数 添加到现有map中
            }
            i = k;
        }
    }
    return cnt;
}

int main(){
    cin >> str;
    cnt = cal(str);
    for(auto item : cnt){
        ans += item.first;
        ans += to_string(item.second);
    }
    cout << ans << endl;
    return 0;
}