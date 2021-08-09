#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string a;
int b;
vector<int> A;

// A / b, 余数r
vector<int> div(vector<int> &A, int b, int &r){
    vector<int> C;
    r = 0; 
    for(int i = A.size() - 1; i >= 0; i--){
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());   //用reverse函数需要#include <algorithm>
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main(){
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    int r;
    auto C = div(A, b, r);
    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    cout << endl << r << endl;
    return 0;
}