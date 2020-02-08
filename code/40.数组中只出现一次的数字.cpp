/*
题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/

#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
	//方法一：使用快速排序。时间复杂度为:O(nlogn).
	void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		if(data.size()==0){
			return;
		}

		sort(data.begin(),data.end());
		for(int i=0;i<data.size()-1;i++){
			if(data[i]==data[i+1] && data[i]!=-1){
				data[i]=-1;
				data[i+1]=-1;
			}
		}

		vector<int > temp;
		for(int i=0;i<data.size();i++){
			if(data[i]!=-1){
				temp.push_back(data[i]);
			}
		}
		
		*num1=temp[0];
		*num2=temp[1];
		return;
	}

	//方法2：使用异或运算.没怎么看懂
	void FindNumsAppearOnce2(vector<int> data,int* num1,int *num2) {
		if(data.size()<2) return ;
      int size=data.size();
      int temp=data[0];
      for(int i=1;i<size;i++) temp=temp^data[i];
      if(temp==0) return;
      int index=0;
      while((temp&1)==0){
           temp=temp>>1;
           ++index;
      }
        
      *num1=*num2=0;
      for(int i=0;i<size;i++)
      {
           if(IsBit(data[i],index))
            *num1^=data[i];
           else
            *num2^=data[i];
          }
    }
    
     bool IsBit(int num,int index)
     {
      num=num>>index;
      return (num&1);
     }


};

int main(){
	int n;
	scanf("%d",&n);
	vector<int> data;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		data.push_back(x);
	}

	
	Solution so1;
	int temp=0;
	int *num1;
	int *num2;
	*num1=temp;
	*num2=temp;
	so1.FindNumsAppearOnce2(data,num1,num2);
	printf("%d %d\n",*num1,*num2);
	return 0;
}

