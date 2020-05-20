// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

// Solution ( Inorder traversal ) :

void f(TreeNode *n, int &k, int &ans){
        if(n->left) f(n->left, k, ans);
        k--;
        if(!k){
            ans= n->val;
            return;
        }
        if(n->right) f(n->right, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        f(root,k,ans);
        return ans;
    }
