/*
    给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

    请必须使用时间复杂度为 O(log n) 的算法。

    
    示例 1:
        输入: nums = [1,3,5,6], target = 5
        输出: 2

    示例 2:
        输入: nums = [1,3,5,6], target = 2
        输出: 1

    示例 3:
        输入: nums = [1,3,5,6], target = 7
        输出: 4
    

    提示:
        1 <= nums.length <= 10^4
        -10^4 <= nums[i] <= 10^4
        nums 为 无重复元素 的 升序 排列数组
        -10^4 <= target <= 10^4
*/
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int sum = nums[mid];
            if(sum < target) {
                left = mid + 1;
            } else if(sum > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return left;    // 除法都是取整，结果都偏左，若是目标值不存在于数组中，要插入的索引值就是mid+1，就是left！
    }
};