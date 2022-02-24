// ###################################################### 版本1 ###################################################### //

#include <vector>
#include <iostream>
using namespace std;

int n;
bool flag[7];
vector<int> temp;

void show(vector<int> temp){
    for(auto x : temp) printf("%d ", x);
    puts("");
}

void permute(int id, vector<int> temp){
    for(int i = 1; i <= n; i++){
        if(flag[i] == 1) continue;
        temp.push_back(i);
        flag[i] = 1;
        if(id == n){
            show(temp);
        }else{
            permute(id + 1, temp);
        }
        temp.pop_back();
        flag[i] = 0;
    }
}

int main(){
    cin >> n;
    permute(1, temp);
    return 0;
}

// ###################################################### 版本2 ###################################################### //

#include <iostream>
using namespace std;

const int N = 10;
int n;
int path[N];
bool flag[N];

void dfs(int u){
    if(u == n){
        for(int i = 0; i < n; i++) printf("%d ", path[i]);
        puts("");
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!flag[i]){
            path[u] = i;
            flag[i] = true;
            dfs(u + 1);
            flag[i] = false;
        }
    }
}

int main(){
    scanf("%d", &n);
    dfs(0);
    return 0;
}

// ###################################################### 版本3 ###################################################### //

#include <iostream>
using namespace std;

const int N = 10;
int n;
int path[N];

void dfs(int u, int state){
    if(u == n){
        for(int i = 0; i < n; i++) printf("%d ", path[i]);
        puts("");
        return;
    }
    for(int i = 0; i < n; i++){
        if(!(state >> i & 1)){
            path[u] = i + 1;
            dfs(u + 1, state + (1 << i));
        }
    }
}

int main(){
    scanf("%d", &n);
    dfs(0, 0);
    return 0;
}