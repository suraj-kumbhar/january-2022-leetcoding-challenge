// 1022. Sum of Root To Leaf Binary Numbers
// Easy

// 2256

// 138

// Add to List

// Share
// You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

// For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
// For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

// The test cases are generated so that the answer fits in a 32-bits integer.

 

// Example 1:


// Input: root = [1,0,1,0,1,0,1]
// Output: 22
// Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
// Example 2:

// Input: root = [0]
// Output: 0
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// Node.val is 0 or 1.

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
    int sumRootToLeaf(TreeNode* root, int sum){
        if(!root) return 0;
        sum = (2 * sum) + root->val;
        if(!root->left && !root->right) return sum;
        return sumRootToLeaf(root->left, sum) + sumRootToLeaf(root->right, sum);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return sumRootToLeaf(root, 0);
    }
    
};

// alternate solution

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
    void dfs(TreeNode* root, string &s, int &res){
        if(!root){
            return;
        }
        s += to_string(root->val);
        if(!root->left && !root->right){
            int temp = 0;
            int ind = 0;
            
            for(int i = s.length() - 1; i>=0; i--){
                if(s[i] == '1')
                {
                    temp += pow(2, ind);
                }
                ind++;
            }
            res += temp;
            s = s.substr(0, s.length()-1);
            return;
        }
        else{
            if(root->left){
                dfs(root->left, s, res);
                
            }
            if(root->right){
                dfs(root->right, s, res);
                
            }
        }
        s = s.substr(0, s.length()-1);
        return;
        
    }
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        string s = "";
        dfs(root, s, res);
        return res;
    }
};