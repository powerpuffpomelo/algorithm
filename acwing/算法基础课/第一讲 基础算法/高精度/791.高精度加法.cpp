// ###################################################### 版本1 ###################################################### //

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string a, b;
vector<int> A, B; 

vector<int> add(vector<int> &A, vector<int> &B){
    if(A.size() < B.size()) return add(B, A);
    int t = 0;
    vector<int> C;
    for(int i=0; i< A.size(); i++){
        t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t) C.push_back(1);
    return C;
}

int main(){
    cin >> a >> b;
    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');  // 字符转数字要-'0'
    for(int i = b.size()-1; i >= 0; i--) B.push_back(b[i] - '0');
    auto C = add(A, B);
    for(int i = C.size()-1; i>=0; i--) printf("%d", C[i]);
    return 0;
}

// ###################################################### 版本2 ###################################################### //

#include <iostream>
#include <string>
using namespace std;

const int N = 1e5 + 10;
string stra, strb;
int a[N], b[N];
int res[N];

int main(){
    cin >> stra >> strb;
    for(int i = 0; i < stra.size(); i++) a[i] = stra[stra.size() - i - 1] - '0';
    for(int i = 0; i < strb.size(); i++) b[i] = strb[strb.size() - i - 1] - '0';
    int tt = 0;
    int i = 0;
    for(; i < stra.size() || i < strb.size() || tt; i++){
        tt = a[i] + b[i] + tt;
        res[i] = tt % 10;
        tt /= 10;
    }
    for(int j = i - 1; j >= 0; j--) cout << res[j];
    return 0;
}