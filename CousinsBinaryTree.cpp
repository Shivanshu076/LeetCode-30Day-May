/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.
*/

// Recursive solution :

typedef pair<int,int> pi;
    
void fn(TreeNode* n,int t, int cd, int p, pi &ans){
    if(!n) return;
    if(n->val==t){
        ans= make_pair(cd,p);
        return;
    }
    fn(n->left,t,cd+1,n->val,ans);
    fn(n->right,t,cd+1,n->val,ans);
}
    
bool isCousins(TreeNode* root, int x, int y) {
    pi xx,yy;
    fn(root,x,0,-1,xx);
    fn(root,y,0,-1,yy);
    if(xx.first==yy.first && xx.second!=yy.second) return 1;
    return 0;
}
