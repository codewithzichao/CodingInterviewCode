/*
题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

class Solution{
	public:
	/*
	思路：首先要清楚平衡二叉树的概念。平衡二叉树指的是左子树与右子树的高度差不超过1.
	那么很自然的，我们计算出左子树与右子树的高度，如果高度差在1之内，那么递归计算左子树与右子树；否则，返回false。
	那么计算二叉树的高度，可以使用递归的方式实现，当然，也可以使用层次遍历的方式实现。
	over～
	*/
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if(pRoot==nullptr){
			return true;
		}

		int left=GetDepth(pRoot->left);
		int right=GetDepth(pRoot->right);
		if(abs(left-right)>1){
			return false;
		}
		else{
			return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
		}
	}

	int GetDepth(TreeNode * pRoot){
		if(pRoot==nullptr){
			return 0;
		}

		int left=GetDepth(pRoot->left);
		int right=GetDepth(pRoot->right);

		return left>=right?left+1:right+1;

	}
};

int main(){
	return 0;
}