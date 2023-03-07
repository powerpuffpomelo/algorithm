#include <bits/stdc++.h>
using namespace std;

int n;
vector<queue<int>> veq;
string str;

int main(){
    cin >> n;
    veq = vector<queue<int>>(6);
    while(n--){
        cin >> str;
        if(str == "a"){
            int num, x;
            cin >> num >> x;
            veq[x].push(num);
        }else{
            for(int i = 1; i <= 5; i++){
                if(veq[i].size()){
                    cout << veq[i].front() << endl;
                    veq[i].pop();
                    break;
                }
            }
        }
    }
    return 0;
}