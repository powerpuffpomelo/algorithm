// ###################################################### 版本1 ###################################################### //
// dfs，有待继续理解
using PDD = pair<double,double>;
#define x first
#define y second
const double EPS = 1e-6;
class Solution {
public:
    PDD dfs(TreeNode* root) {
        // return {在该点用双核的开销 , 在该点用单核的开销} 
        if(!root) return {0,0};// 空节点开销都为 0
        auto cl = dfs(root->left);
        auto cr = dfs(root->right);
        double one = cl.y + cr.y + root->val;// 单核的情况
        double two = root->val;// 双核的情况
        double a = -(cl.y - cl.x);
        double b = (cr.y - cr.x);
        double t_ = (cr.y - cl.y) / 2;// 理想取最小值的 t 值
        if(t_ >= a && t_ <= b) two += (cl.y + cr.y) / 2;// t_ 在区间中的情况
        else if(t_ < a) two += max(cl.y + a,cr.y - a);
        else  two += max(cl.y + b,cr.y - b);
        return {two,one};
    }
    double minimalExecTime(TreeNode* root) {
        if(!root) return 0;
        return dfs(root).x;
    }
};