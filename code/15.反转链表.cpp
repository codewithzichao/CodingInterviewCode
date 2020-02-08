/*
题目描述
输入一个链表，反转链表后，输出新链表的表头。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

ListNode * createListNode(int arr[],int n){
	ListNode * dummy=new ListNode(0);
	ListNode * pre=dummy;
	for(int i=0;i<n;i++){
		ListNode * node=new ListNode(arr[i]);
		pre->next=node;
		pre=node;
	}
	return dummy->next;
}

class Solution{
	public:
	//方法一：定义三个指针，分别指向当前节点的前一个节点pPre、当前节点pNode、当前节点的后一个节点pNext。
	//首先要保存pNext，因为当反向的时候，当前节点->当前节点的后一个节点，链会断裂，那么就无法找到但前节点的后一个节点了
	//然后，反向，pNode->next=pPre
	//然后，pPre=pNode;pNode=pNext,迭代
	//当pNext=nullptr的时候，说明到链尾了，那么就返回pNode
	//over
	ListNode* ReverseList1(ListNode* pHead) {
		if(pHead==nullptr || pHead->next==nullptr){
			return pHead;
		}

		ListNode * reverseHead=nullptr;
		ListNode * pNode=pHead;
		ListNode * pPre=nullptr;

		while(pNode!=nullptr){
			ListNode * pNext=pNode->next;
			if(pNext==nullptr){
				reverseHead=pNode;
			}

			pNode->next=pPre;
			pPre=pNode;
			pNode=pNext;

		}

		return reverseHead;
	}

	//递归.
	ListNode* ReverseList2(ListNode* pHead) {
		if(pHead==nullptr || pHead->next==nullptr){
			return pHead;
		}

		ListNode * temp=ReverseList2(pHead->next);
		pHead->next->next=pHead;//这句是递归的精髓所在！仔细品味
		pHead->next=nullptr;

		return temp;
	}
};

int main(){
	int n;
	printf("请输入数组长度:");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		arr[i]=x;
	}

	ListNode * pHead=createListNode(arr,n);
	Solution so1;
	ListNode * reverseHead=so1.ReverseList2(pHead);
	while(reverseHead!=nullptr){
		printf("%d",reverseHead->val);
		if(reverseHead->next!=nullptr){
			printf("->");
		}
		reverseHead=reverseHead->next;
	}

	printf("\n");
	return 0;

}