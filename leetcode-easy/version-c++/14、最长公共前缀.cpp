/*
    编写一个函数来查找字符串数组中的最长公共前缀。
    如果不存在公共前缀，返回空字符串 ""。
    

    示例 1：
        输入：strs = ["flower","flow","flight"]
        输出："fl"

    示例 2：
        输入：strs = ["dog","racecar","car"]
        输出：""
        解释：输入不存在公共前缀。
    

    提示：
        1 <= strs.length <= 200
        0 <= strs[i].length <= 200
        strs[i] 仅由小写英文字母组成
*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 字符串个数
        int rows = strs.size();
        // 第一个字符串中的字符个数
        int cols = strs[0].length();
        // 一列一列比较每个字符串对应的字符
        for (int col = 0; col < cols; col++) {
            for (int row = 1; row < rows; row++) {
                string curStr = strs[row];
                string preStr = strs[row - 1];
                // 如果已经遍历完最短的字符串，或者有公共前缀不相同，返回子串
                if (col >= curStr.length() || col >= preStr.length() || curStr[col] != preStr[col]) {
                    // 这里之所以使用col，是因为进入这里就表示长度为col+1的公共前缀不存在，自然就返回长度为col的子串
                    return strs[row].substr(0, col);
                }
            }
        }
        return strs[0];
    }
};