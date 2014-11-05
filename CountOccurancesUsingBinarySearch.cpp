// Program to count occurances of a number in Sorted Array Using binary Search
#include<iostream>
#include<cstdio>
using namespace std;
int a[1000000];
int count = 0;

int getLeft(int low,int high,int key){
int mid ,ans = -1;
while(low<=high){
	mid = low + (high-low)/2;

if(a[mid]>key)
		high = mid - 1;
	else if(a[mid]<key )
		low = mid + 1;
	else{
		ans = mid;
		high = mid -1;
    }
}
return ans;
}
int getRight(int low,int high,int key){
int mid , ans = -1;
while(low<=high){
	mid = low + (high-low)/2;
if(a[mid]>key){
	high = mid-1;
}
else if(a[mid]<key){
	low = mid + 1;
}
else {
	ans = mid;
	low = mid + 1;
}
}
return ans;
}

void countOccurances(int n,int key){
int x = getLeft(0,n-1,key);
int y = getRight(0,n-1,key);
cout<<"Left Position :"<<x<<endl;
cout<<"Right Position :"<<y<<endl;
if(x!=-1&&y!=-1&&a[x]==key&&a[y]==key)
	cout<<(y-x+1)<<endl;
else
	cout<<"Not found !"<<endl;

}

int main(){
int t,n,i,key;
cin>>t;
while(t--){
	cin>>n;
	for(i=0;i<n;i++) scanf("%d",&a[i]);
count=0;
cin>>key;
countOccurances(n,key);
}
return 0;
}
