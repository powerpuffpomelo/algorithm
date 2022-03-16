#include<bits/stdc++.h>
using namespace std;

void title(vector<int> &vv){
    vector<int> temp;
    for(int e : vv){
        if(e > temp.size()){
            while(e > temp.size()) temp.push_back(1);
        }else{
            while(e < temp.size()) temp.pop_back();
            temp[e - 1]++;
            for(int i = e; i < temp.size(); i++){
                temp[i] = 1;
            }
        }
        for(int i = 0; i < temp.size(); i++){
            cout << temp[i];
            if(i != temp.size() - 1) cout << '.';
        }
        cout << endl;
    }
}

int main(){
    vector<int> vv;
    vv = {2, 3, 1, 4};
    title(vv);
    return 0;
}