// ###################################################### 版本2 ###################################################### //
// vector
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

vector<int> get_divisors(int x){
    vector<int> ret;
    for(int i = 1; i <= x / i; i++){
        if(x % i == 0){
            ret.push_back(i);
            if(x / i != i) ret.push_back(x / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main(){
    scanf("%d", &n);
    while(n--){
        int a;
        scanf("%d", &a);
        vector<int> divisors = get_divisors(a);
        for(auto x : divisors){
            printf("%d ", x);
        }
        puts("");
    }
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版，set
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int n;

int main(){
    scanf("%d", &n);
    while(n--){
        int a;
        scanf("%d", &a);
        set<int> ss;
        for(int i = 1; i <= a / i; i++){
            if(a % i == 0){
                ss.insert(i);
                ss.insert(a / i);
            } 
        }
        //sort(ss.begin(), ss.end());  // 集合需要排序吗？看样子set自动从小到大？
        for(int i : ss) printf("%d ", i);
        puts("");
    }
    return 0;
}