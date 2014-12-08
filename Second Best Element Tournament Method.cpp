#include<iostream>
#include<cstdio>
using namespace std;
/*
                0
	          /	   \
	       0       5
	     /   \     /  \
        2    0   12    5
*/

int a[]={0,0,5,2,0,12,5};

int func(int index,int n,int val)
{
    if(index>=n)
        return 10000000;
    if(a[index]!=val)
        return a[index];
    else
      return min(func(2*index+1,n,val),func((2*index+2),n,val));

}
int main(){

//Tournament method takes a complete binary tree so array as given as input

//Given first best elemnt - 0 ; Output Second Min Element - ie 2
cout<<"Second Min Element is "<<func(0,7,0);

}
