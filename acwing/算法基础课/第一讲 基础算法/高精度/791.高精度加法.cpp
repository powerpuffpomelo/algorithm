#include <iostream>
#include <vector>
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
