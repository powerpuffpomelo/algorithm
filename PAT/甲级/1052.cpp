#include <cstdio>
#include <algorithm>
using namespace std;

struct Node {
	int key;
	int add;
	int next;
	bool inlist=0;
}node[100000];

int n, head;
int add, key, p;
int cnt = 0;

bool cmp(Node a,Node b) {
	if (a.inlist ==0 || b.inlist==0) return a.inlist > b.inlist;
	if (a.inlist == 1 && b.inlist == 1) return a.key < b.key;
}

int main() {
	scanf("%d%d", &n, &head);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &add, &key, &p);
		node[add].key = key;
		node[add].next = p;
		node[add].add = add;
	}
	p = head;
	while (p != -1) {
		node[p].inlist = 1;
		p = node[p].next;
		cnt++;
	}
	if (cnt == 0) {
		printf("0 -1");
		return 0;
	}
	sort(node, node + 100000, cmp);
	
	printf("%d %05d\n", cnt, node[0].add);
	for (int i = 0; i < cnt; i++ ) {
		printf("%05d %d ", node[i].add, node[i].key);
		if (i==cnt-1) {
			printf("-1\n");
			break;
		}
		else {
			printf("%05d\n", node[i + 1].add);
		}
	}
	return 0;
}