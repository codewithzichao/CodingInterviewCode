/*
题目描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

class Solution{
	public:
	/*
	方法一：使用priority_queue创建一个最大堆（bigheap）和最小堆（smallheap）。
	维持最大堆的元素均小于最小堆的元素，并且，0<=最大堆的元素数目-最小堆的元素数目<=1.
	over~
	*/
	void Insert(int num){
		if(bigheap.empty()==true || num<=bigheap.top()) bigheap.push(num);
		else smallheap.push(num);

		if(bigheap.size()==smallheap.size()+2){
			smallheap.push(bigheap.top());
			bigheap.pop();
		}
		if(bigheap.size()==smallheap.size()-1){
			bigheap.push(smallheap.top());
			smallheap.pop();
		}
	}

	double GetMedian(){
		return bigheap.size()==smallheap.size()?(bigheap.top()+smallheap.top())/2.0:bigheap.top();
	}


	priority_queue<int,vector<int>, less<int> > bigheap;//创建最大堆，默认就是最大堆
	priority_queue<int,vector<int>, greater<int> > smallheap;//创建最小堆
};


/*
	方法二：nowcoder上还有大佬手撸AVL树的，给跪了......
	*/

struct myTreeNode
{
    int val;
    int count;//以此节点为根的树高
    struct myTreeNode* left;
    struct myTreeNode* right;
    myTreeNode(int v) :
        val(v),
        count(1), left(NULL), right(NULL) {}
 
};
 
myTreeNode *root = NULL;
 
class Solution2
{
public:
 
    /*计算以节点为根的树的高度
    */
    int totalCount(myTreeNode* node)
    {
        if (node == NULL)
            return 0;
        else
            return node->count;
    }
 
    //左左
    void rotateLL(myTreeNode* &t)
    {
        myTreeNode* k = t->left;
        myTreeNode* tm = NULL;
        while (k->right != NULL)
        {
            k->count--;
            tm = k;
            k = k->right;
             
        }
        if (k != t->left)
        {
            k->left = t->left;
            tm->right = NULL;
        }
        t->left = NULL;
        k->right = t;
 
 
        t->count = totalCount(t->left) + totalCount(t->right) + 1;
        k->count = totalCount(k->left) + t->count + 1;
 
        t = k;
    }
 
    //右右
    void rotateRR(myTreeNode* &t)
    {
        myTreeNode* k = t->right;
        myTreeNode* tm = NULL;
        while (k->left != NULL) {
            k->count--;
            tm = k;
            k = k->left;
             
        }
        if (k != t->right)
        {
            k->right = t->right;
            tm->left = NULL;
        }
             
        t->right = NULL;
        k->left = t;
 
        t->count = totalCount(t->left) + 1;
        k->count = totalCount(k->right)+ t->count + 1;
        t = k;
    }
 
    //左右
    void rotateLR(myTreeNode* &t)
    {
        rotateRR(t->left);
        rotateLL(t);
    }
 
    //右左
    void rotateRL(myTreeNode* &t)
    {
        rotateLL(t->right);
        rotateRR(t);
    }
 
    //插入
    void insert(myTreeNode* &root, int x)
    {
        if (root == NULL)
        {
            root = new myTreeNode(x);
            return;
        }
         
        if (root->val >= x)
        {
            insert(root->left, x);
            root->count = totalCount(root->left)+ totalCount(root->right) + 1;
            if (2 == totalCount(root->left) - totalCount(root->right))
            {
                if (x < root->left->val)
                {
                    rotateLL(root);
                }
                else
                {
                    rotateLR(root);
                }
            }
        }
        else
        {
            insert(root->right, x);
            root->count = totalCount(root->left)+ totalCount(root->right) + 1;
            if (2 == totalCount(root->right) - totalCount(root->left))
            {
                if (x > root->right->val)
                {
                    rotateRR(root);
                }
                else {
                    rotateRL(root);
                }
            }
        }
 
    }
 
    void deleteTree(myTreeNode* root)
    {
        if (root == NULL)return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
     
    void Insert(int num)
    {
        insert(root, num);
    }
 
    double GetMedian()
    {
        int lc = totalCount(root->left), rc = totalCount(root->right);
        if ( lc == rc)
            return root->val;
        else
        {
            bool isLeft = lc > rc ;
            myTreeNode* tmp ;
            if (isLeft)
            {
                tmp = root->left;
                while (tmp->right != NULL)
                {
                    tmp = tmp->right;
                }
            }
            else {
                tmp = root->right;
                while (tmp->left != NULL)
                {
                    tmp = tmp->left;
                }
            }
            return (double)(root->val + tmp->val) / 2.0;
        }
    }
 
};

int main(){
	int arr[]={1,2,3,9,4,5};
	Solution so2;
	for(int i=0;i<sizeof(arr)/sizeof(int);i++){
		so2.Insert(arr[i]);
	}
	double mid=so2.GetMedian();
	printf("中位数为：%lf\n",mid);
	return 0;
}