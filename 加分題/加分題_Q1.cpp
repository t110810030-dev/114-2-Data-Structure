class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==nullptr && q==nullptr) return true;//都是空的
        if (p==nullptr || q==nullptr) return false;//只有一個是空的
        if (p->val != q->val) return false;//值不同
        return isSameTree(p->left, q->left) &&//值相同
               isSameTree(p->right, q->right);
    }
};
