#include <bits/stdc++.h>
using namespace std;

/*
struct node{
    int val;
    node *left, *right;
    node(int _val): val(_val), left(nullptr), right(nullptr){}
}*root;

node* jingzi(node* root){
    if(!root) return nullptr;
    node *ll = root->left;
    node *rr = root->right;
    root->left = jingzi(rr);
    root->right = jingzi(ll);
    return root;
}
*/

unordered_map<string, int> cnt;   // 计数
vector<string> vv;
bool inp = false;  // 在括号里

unordered_map<string, int> cal(string str){
    for(int i = 0; i < str.size(); i++){
        // 读入普通元素
        if(str[i] >= 'A' && str[i] <= 'Z'){
            string temp;
            temp += str[i++];
            if(str[i] >= 'a' && str[i] <= 'z'){
                temp += str[i];
                i++;
            }
            // i落到下一个位置了
            i--;
            if(!inp){
                cnt[temp]++;
            }else{
                int num = 0;
                if(str[i + 1] >= '0' && str[i + 1] <= '9'){
                    i++;
                    while(str[i] >= '0' && str[i] <= '9'){
                        num = num * 10 + str[i] - '0';
                    }
                }
                i--;
                if(num){
                    for(int k = 0; k < num; k++) vv.push_back(temp);
                }else{
                    vv.push_back(temp);
                }
                
            }
            
        }
        else if(str[i] == '('){
            inp = true;
        }else if(str[i] == ')'){
            inp = false;
            int num = 0;
            i++;
            while(i < str.size() && str[i] >= '0' && str[i] <= '9'){
                num = num * 10 + str[i] - '0';
                i++;
            }
            if(!num) num = 1;
            i--;
            for(int k = 0; k < vv.size(); k++){
                string elm = vv[k];   // 括号里的元素
                cnt[elm] += num;
            }
            vv.clear();
        }
    }
    return cnt;
}

int main(){
    string ss = "Cu(CaS)14";
    auto mm = cal(ss);
    for(auto item : mm){
        cout << item.first << ' ' << item.second << endl;
    }
    return 0;
}