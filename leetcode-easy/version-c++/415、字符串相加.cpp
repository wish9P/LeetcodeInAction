/*
    给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。

    你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
    

    示例 1：
        输入：num1 = "11", num2 = "123"
        输出："134"

    示例 2：
        输入：num1 = "456", num2 = "77"
        输出："533"

    示例 3：
        输入：num1 = "0", num2 = "0"
        输出："0"


    提示：
        1 <= num1.length, num2.length <= 10^4
        num1 和num2 都只包含数字 0-9
        num1 和num2 都不包含任何前导零
*/
#include <string>
#include <algorithm>
using namespace std;

// O(max(n1, n2))
class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res;
        int len = min(num1.size(), num2.size());
        int sign = 0;
        for (int i = 0; i < len; ++i) {
            int temp = sign + (num1[i] - '0') + (num2[i] - '0');
            res += to_string(temp % 10);
            sign = temp / 10;
        }
        while (num1.size() > len) {
            int temp = sign + (num1[len++] - '0');
            res += to_string(temp % 10);
            sign = temp / 10;
        }
        while (num2.size() > len) {
            int temp = sign + (num2[len++] - '0');
            res += to_string(temp % 10);
            sign = temp / 10;
        }
        if (sign != 0) {
            res += to_string(sign);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// O(max(n1, n2))
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans.push_back('0' + result % 10);
            add = result / 10;
            i -= 1;
            j -= 1;
        }
        // 计算完以后的答案需要翻转过来
        reverse(ans.begin(), ans.end());
        return ans;
    }
};