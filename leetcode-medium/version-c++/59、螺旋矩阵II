/**
* [59]螺旋矩阵 II
*
*
*https://leetcode-cn.com/problems/spiral-matrix-ii/description/
*
*
* 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
*  
* 示例 1：
* 输入：n = 3
* 输出：[[1,2,3],[8,9,4],[7,6,5]]
* 
* 示例 2：
* 输入：n = 1
* 输出：[[1]]
* 
*  
* 提示：
* 1 <= n <= 20
* 
* 
*/
#include <iostream>
#include <vector>
#include <functional>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startX = 0;
        int startY = 0;
        int num = 1;
        int loop = n / 2;
        int i;
        int j;
        int offset = 1;
        while (loop--) {
            i = startX;
            j = startY;
            for (; j < n - offset; j++) {
                res[i][j] = num++;
            }
            for (; i < n - offset; i++) {
                res[i][j] = num++;
            }
            for (; j > startY; j--) {
                res[i][j] = num++;
            }
            for (; i > startX; i--) {
                res[i][j] = num++;
            }
            startX++;
            startY++;
            offset++;
        }
        if (n % 2 == 1) {
            res[startX][startY] = num;
        }
        return res;
    }
};
