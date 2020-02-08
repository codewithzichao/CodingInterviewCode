/*
题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;

class Solution{
	public:
	/*
	1.最容易想到的思路是遍历字符串，每遇到一个空格，将将空格用“%20”填充，当然，在填充之前，需要将后面所有的字符都往后移动2个单位；这样的时间复杂度为O(n^2);
	2.使用双指针。步骤：1.计算出用“%20”填充后的长度；2.使用p2指向填充后的最后一个位置，使用p1指向原字符串最后一个位置；3.从后往前遍历，遇到空格，那么就用“%20”填充。
	时间复杂度为O(n).
	*/
	void replaceSpace(char *str,int length) {
		if(str==nullptr || length==0){//边界条件
			return;
		} 

		int originalLength=0;//统计原字符串的长度
		int blank=0;//统计空格数目
		int i=0;
		while(str[i]!='\0'){
			originalLength++;
			if(str[i]==' '){
				blank++;
			}
			i++;
		}

		int indexOfnew=originalLength+2*blank;//使用指针指向填充后的的最后一个位置
		int indexOforiginal=originalLength;//使用指针指向原字符串最后一个位置

		if(indexOfnew>length){//判断，当填充后，是否超过了字符串的最大容量
			return;
		}

		while(indexOforiginal>=0 && indexOforiginal<=indexOfnew){//开始填充
			if(str[indexOforiginal]==' '){
				str[indexOfnew--]='0';
				str[indexOfnew--]='2';
				str[indexOfnew--]='%';
			}
			else{
				str[indexOfnew--]=str[indexOforiginal];
			}
			indexOforiginal--;
		}

		return ;

	}
};

int main(){
	int length;
	scanf("%d",&length);
	char str[40];
	/*
	int s;
	scanf("%d",&s);*/
	cin.getline(str,13);//接受带空格的输入
	cout<<str<<endl;
	char * str1=&str[0];//指针
	Solution so1;
	so1.replaceSpace(str1,length);
	cout<<str<<endl;
	//printf("\n");
	return 0;

	
}