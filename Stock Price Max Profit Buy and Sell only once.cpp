#include<iostream>
#include<cstdio>
using namespace std;

int cum[100];

int func(int *a,int n){
int i,profit=0;

cum[n-1]=a[n-1];

for(i=n-2;i>=0;i--)
cum[i]=max(a[i],cum[i+1]);

for(i=0;i<n-1;i++)
    { profit=max(cum[i+1]-a[i],profit);}

return profit;
}

int main(){

int a[]={20, 30, 50, 10, 25, 50};
//Here by at Day 4 , sell at Day 6 , Profit 50 -10 = Rs.40
cout<<"PROFIT : "<<func(a,6)<<endl;
return 0;
}
