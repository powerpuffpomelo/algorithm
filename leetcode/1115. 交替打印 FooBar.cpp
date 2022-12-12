// ###################################################### 版本1 ###################################################### //
// 互斥锁+条件变量
class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool foo_done = false;
public:
    FooBar(int n) : n(n) {}

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&]() { return !foo_done; });
            printFoo();
            foo_done = true;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&]() { return foo_done; });
            printBar();
            foo_done = false;
            cv.notify_one();
        }
    }
};
