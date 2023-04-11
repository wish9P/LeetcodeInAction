/**
* [19]删除链表的倒数第 N 个结点
*
*
*https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
*
*
* 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*  
* 示例 1：
* 输入：head = [1,2,3,4,5], n = 2
* 输出：[1,2,3,5]
* 
* 示例 2：
* 输入：head = [1], n = 1
* 输出：[]
* 
* 示例 3：
* 输入：head = [1,2], n = 1
* 输出：[1]
* 
*  
* 提示：
* 链表中结点的数目为 sz
* 1 <= sz <= 30
* 0 <= Node.val <= 100
* 1 <= n <= sz
* 
*  
* 进阶：你能尝试使用一趟扫描实现吗？
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        ListNode* slow = pre;
        ListNode* fast = pre;
        // 我们希望找到“倒数”第n+1个节点，方便进行删除操作！
        n += 1;
        // 如果已经规定 0 <= n <= sz，那就说明fast在n为0的时候肯定不为空，就不需要这个判断了
        while (n--) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return pre->next;
    }
};
