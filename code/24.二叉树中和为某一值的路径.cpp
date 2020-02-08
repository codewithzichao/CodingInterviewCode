/*
题目描述
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

//先序创建二叉树
TreeNode * createTree(){
	TreeNode * q;
	int data;
	scanf("%d",&data);
	if(data==0){
		q=nullptr;
	}
	else{
		q=new TreeNode(data);
		q->left=createTree();
		q->right=createTree();
	}

	return q;
}

class Solution{
	public:
	/*
	思路：回溯+DFS。这是最直观的思路。就是计算当前路径的和是否等于期望的值。
	*/
	vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		if(root==nullptr){//如果root=nullptr，返回空的集合
			vector<vector<int> > ans;
			return ans;
		}

		vector<vector<int> > vec;//最终返回的值，所有路径的集合
		vector<int> temp;//存放一条路径
		int cursum=0;//当前路径的值
		DFS(root,expectNumber,cursum,temp,vec);//回溯，使用DFS
		return vec;//返回所有路径的集合
	}

	void DFS(TreeNode * root,int expectNumber,int &cursum,vector<int> &temp,vector<vector<int> > &vec){
		if(root==nullptr){
			return;
		}
		temp.push_back(root->val);
		cursum+=root->val;
		if(root->left==nullptr && root->right==nullptr && cursum==expectNumber){//当遍历到叶节点。并且cursum等于期望的值，那么说明找到一条路径
			vec.push_back(temp);
		}
		else{
			if(root->left){
				DFS(root->left,expectNumber,cursum,temp,vec);
			}
			if(root->right){
				DFS(root->right,expectNumber,cursum,temp,vec);
			}
		}
		temp.pop_back();//回溯，将root节点删除，返回到上一节点
		cursum-=root->val;//回溯，当前的和也要减去root的值
	}

	/*
	思路：仍然是回溯+DFS。另外一种思路是：让期望的值减去当前的节点的值，如果遍历到叶子节点的时候，当前期望的值等于叶子节点的值，说明找到一条路径。
	*/
	vector<vector<int> > ans;
	vector<int> aPath;
	vector<vector<int> > FindPath2(TreeNode* root,int expectNumber) {
		if(root==nullptr){
			return ans;
		}

		DFS2(root,expectNumber);
		return ans;
	}

	void DFS2(TreeNode * root,int expectNumber){
		if(root==nullptr){
			return;
		}
		aPath.push_back(root->val);
		if(root->left==nullptr && root->right==nullptr && expectNumber==root->val){
			ans.push_back(aPath);
		}
		else{
			expectNumber-=root->val;
			if(root->left){
				DFS2(root->left,expectNumber);
			}
			if(root->right){
				DFS2(root->right,expectNumber);
			}
		}
		aPath.pop_back();
		expectNumber+=root->val;
	}
};

int main(){
	printf("请输入节点值：");
	TreeNode * root=createTree();
	printf("请输入总和：");
	int expectNumber;
	scanf("%d",&expectNumber);

	Solution so1;
	vector<vector<int> > ans=so1.FindPath2(root,expectNumber);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
