#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

#include<iostream>
#include<cstdio>
using namespace std;

//In this problem , price of buffloe is given on different days.Ram can buy and sell atmost once buffloe at time.
//There is a price with each buy and sell operation

int func(int *a,int n,int cost){
int with[100];
int without[100];

with[0] = 0 -a[0] - cost;
without[0] = 0;
int i;

//DP Solution : With means Ram has bufflo on day i , previously had it our buys it on day i
 // Without : Without means Ram doesnt have a bufflo , previously dont had it or sold it on day i.

for(i=1;i<n;i++){
    with[i] = max(with[i-1],without[i-1] - a[i]-cost);
    without[i] = max(without[i-1],with[i-1] + a[i] - cost );
}
//return max(with[n-1],without[n-1]);
return without[n-1];
}


int main(){
int n=10;
int a[]={11 ,7 ,10, 9, 13, 14, 10, 15, 12, 10};
/*cout<<"Enter no of days: ";
cin>>n;
int a[n+1];
int i;
cout<<"Enter prices :";

for(i=0;i<n;i++){
cin>>a[i];
} */

int cost = 2;
cout<<endl<<func(a,n,cost);

return 0;
}
