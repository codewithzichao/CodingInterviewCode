/*
题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

class Solution{
	public:
	//这种非常容易想到，但是面试必挂！
	string LeftRotateString(string str, int n) {
		if(str.size()==0 || n==0){
			return str;
		}

		string strTemp=str.substr(0,n);
		str.erase(0,n);
		str+=strTemp;
		return str;
	}

	/*
	这才是正确思路。举例说明： str=abcXYZdef，n=3.记X=abc,Y=XYZdef.我们要求的是：YX。具体做法如下：
	1.反转X得到XT，即cba；反转Y得到YT，即：fedZYX。所以：XTYT=cbafedZYX。
	2.再对XTYT反转，得到XYZdefabc。
	总结：YX=(XTYT)T.
	over～
	*/
	string LeftRotateString2(string str, int n) {
		if(str.size()==0 || n==0){
			return str;
		}

		int length=str.size();
		n%=length;//这一步必不可少，主要是防止n>length的情况
		for(int i=0,j=n-1;i<j;i++,j--) swap(str[i],str[j]);
		for(int i=n,j=length-1;i<j;i++,j--) swap(str[i],str[j]);
		for(int i=0,j=length-1;i<j;i++,j--) swap(str[i],str[j]);

		return str;
	}
};

int main(){
	string str;
	int n;
	cin>>str>>n;
	Solution so1;
	string ans=so1.LeftRotateString2(str,n);
	cout<<ans<<endl;
	return 0;
}