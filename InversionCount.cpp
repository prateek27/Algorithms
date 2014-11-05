#include<iostream>
#include<cstdio>
using namespace std;
long long count;
int temp[200000];
int arr[200000];
void countInversions(int arr[],int low,int high);
void merge(int arr[],int low,int mid,int high);

void countInversions(int arr[],int low,int high){
int mid;
if(low<high){
	mid = low + (high-low)/2;
	countInversions(arr,low,mid);
	countInversions(arr,mid+1,high);
	merge(arr,low,mid,high);
}

}
void merge(int arr[],int low,int mid,int high){
int i , j , k ;
i=low;
k=low;
j=mid+1;

while(i<=mid&&j<=high){
if(arr[i]<arr[j]){
	temp[k++] = arr[i++];
}
else{
    temp[k++]=arr[j++];
    count+= mid - i + 1;
    }

}

while(i<=mid){
temp[k++] = arr[i++];
}
while(j<=high){
temp[k++] = arr[j++];
}


for(i=low;i<k;i++) arr[i] = temp[i];
}

int main(){
int i,t,n;
cin>>t;


while(t--){
cin>>n;

for(i=0;i<n;i++)
{ scanf("%d",&arr[i]); }
count = 0 ;
countInversions(arr,0,n-1);
printf("%lld\n",count);
}

return 0;
}
