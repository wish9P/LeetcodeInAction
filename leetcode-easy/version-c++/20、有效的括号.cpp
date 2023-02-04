/*
    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

    有效字符串需满足：
        左括号必须用相同类型的右括号闭合。
        左括号必须以正确的顺序闭合。
        每个右括号都有一个对应的相同类型的左括号。
    

    示例 1：
        输入：s = "()"
        输出：true

    示例 2：
        输入：s = "()[]{}"
        输出：true

    示例 3：
        输入：s = "(]"
        输出：false
    

    提示：
        1 <= s.length <= 104
        s 仅由括号 '()[]{}' 组成
*/
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    /* 返回右括号对应的左括号 */
    char leftOf(char c) {
        if (c == '}') {
            return '{';
        } else if (c == ']') {
            return '[';
        } else {
            return '(';
        }
    }

    bool isValid(string s) {
        stack<char> left;
        for (char c: s) {
            // 如果是左括号就入栈
            if (c == '[' || c == '(' || c == '{') {
                left.push(c);
            } else {
                // 如果是右括号，当栈中有左括号且与它相对应时，将对应的左括号出栈，否则说明括号无效！
                if (!left.empty() && leftOf(c) == left.top()) {
                    left.pop();
                } else {
                    return false;
                }
            }
        }
        // 遍历完s只代表右括号匹配完毕，还要判断栈中左括号是否都匹配完成！
        return left.empty();
    }
};