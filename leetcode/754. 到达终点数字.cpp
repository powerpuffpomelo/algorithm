// ###################################################### 版本1 ###################################################### //
// 找到一个最小的k，使得前k个数的和 1+2+...+k >= target ，且sum与target奇偶性相同即可。
// target正负对称，只考虑正数情况即可；
// 如果 1+2+...+k >= target，那么需要调整部分正负号，比如a1到ai变负，那么 sum - 2(a1+..+ai) = target，即a1+...+ai = (sum - target) / 2，因此(sum - target) / 2 需要是整数
// 由于1到n这n个数一定可以凑出来1到sum n中间的任何一个数，所以必然能找到。
/*
负位置与正位置是对应的，统一按照正位置考虑。
假设每次都是向右移动，当位置大于等于 target 的时候停止。
此时如果位置与 target 的差距为偶数，则显然可以将某一步改为向左走，即可到达 target。
如果差距为奇数，则需要再向后走，直到出现位置为偶数的情况（不会超过 4 次）。*/
// 时间复杂度O(sqrt(target))
class Solution {
public:
    int reachNumber(int target) {
        int k = 0, sum = 0;
        target = abs(target);
        while(sum < target || (sum - target) % 2){
            k++;
            sum += k;
        }
        return k;
    }
};
