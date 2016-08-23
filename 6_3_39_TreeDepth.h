//求树的深度和是否平衡
#include <iostream>
#include <math.h>

using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){
    }
};
int TreeDepth(TreeNode* pRoot){
    if(pRoot == NULL)
        return 0;
    if(pRoot->left==NULL && pRoot->right == NULL)
        return 1;
    int left = TreeDepth(pRoot->left);
    int right = TreeDepth(pRoot->right);
    int depth;
    if(left >= right)
        depth = left + 1;
    else
        depth = right + 1;
    return depth;
}
//判断一棵树是不是平衡二叉树，每个结点需要遍历多次，效率低
bool IsBalanced(TreeNode* pRoot){
    if(pRoot == NULL)
        return true;
    int left = TreeDepth(pRoot->left);
    int right = TreeDepth(pRoot->right);
    int diffHeight = left - right;
    if(abs(diffHeight) > 1)
        return false;
    bool isleft = IsBalanced(pRoot->left);
    bool isright = IsBalanced(pRoot->right);
    return isleft && isright;
}
bool IsBalanced(TreeNode* pRoot,int& depth){
    if(pRoot == NULL){
        depth = 0;
        return true;
    }
    int left,right;
    if(IsBalanced(pRoot->left,left) && IsBalanced(pRoot->right,right)){
        int diff = left - right;
        if(abs(diff) <= 1){
            depth = 1+(left > right ? left:right);
            return true;
        }
    }
    return false;
}
bool IsBalanced_Solution(TreeNode* pRoot){
    if(pRoot == NULL)
        return true;
    int depth = 0;
    return IsBalanced(pRoot,depth);
}
void Test(){
    TreeNode* root;
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    TreeNode h(7);
    root = &a;
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    e.right = &h;
    int dep = TreeDepth(NULL);
    cout<<dep<<" ";
}

