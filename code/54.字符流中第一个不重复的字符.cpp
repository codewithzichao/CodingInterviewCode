/*
题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。

输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。
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
	Solution(){
		memset(array,0,sizeof(array));
	}
	void Insert(char ch){
		++array[ch-'0'];
		if(array[ch-'0']==1){
			q.push(ch);
		}
		return;
	}

	char FirstAppearingOnce(){
		while(q.empty()==false && array[q.front()]>=2) q.pop();
		if(q.empty()) return '#';
		return q.front();
	}

	private:
	queue<char> q;
	int array[128];
};

int main(){
	return;
}