/*
题目描述
给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
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
	TreeNode* KthNode(TreeNode* pRoot, int k){
		if(pRoot==nullptr || k<=0) return nullptr;
		TreeNode * ans=nullptr;
		InOrder(pRoot,ans,k);

		return ans;
	}

	void InOrder(TreeNode * pRoot,TreeNode * &ans,int k){
		if(pRoot==nullptr) return;
		
		InOrder(pRoot->left,ans,k);
		k--;
		if(k==0) ans=pRoot;
		InOrder(pRoot->right,ans,k);
	}
};

int main(){
	return 0;
}
