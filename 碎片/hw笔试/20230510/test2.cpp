#include <bits/stdc++.h>
using namespace std;

const int N = 110;
vector<int> vecn;
string k;

int main(){
    string strm, strn;
    cin >> strm >> strn >> k;
    // for(int i = strm.size() - 1; i >= 0; i--) vecm.push_back(strm[i] - '0');
    for(int i = strn.size() - 1; i >= 0; i--) vecn.push_back(strn[i] - '0');
    int maxlen = (k == "*") ? 3 : 12;
    for(ing len = 3; len <= maxlen; len++){
        vector<int> vecm;
        for(int i = 0; i + len - 1 <= strm.size(); i++){
            for(int j = i + len - 1; j >= i; j--){
                vecm.push_back(strm[j] - '0');
            }
            vector<int> res;
            if(k == "+") res = add(vecm, vecn);
            else if(k == "-") res = sub(vecm, vecn);
            else if(k == "*") res = mul(vecm, vecn);
            if(check(res))
        }
    }
    return 0;
}