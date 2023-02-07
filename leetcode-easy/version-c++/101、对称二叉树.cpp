/*
    给你一个二叉树的根节点 root ， 检查它是否轴对称。
 

    示例 1：
        输入：root = [1,2,2,3,4,4,3]
        输出：true

    示例 2：
        输入：root = [1,2,2,null,3,null,3]
        输出：false
    

    提示：
        树中节点数目在范围 [1, 1000] 内
        -100 <= Node.val <= 100
    

    进阶：你可以运用递归和迭代两种方法解决这个问题吗？
*/
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归
class Solution {
public:
    bool check(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if (!p || !q) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        return check(p->left, q->right) && check(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

// 迭代
class Solution {
public:
    bool check(TreeNode* p, TreeNode* q) {
        queue<TreeNode *> que;
        que.push(p);
        que.push(q);
        while (!que.empty()) {
            p = que.front();
            que.pop();
            q = que.front();
            que.pop();
            if (!p && !q) {
                continue;
            }
            if ((!p || !q) || (p->val != q->val)) {
                return false;
            }
            que.push(p->left);
            que.push(q->right);
            que.push(p->right);
            que.push(q->left);
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};