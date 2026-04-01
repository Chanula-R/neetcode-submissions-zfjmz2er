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
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> pA;
        vector<int> qA;
        traverse(p,pA);
        traverse(q,qA);
        if (pA == qA)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }

    void traverse(TreeNode* p,vector<int>& pA)
    {   
        if (!p)
        {
            pA.push_back(0);
            return;
        }
        if(p)
        {
            pA.push_back(p->val);
            traverse(p->left,pA);
            traverse(p->right,pA);
        } 
    }
};
