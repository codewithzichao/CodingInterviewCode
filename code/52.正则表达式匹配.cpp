/*
题目描述
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
	/*
	思路：
	一、首先考虑特殊情况：
			1.当str与pattern字符串均为空时，那么返回true；
			2.当str不为空，pattern为空，返回false；
			3.当str为空，pattern不为空，需要分情况讨论；
			4.当str不为空，pattern不为空，需要分情况讨论。
	二、当不是特殊情况之时：
			1.当pattern的下一个字符不为'*'的时候，那么，直接匹配当前字符；如果成功，就接着匹配下一个；如果不成功，返回false；
			2.当pattern的下一个字符为'*'的时候，由于‘*’可以匹配0个或者多个字符，那么有如下几个情况：
				2.1.当‘*’匹配0个字符的时候，str字符不变，pattern往后移两位；
				2.2.当‘*’匹配1个/多个字符的时候，str往后移一位，pattern不变，这个时候又回到来2.1这种情况
	over～
	
	*/
	bool match(char* str, char* pattern){
		if(*str=='\0' && *pattern=='\0') return true;
		if(*str!='\0' && *pattern=='\0') return false;

		if(*(pattern+1)!='*'){
			if(*str==*pattern || (*str!='\0' && *pattern=='.')){
				return match(str+1,pattern+1);
			}
			else{
				return false;
			}
		}
		else{
			if(*str==*pattern || (*str!='\0' && *pattern=='.')){
				return match(str,pattern+2)|| match(str+1,pattern) ;
			}
			else{
				return match(str,pattern+2);
			}
		}
	}
};

int main(){
	char str[]="aaa";
	char pattern[]="ab*ac*a";
	Solution so1;
	bool ans=so1.match(str,pattern);
	if(ans) printf("true\n");
	else printf("false\n");
	return 0;
}