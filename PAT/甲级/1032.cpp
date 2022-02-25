// ###################################################### 版本2 ###################################################### //
// 稍微近些的我
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
struct node{
    char c;
    bool vis;
    int next;
}nodes[N];
int n, a1, a2;

int main(){
    cin >> a1 >> a2 >> n;
    for(int i = 0; i < n; i++){
        int a, ne;
        char c;
        cin >> a >> c >> ne;
        nodes[a].c = c;
        nodes[a].next = ne;
    }
    for(int i = a1; i != -1; i = nodes[i].next){
        nodes[i].vis = true;
    }
    int ans = -1;
    for(int i = a2; i != -1; i = nodes[i].next){
        if(nodes[i].vis){
            ans = i;
            break;
        }
    }
    if(ans != -1) printf("%05d\n", ans);
    else printf("-1\n");
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 以前的我
#include <cstdio>

struct Node {
	int nextadd;
	char data;
	bool vis = 0;
}node[100000];
int n;
int a1, a2;
int temp;

int ans=-1;

int main() {
	scanf("%d%d%d", &a1, &a2, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		scanf("%*c%c%d", &node[temp].data, &node[temp].nextadd);
	}
	int p1 = a1, p2 = a2;
	while (p1 != -1) {
		node[p1].vis = 1;
		p1 = node[p1].nextadd;
		//printf("%d\n", p1);
	}
	while (p2!=-1&&node[p2].vis==0) {
		p2 = node[p2].nextadd;
	}
	if (p2 == -1) {
		printf("-1\n");
		return 0;
	}
	printf("%05d\n", p2);
	return 0;
}