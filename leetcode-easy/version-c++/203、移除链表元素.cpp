/**
* [203]移除链表元素
*
*
*https://leetcode-cn.com/problems/remove-linked-list-elements/description/
*
*
* 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
*  
* 示例 1：
* 输入：head = [1,2,6,3,4,5,6], val = 6
* 输出：[1,2,3,4,5]
* 
* 示例 2：
* 输入：head = [], val = 1
* 输出：[]
* 
* 示例 3：
* 输入：head = [7,7,7,7], val = 7
* 输出：[]
* 
*  
* 提示：
* 列表中的节点数目在范围 [0, 104] 内
* 1 <= Node.val <= 50
* 0 <= val <= 50
* 
* 
*/
#include <iostream>
#include <vector>
#include <functional>
#include <string>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = head;
        ListNode *pre = dummy;
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
                cur = pre->next;
            } else {
                cur = cur->next;
                pre = pre->next;
            }
        }
        return dummy->next;
    }
};
