#include<iostream>
#include<cstdio>
using namespace std;

int a[1000005];

int main(){
int m,n,i;
cin>>m>>n;

for(i=0;i<m;i++){
    scanf("%d",&a[i]);
    }
    a[m]=0;

    int index=0;
    int ans =0 ;
    while(index!=m-1){
        int temp = min(a[index],a[index+1]);
        a[index] -= temp;
        a[index+1] -= temp;
        ans+=2*temp;

        if(a[index+1]>a[index])
            index=index+1;
        else{
            swap(a[index],a[index+1]);
            index=index+1;
            }
    }
    if(a[index])
        ans+=1;

    if(ans>=n)
        printf("YES");
    else
        printf("NO");

return 0;
}
