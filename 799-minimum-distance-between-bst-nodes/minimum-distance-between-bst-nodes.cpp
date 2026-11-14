/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev = NULL;

    int minDiffInBST(TreeNode* root) { // O(n)
        if (root == NULL) {  // BC
            return INT_MAX;
        }

        int ans = INT_MAX;

        if (root->left != NULL) { // left
            int leftmin = minDiffInBST(root->left);
            ans = min(ans, leftmin);
        }

        if (prev != NULL) {  // root
            ans = min(ans, root->val - prev->val); // currDiff
        }

        prev = root;

        if (root->right != NULL) { // right
            int rightmin = minDiffInBST(root->right);
            ans = min(ans, rightmin);
        }

        return ans;
    }
};