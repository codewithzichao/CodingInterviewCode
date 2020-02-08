/*
题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//定义TreeNode
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

//后序遍历
void PostOrder(TreeNode * T){
	if(T==nullptr){
		return;
	}
	if(T->left){
		PostOrder(T->left);
	}
	if(T->right){
		PostOrder(T->right);
	}
	printf("%d ",T->val);
}


class Solution{
	public:
	//根据前序遍历与中序遍历，构建二叉树
	TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		//如果没有节点的话，返回nullptr
		if(pre.size()==0){
			return nullptr;
		}

		//如果只有一个节点的话，就返回根节点
		int rootVal=pre[0];
		TreeNode * root=new TreeNode(rootVal);
		if(pre.size()==1){
			return root;
		}

		//如果不止一个节点的话，那么执行以下步骤
		
		//找到中序遍历中的根节点下标
		int rootidx=0;
		for(int i=0;i<pre.size();i++){
			if(rootVal==vin[i]){
				rootidx=i;
				break;
			}
		}


		int s1=0,e1=pre.size()-1,s2=0,e2=vin.size()-1;

		//如果左子树不为空，那么递归构建左子树
		if(rootidx!=s2){
			vector<int> pre_left,vin_left;
			for(int i=s1+1;i<=s1+1+(rootidx-1-s2);i++){
				pre_left.push_back(pre[i]);
			}
			for(int j=s2;j<=rootidx-1;j++){
				vin_left.push_back(vin[j]);
			}

			root->left=reConstructBinaryTree(pre_left,vin_left);
		}

		//如果右子树不为空，递归构建右子树
		if(rootidx!=e2){
			vector<int> pre_right,vin_right;
			for(int i=s1+1+(rootidx-1-s2)+1;i<=e1;i++){
				pre_right.push_back(pre[i]);
			}
			for(int j=rootidx+1;j<=e2;j++){
				vin_right.push_back(vin[j]);
			}
			root->right=reConstructBinaryTree(pre_right,vin_right);
		}

		//返回根节点指针
		return root;

	}
}; 

int main(){
	int pre_n,vin_n;
	scanf("%d%d",&pre_n,&vin_n);
	vector<int> pre,vin;
	for(int i=0;i<pre_n;i++){
		int x;
		scanf("%d",&x);
		pre.push_back(x);
	}
	for(int j=0;j<vin_n;j++){
		int y;
		scanf("%d",&y);
		vin.push_back(y);
	}

	Solution so1;
	TreeNode *root=so1.reConstructBinaryTree(pre,vin);
	PostOrder(root);
	return 0;

}
 