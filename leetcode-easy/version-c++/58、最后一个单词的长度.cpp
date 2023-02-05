/*
    给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。

    单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
    

    示例 1：
        输入：s = "Hello World"
        输出：5
        解释：最后一个单词是“World”，长度为5。

    示例 2：
        输入：s = "   fly me   to   the moon  "
        输出：4
        解释：最后一个单词是“moon”，长度为4。

    示例 3：
        输入：s = "luffy is still joyboy"
        输出：6
        解释：最后一个单词是长度为6的“joyboy”。
    

    提示：
        1 <= s.length <= 10^4
        s 仅有英文字母和空格 ' ' 组成
        s 中至少存在一个单词
*/
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int indx = s.length() - 1;
        // 从字符串最后一个字符反向遍历，首先找到最后一个非空子串的最后一个字符！
        while (s[indx] == ' ') {
            indx--;
        }
        int len = 0;
        // 此时反向遍历记录字串长度
        while (indx >= 0 && s[indx] != ' ') {
            len++;
            indx--;
        }
        return len;
    }
};