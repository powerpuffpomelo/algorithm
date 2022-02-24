#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
int n;
vector<PII> segs;

void merge_seg(vector<PII> &segs){   //这里直接修改原vector，也可以返回合并后新vector
    vector<PII> ans;
    sort(segs.begin(), segs.end());
    int st = -2e9, ed = -2e9;
    for(auto item : segs){
        if(item.first > ed){
            if(st != -2e9) ans.push_back({item.first, item.second});
            st = item.first;
            ed = item.second;
        }else{
            ed = max(ed, item.second);
        }
    }
    ans.push_back({st, ed});
    segs = ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    merge_seg(segs);
    cout << segs.size() << endl;
    
    return 0;
}