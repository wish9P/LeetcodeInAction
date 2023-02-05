/*
    给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

    由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

    注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。


    示例 1：
        输入：x = 4
        输出：2

    示例 2：
        输入：x = 8
        输出：2
        解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
    

    提示：
        0 <= x <= 2^31 - 1
*/
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int res = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long num = static_cast<long long>(mid);
            long long sum = num * num;
            if (sum <= x) {
                res = mid;  // 关键，保留上一个平方小于等于x的值，此次轮回大于就表示上一次结果就是正解！
                left = mid + 1;
            } else if (sum > x) {
                right = mid - 1;
            }
        }
        return res;
    }
};