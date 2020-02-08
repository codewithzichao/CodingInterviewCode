/*
题目描述
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
HF作为牛客的资深元老,自然也准备了一些小游戏。
其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。
每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,
从他的下一个小朋友开始,继续0...m-1报数....这样下去....
直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)

如果没有小朋友，请返回-1
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;

class Solution{
	public:
	/*
	方法一：这是著名的约瑟夫问题。第一种方法，就是使用环形链表来模拟这个过程。在C++中，stl中使用list封装好了链表。具体步骤如下：
	1.将数组中的元素全部放入链表中；
	2.使用一个指针指向链表的头节点，并走m-1步，到达第m-1个节点；当然每次往前走，都需要判断指针是否到达了链尾，如果到达了链尾，那么指针就要指向链头；
	3.另建一个指针指向第一个指针的下一个节点；
	4.删除第一个指针指向的节点，并把第二个指针指向的节点赋给第一个指针；
	5.直到链表元素只剩一个为止，结束循环。
	时间复杂度:O(mn).
	over～
	*/
	int LastRemaining_Solution(int n, int m){
		if(n<1 || m<1) return -1;

		list<int> numbers;
		for(int i=0;i<n;i++) numbers.push_back(i);

		list<int>::iterator it=numbers.begin();

		while(numbers.size()>1){
			for(int i=1;i<m;i++){
				it++;
				if(it==numbers.end()) it=numbers.begin();
			}

			list<int>::iterator next=++it;
			if(next==numbers.end()) next=numbers.begin();

			it--;
			numbers.erase(it);
			it=next;
		}

		return *it;
	}

	//数学法。分析之后得到的结果。
	int LastRemaining_Solution2(int n, int m){
		if(n<1 || m<1) return -1;
		int last=0;
		for(int i=2;i<=n;i++){
			last=(last+m)%i;
		}

		return last;
	}
};

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	Solution so1;
	int ans=so1.LastRemaining_Solution2(n,m);
	printf("%d\n",ans);
	return 0;
}