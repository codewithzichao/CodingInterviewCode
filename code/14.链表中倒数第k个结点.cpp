/*
题目描述
输入一个链表，输出该链表中倒数第k个结点。
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
	//方法一：非常直接的思路。首先统计链表长度n，然后找到规律：找倒数第k个节点等于找正数n-k+1个节点。
	ListNode* FindKthToTail1(ListNode* pListHead, unsigned int k) {
		if(pListHead==nullptr || k==0){
			return nullptr;
		}

		int length=0;
		ListNode * pre=pListHead;
		while(pre!=nullptr){
			length++;
			pre=pre->next;
		}

		if(k>length){//这个一定要判断一下，要不然不能AC！
			return nullptr;
		}

		for(int i=0;i<(length-k);i++){
			pListHead=pListHead->next;
		}

		return pListHead;
	}

	//双指针。定义两个指针，初始时均指向头指针。1.让p1先走k-1步，p2不动；2.让p1、p2一起往后移动，当p1到达链尾的时候，p2指的位置就是要求的位置。
	ListNode* FindKthToTail2(ListNode* pListHead, unsigned int k) {
		if(pListHead==nullptr || k==0){
			return nullptr;
		}

		ListNode * pBegin=pListHead;
		ListNode * pEnd=pListHead;

		for(int i=0;i<k-1;i++){
			if(pBegin->next!=nullptr){
				pBegin=pBegin->next;
			}
			else{
				return nullptr;
			}
		}

		while(pBegin->next!=nullptr){
			pBegin=pBegin->next;
			pEnd=pEnd->next;
		}

		return pEnd;
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

	int k;
	scanf("%d",&k);
	ListNode * pListHead=createListNode(arr,n);
	Solution so1;
	ListNode * ans=so1.FindKthToTail2(pListHead,k);
	printf("%d\n",ans->val);
	return 0;	
}