#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *root, vector<int> &vals) {
        if (root == NULL) {
            return;
        }
        dfs(root->left, vals);
        vals.emplace_back(root->val);
        dfs(root->right, vals);
    }

    vector<int> Merge(vector<int> &left, vector<int> &right) {
        vector<int> res;
        res.reserve(left.size() + right.size());

        int lBeg = 0, lEnd = left.size();
        int rBeg = 0, rEnd = right.size();
        while (lBeg < lEnd && rBeg < rEnd) {
            if (left[lBeg] < right[rBeg]) {
                res.emplace_back(left[lBeg++]);
            } else {
                res.emplace_back(right[rBeg++]);
            }
        }
        while (lBeg < lEnd) {
            res.emplace_back(left[lBeg++]);
        }
        while (rBeg < rEnd) {
            res.emplace_back(right[rBeg++]);
        }
        return res;
    }

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        vector<int> vals1;
        vector<int> vals2;
        dfs(root1, vals1);
        dfs(root2, vals2);
        return Merge(vals1, vals2);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
