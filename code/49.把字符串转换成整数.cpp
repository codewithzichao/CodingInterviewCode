/*
题目描述
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0

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
	/*
	这道题很难！
	*/
 	enum Status{kValid = 0,kInvalid};
    //int g_nStatus = kValid;
     
    int StrToInt(string str) {
      	int g_nStatus = kInvalid;
        long long num = 0;
        const char* cstr = str.c_str();
        if( (cstr != NULL) && (*cstr != '\0') )
        {
            int minus = 1;
            if(*cstr == '-')
            {
                minus = -1;
                cstr++;
            }
            else if(*cstr == '+')
                cstr++;
             
            while(*cstr != '\0')
            {
                if(*cstr > '0' && *cstr < '9')
                {
                    g_nStatus = kValid;
                    num = num*10 + (*cstr -'0');
                    cstr++;
                    if( ((minus>0) && (num > 0x7FFFFFFF)) ||
                        ((minus<0) && (num > 0x80000000)) )
                    {
                        g_nStatus = kInvalid;
                        num = 0;
                        break;
                    }
                }
                else
                {
                    g_nStatus = kInvalid;
                    num = 0;
                    break;
                }
            }
             
            if(g_nStatus == kValid)
                num = num * minus;
             
        }
        return (int)num;
    }
};

int main(){
	string str;
	getline(cin,str);
	Solution so1;
	int ans=so1.StrToInt(str);
	cout<<ans<<endl;
	return 0;
}