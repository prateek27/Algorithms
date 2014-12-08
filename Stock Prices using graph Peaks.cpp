#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

#include<iostream>
#include<cstdio>
using namespace std;

int peak[100];

int func(int *a,int n){
peak[0]=a[0];

int j=1,i,profit=0;

for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;

for(i=1;i<n-1;i++){
     if(a[i]>a[i-1]&&a[i]>a[i+1])
        {   //cout<<"MAX"<<a[i]<<" ";
            peak[j++]=a[i];}

     if(a[i]<a[i-1]&&a[i]<a[i+1])
            {   //cout<<"MIN"<<a[i]<<" ";
                peak[j++]=a[i];
            }
}
peak[j]=a[n-1];

for(i=0;i<=j;i++)
    cout<<peak[i]<<" ";
cout<<endl;

if(peak[1]>peak[0]){
    for(i=1;i<=j;i+=2){
        profit+= peak[i]-peak[i-1];
        }
    }

else{
    for(i=2;i<=j;i+=2){
        profit+= peak[i]-peak[i-1];
        }
    }

return profit;
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
}*/

cout<<endl<<func(a,n);

return 0;
}
