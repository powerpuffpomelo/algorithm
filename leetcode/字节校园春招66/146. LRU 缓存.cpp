class LRUCache {
    struct node{
        int k, v;
        node *left, *right;
        node(int _k, int _v): k(_k), v(_v), left(nullptr), right(nullptr) {}
    }*l, *r;
    int n;
    unordered_map<int, node*> mp;
public:
    void remove(node* p){
        p->left->right = p->right;
        p->right->left = p->left;
    }
    
    void insert(node* p){
        p->left = l;
        p->right = l->right;
        l->right = p;
        p->right->left = p;
    }
    LRUCache(int capacity) {
        n = capacity;
        l = new node(-1, -1), r = new node(-1, -1);
        l->right = r, r->left = l;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        auto p = mp[key];
        remove(p);
        insert(p);
        return p->v;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            auto p = mp[key];
            p->v = value;
            remove(p);
            insert(p);
        }else{
            auto p = new node(key, value);
            insert(p);
            mp[key] = p;
            if(mp.size() > n){
                p = r->left;
                remove(p);
                mp.erase(p->k);   // 要删除key才行
                //mp[p->k] = nullptr;   // 不能这么写，因为这个key依然存在，value是nullptr
                delete(p);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */