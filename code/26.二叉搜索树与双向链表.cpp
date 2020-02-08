/*
题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
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
	/*
	思路：二叉树和双向链表是非常相似的。在二叉树中，一个节点有两个子节点（除去叶节点）；双向链表中，一个节点有两个指针。所以相互转换是有可能的。
	由于最后得出的双向链表是排序的，所以我们可以对二叉搜索树采取中序遍历的方式。
	那么，我们可以将二叉搜索树分为三部分：左子树、根节点、右子树。
	需要注意的是，根节点的左指针需要连接左子树中最大的节点，右指针需要连接右子树中最小的节点。之后，左子树和右子树可以递归实现。
	over～
	*/
	TreeNode* Convert(TreeNode* pRootOfTree){
		if(pRootOfTree==nullptr){
			return nullptr;
		}

		TreeNode * LastNodePtr=nullptr;//LastNodePtr指向已排好序的双向链表的最后一个节点
		ConvertNode(pRootOfTree,LastNodePtr);//调用这个函数之后，LastNodePtr已经指向双向链表的最后一个节点了
		TreeNode * ans=LastNodePtr;//ans是返回值
		while(ans->left!=nullptr){//往回遍历
			ans=ans->left;
		}

		return ans;//返回ans
		
	}

	//转换操作
	void ConvertNode(TreeNode * pRootOfTree,TreeNode * &LastNodePtr){//注意，一定要加引用&！！！
		if(pRootOfTree==nullptr){//如果pRootOfTree为nullptr的话，那么返回
			return;
		}

		ConvertNode(pRootOfTree->left,LastNodePtr);//对左子树执行递归操作
		pRootOfTree->left=LastNodePtr;//根节点的左指针指向已排好的左边双向链表的最后一个节点
		if(LastNodePtr!=nullptr){//如果最后一个节点不为空的话，那么最后一个节点的右指针指向根节点
			LastNodePtr->right=pRootOfTree;
		}

		LastNodePtr=pRootOfTree;//将最后一个节点与根节点相连接之后，链表长度+1，并且这时的链表的最后一个节点就是根节点了，这个需要注意！
		ConvertNode(pRootOfTree->right,LastNodePtr);//对右子树执行递归操作
	}
};

int main(){
	return 0;
}