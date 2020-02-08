
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL) {
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
	ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
		ListNode * p1=pHead1;
		ListNode * p2=pHead2;

		while(p1!=p2){
			p1=(p1==nullptr?pHead2:p1->next);
			p2=(p2==nullptr?pHead1:p2->next);
		}

		return p1;
	}
};

int main(){
	int n1,n2;
	scanf("%d",&n1);
	int arr1[n1];
	
	for(int i=0;i<n1;i++){
		int x;
		scanf("%d",&x);
		arr1[i]=x;
	}

	scanf("%d",&n2);
	int arr2[n2];
	for(int i=0;i<n2;i++){
		int x;
		scanf("%d",&x);
		arr2[i]=x;
	}

	ListNode * pHead1=createListNode(arr1,n1);
	//printf("anks");
	ListNode * pHead2=createListNode(arr2,n2);

	Solution so1;
	ListNode * ans=so1.FindFirstCommonNode(pHead1,pHead2);
	printf("%d\n",ans->val);
	return 0;
}