#include <bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */

class CBTInserter {
public:
    TreeNode* _root;
    vector<TreeNode*> _tree;

    CBTInserter(TreeNode* root) {
        _root = root;
        // #{nodes} is bounded by 10^3
        // Add dummy node at _tree[0] to make sure 
        // that the relation parent(2*i) == parent(2*i + 1) == i is valid
        _tree.reserve(1001);
        _tree.push_back(0);

        queue<TreeNode*> q {{root}};
        for(; !q.empty(); q.pop()) {
            auto node = q.front();
            _tree.push_back(node);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right); 
        }
    }

    int insert(int val) {
        TreeNode* new_node = new TreeNode(val);
        _tree.push_back(new_node);
        auto parent = _tree[(_tree.size()-1) >> 1];
        !parent->left ? parent->left = new_node : parent->right = new_node;
        return parent->val;
    }

    TreeNode* get_root() {
        return _root;
    }
};

