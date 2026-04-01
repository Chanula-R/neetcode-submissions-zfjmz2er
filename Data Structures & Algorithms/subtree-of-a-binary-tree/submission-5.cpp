/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if (!subRoot)
        {
            return true;
        }
        if (isSametree(root,subRoot))
        {
            return true;
        }
        if(root)
        {
            return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
        }
        else
        {
            return false;
        }
    
    }

    bool isSametree(TreeNode* root1,TreeNode* root2)
    {
        if (!root1 && !root2)
        {
            return true;
        }
        else if ((!root1 || !root2) || (root1->val != root2->val))
        {
            return false;
        }
        else
        {
            return (isSametree(root1->left,root2->left) && isSametree(root1->right,root2->right));
        }
    }
};
