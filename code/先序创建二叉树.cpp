#include<stdio.h>
#include<stdlib.h>

typedef struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *Left;
    struct BinaryTreeNode *Right;
}Node;
 
 
//创建二叉树，顺序依次为中间节点->左子树->右子树
Node* createBinaryTree()
{
    Node *p;
    int ch;
	printf("输入data:");
    scanf("%d",&ch);
    if(ch == 0)     //如果到了叶子节点，接下来的左、右子树分别赋值为0
    {
        p = NULL;
    }
    else
    {
        p = (Node*)malloc(sizeof(Node));
        p->data = ch;
        p->Left  = createBinaryTree();  //递归创建左子树
        p->Right = createBinaryTree();  //递归创建右子树
    }
    return p;
}
 
//先序遍历
void preOrderTraverse(Node* root)
{
    if( root )
    {
        printf("%d",root->data);
        preOrderTraverse(root->Left);
        preOrderTraverse(root->Right);
    }
}
 
//中序遍历
void inOrderTraverse(Node* root)
{
    if( root )
    {
        inOrderTraverse(root->Left);
        printf("%d",root->data);
        inOrderTraverse(root->Right);
    }
}
 
//后序遍历
void lastOrderTraverse(Node* root)
{
    if( root )
    {
        lastOrderTraverse(root->Left);
        lastOrderTraverse(root->Right);
        printf("%d",root->data);
    }
}
 
//二叉树节点总数目
int Nodenum(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return 1+Nodenum(root->Left)+Nodenum(root->Right);
    }
}

 
//二叉树叶子节点数
int Leafnum(Node* root)
{
    if(!root)
    {
        return 0;
    }
    else if(  (root->Left == NULL) && (root->Right == NULL) )
    {
        return 1;
    }
    else
    {
        return  (Leafnum(root->Left) + Leafnum(root->Right)) ;
    }
}
 
 
int main()
{
	int i;
    Node *root = NULL;
    root = createBinaryTree();
    printf("二叉树建立成功");
	printf("\n");
    preOrderTraverse(root);
	printf("\n");
    inOrderTraverse(root);
	printf("\n");
    lastOrderTraverse(root);
	printf("\n");
    i = Leafnum(root);
	printf("%d",i);
	printf("\n");
	i = Nodenum(root);
	printf("%d",i);
    return 0;
}