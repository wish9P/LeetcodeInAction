/*
    给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

    最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

    你可以假设除了整数 0 之外，这个整数不会以零开头。

    
    示例 1：
        输入：digits = [1,2,3]
        输出：[1,2,4]
        解释：输入数组表示数字 123。

    示例 2：
        输入：digits = [4,3,2,1]
        输出：[4,3,2,2]
        解释：输入数组表示数字 4321。

    示例 3：
        输入：digits = [0]
        输出：[1]
    

    提示：
        1 <= digits.length <= 100
        0 <= digits[i] <= 9
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            // 判断当前数加1之后是否为10，不是则直接返回digits，是则继续遍历下去
            digits[i] = (digits[i] + 1) % 10;
            if (digits[i] != 0) {
                return digits;
            }
        }
        // 遍历完成之后，如果没有返回digits，而是走到了这里，说明其中所有的数都变成了0。这里处理进一位的情况！
        vector<int> res(n + 1);
        res[0] = 1;
        return res;
    }
};