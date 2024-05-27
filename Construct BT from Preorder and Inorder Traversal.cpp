/*Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.*/
#include <vector>
#include <unordered_map>

using namespace std;

// Assume TreeNode is defined somewhere else
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        int preorderIndex = 0;
        return buildTreeHelper(preorder, inorderMap, preorderIndex, 0, inorder.size() - 1);
    }
    
private:
    TreeNode* buildTreeHelper(vector<int>& preorder, unordered_map<int, int>& inorderMap, int& preorderIndex, int inorderStart, int inorderEnd) {
        if (inorderStart > inorderEnd) {
            return nullptr;
        }

        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);
        int inorderIndex = inorderMap[rootValue];

        root->left = buildTreeHelper(preorder, inorderMap, preorderIndex, inorderStart, inorderIndex - 1);
        root->right = buildTreeHelper(preorder, inorderMap, preorderIndex, inorderIndex + 1, inorderEnd);

        return root;
    }
};
