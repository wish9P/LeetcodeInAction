/*
    给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。

 
    示例 1：
        输入:a = "11", b = "1"
        输出："100"

    示例 2：
        输入：a = "1010", b = "1011"
        输出："10101"
    

    提示：
        1 <= a.length, b.length <= 10^4
        a 和 b 仅由字符 '0' 或 '1' 组成
        字符串如果不是 "0" ，就不含前导零
*/
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        // 反转字符串，方便进行加法运算
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = max(a.size(), b.size());
        int carry = 0;
        int i = 0;
        while (i < n || carry > 0) {
            int val = carry;
            // 遍历a和b的字符，若两者之和没有进位，carry为0，有则carry为1
            val += i < a.size() ? (a[i] - '0') : 0;
            val += i < b.size() ? (b[i] - '0') : 0;
            // string 也有 push_back，表示在最后插入一个字符；pop_back，表示从最后删除一个字符
            res.push_back((val % 2) ? '1' : '0');
            carry = val / 2;
            i++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};