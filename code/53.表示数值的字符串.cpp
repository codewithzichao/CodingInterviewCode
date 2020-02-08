/*
题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
	/*主要是要考察是否能够考虑问题全面。
	思路：分情况讨论：
	一、考虑字符串开头
		1.如果string为nullptr的话，返回false；
		2.如果string前面有空格，需要过滤掉空格；过滤掉空格之后，还需要判断指针是否到了字符串尾，如果是，返回false；
	
	二、进入正题，考虑字符串本身的各种情况
		设置三个标志：num，dot，nume，分别表示整数、小数、e是否存在，初始是false。
		1.如果当前指针指向的字符在['0','9']之间，说明是整数，那么，指针+1，num=true；
		2.如果当前指针指向的字符是‘.’的话，说明下一个将是小数，那么，如果在这之前，小数或者e就已经存在，那么返回false；否则，指针+1，dot=true；
		3.如果当前指针指向的字符是'e'/'E'的话，那么，如果在这之前，e/E已经存在 或者 没有整数，那么返回false；否则，指针+1，nume=true，
		再判断+1之后的指针指向的字符是否是+/-，如果是，那么指针+1；
		再判断+1之后的指针指向的字符是否是'\0'，如果是，那么返回false；
		4.如果字符是其他字符，那么，一律返回false；
		5.以上情况之外的，均返回true。
	
	over～
	*/
	bool isNumeric(char* string){
		if(string==nullptr) return false;
		while(*string==' ') string++;
		if(*string=='+' || *string=='-') string++;
		if(*string=='\0') return false;

		bool num=false,dot=false,nume=false;
		while(*string!='\0'){
			if(*string>='0' && *string<='9'){
				num=true;
				string++;
			}
			else if(*string=='.'){
				if(dot==true || nume==true){
					return false;
				}
				dot=true;
				string++;
			}
			else if(*string=='e' || *string=='E'){
				if(nume==true || num==false){
					return false;
				}
				nume=true;
				string++;
				if(*string=='+' || *string=='-'){
					string++;
				}
				if(*string=='\0'){
					return false;
				}
			}
			else{
				return false;
			}
		}
		return true;
	}
};

int main(){
	char string[]="5e2";
	Solution so1;
	bool ans=so1.isNumeric(string);
	if(ans) printf("true\n");
	else printf("false\n");
	return 0;
}