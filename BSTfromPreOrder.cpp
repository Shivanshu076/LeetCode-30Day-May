/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.
*/

// Solution :

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int n=preorder.size(); if(!n) return NULL;
    TreeNode* r=new TreeNode(preorder[0]);
    for(int i=1;i<n;i++){
        int x= preorder[i];
        TreeNode *p=r, *c;
        if(x>p->val) c=p->right;
        else c=p->left;
        while(c){
            p=c;
            if(x>c->val) c=c->right;
            else c=c->left;
        }
        if(x>p->val) p->right= new TreeNode(x);
        else p->left= new TreeNode(x);
    }
    return r;
}
