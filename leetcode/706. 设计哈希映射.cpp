// ###################################################### 版本1 ###################################################### //
// 我的初版
class MyHashMap {
public:
    vector<int> hash;
    MyHashMap() {
        hash = vector<int>(1e6 + 10, -1);
    }
    
    void put(int key, int value) {
        hash[key] = value;
    }
    
    int get(int key) {
        return hash[key];
    }
    
    void remove(int key) {
        hash[key] = -1;
    }
};