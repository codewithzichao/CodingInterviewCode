/*
题目描述
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution{
	public:
	//简单题。递归。
	int TreeDepth(TreeNode* pRoot){
		if(pRoot==nullptr){
			return 0;
		}

		int left=0,right=0;
		if(pRoot->left) left=TreeDepth(pRoot->left);
		if(pRoot->right) right=TreeDepth(pRoot->right);

		return left>=right?left+1:right+1;
	}
	//迭代的话，使用层序遍历的方法就可以了。
};

int main(){
	return 0;
}