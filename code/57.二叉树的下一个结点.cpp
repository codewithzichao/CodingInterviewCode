/*
题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution{
	public:
	/*
	思路：
	1、有右子树的，那么下个结点就是右子树最左边的点；（eg：D，B，E，A，C，G） 
	2、没有右子树的，也可以分成两类：
		a)是父节点左孩子，那么父节点就是下一个节点 ；
		b)是父节点的右孩子，找他的父节点的父节点的父节点...
			直到当前结点是其父节点的左孩子位置。如果没有，那么他就是尾节点。
	
	over～
	*/
	TreeLinkNode* GetNext(TreeLinkNode* pNode){
		if(pNode==nullptr) return pNode;//边界条件，当节点为空，返回nullptr或者pNode

		if(pNode->right!=nullptr){//当节点的右子树不为空的时候，那么就返回右子树最左边的节点
			pNode=pNode->right;
			while(pNode->left!=nullptr){
				pNode=pNode->left;
			}
			return pNode;
		}
		else{//当节点的右子树为空的时候
			while(pNode->next!=nullptr){//如果节点有父节点，如果节点是其父节点的左节点的话，那么就返回父节点；
				TreeLinkNode * pRoot=pNode->next;//如果节点是其父节点的右节点的话，那么就要找父节点的父节点......直到节点是其父节点的左节点为止。
				if(pRoot->left==pNode){
					return pRoot;
				}
				else{
					pNode=pNode->next;
				}
			}
			
		}
		return nullptr;//其余情况均返回nullptr
	}
};

int main(){
	return 0;
}