#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

TreeNode * createTree(){
	TreeNode *p;
	int data;
	printf("输入节点值：");
	scanf("%d",&data);
	if(data==0){
		p=nullptr;
	}
	else{
		p=new TreeNode(data);
		p->left=createTree();
		p->right=createTree();
	}

	return p;
}

void PostOrder(TreeNode *T){
	if(T==nullptr){
		return;
	}
	if(T->left!=nullptr){
		PostOrder(T->left);
	}
	if(T->right!=nullptr){
		PostOrder(T->right);
	}
	printf("%d ",T->val);
}

int main(){
	TreeNode * root=createTree();
	printf("后序遍历的结果如下：");
	PostOrder(root);
	return 0;
}
