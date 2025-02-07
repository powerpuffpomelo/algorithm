// 单调队列
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, k, x;
int arr[N], q[N], front, rear;

void init(){ // front指向队首元素的前一位，rear指向队尾元素
    front = -1, rear = -1;
}

bool empty(){
    return front == rear ? true : false;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    // 窗口内最小值
    init();
    for(int i = 0; i < n; i++){
        if(!empty() && q[front + 1] < i - k + 1) front++;  //判断队首元素是否在窗口范围内
        while(!empty() && arr[q[rear]] >= arr[i]) rear--;  //本题优化的关键思路：如果新进入窗口的元素比窗口内已有元素x要小，那么x永远无法输出，可以直接丢弃x
        q[++rear] = i;  // 本题关键思路之二：队列内存放的是索引，而非数值大小。这样才能知道小数值出窗口了没有
        if(i >= k - 1) cout << arr[q[front + 1]] << ' ';
    }
    cout << endl;
    
    // 窗口内最大值
    init();
    for(int i = 0; i < n; i++){
        if(!empty() && q[front + 1] < i - k + 1) front++;
        while(!empty() && arr[q[rear]] <= arr[i]) rear--;
        q[++rear] = i;
        if(i >= k - 1) cout << arr[q[front + 1]] << ' ';
    }
    
    return 0;
}