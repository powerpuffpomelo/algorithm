// ###################################################### 版本1 ###################################################### //
// string对顶栈
class TextEditor {
public:
    string s, t;
    TextEditor() {
        s = t = "";
    }
    
    void addText(string text) {
        s += text;
    }
    
    int deleteText(int k) {
        k = min(k, int(s.size()));
        for(int i = 0; i < k; i++) s.pop_back();
        return k;
    }
    
    string cursorLeft(int k) {
        k = min(k, int(s.size()));
        for(int i = 0; i < k; i++){
            t.push_back(s.back());
            s.pop_back();
        }
        string ans(s.end() - min(10, int(s.size())), s.end());  // 迭代器初始化string
        return ans;
    }
    
    string cursorRight(int k) {
        k = min(k, int(t.size()));
        for(int i = 0; i < k; i++){
            s.push_back(t.back());
            t.pop_back();
        }
        string ans(s.end() - min(10, int(s.size())), s.end());
        return ans;
    }
};


// ###################################################### 版本2 ###################################################### //
// 自定义双向链表
struct node{
    char c;
    node *prev, *next;
    node(char _c): c(_c) {}
};

class TextEditor {
private:
    node *st, *ed, *cur;

    string get_left_string(int k){
        string ret;
        auto p = cur;
        for(; k > 0 && p != st; k--){
            ret += p->c;
            p = p->prev;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

public:
    TextEditor() {
        st = new node('!');
        ed = new node('!');
        st->next = ed;
        ed->prev = st;
        cur = st;
    }
    
    void addText(string text) {
        for(char c : text){
            auto t = new node(c);
            t->next = cur->next;
            cur->next->prev = t;
            t->prev = cur;
            cur = cur->next = t;
        }
    }
    
    int deleteText(int k) {
        int num = 0;
        for(; k > 0 && cur != st; k--){
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            cur = cur->prev;
            num++;
        }
        return num;
    }
    
    string cursorLeft(int k) {
        for(; k > 0 && cur != st; k--){
            cur = cur->prev;
        }
        return get_left_string(10);
    }
    
    string cursorRight(int k) {
        for(; k > 0 && cur->next != ed; k--){
            cur = cur->next;
        }
        return get_left_string(10);
    }
};