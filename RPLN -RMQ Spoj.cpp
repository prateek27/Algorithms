#include<iostream>
#include<cstdio>
#include<climits>
#include<cmath>
using namespace std;

int arr[100000];
//int  st[200001];
int *st;

int makeSegmentTree(int ss,int se,int si)
{
    if(ss==se)
    {
        st[si]=arr[ss];
        return arr[ss];
    }

    int mid = (ss+se)/2;
    st[si] = min(makeSegmentTree(ss,mid,2*si+1),makeSegmentTree(mid+1,se,2*si+2));
    return st[si];
}

int RMQ(int ss,int se,int qs,int qe,int ci){
if(qs<=ss&&qe>=se)
    return st[ci];
if(se<qs||ss>qe)
    return INT_MAX;
int mid = (ss+se)/2;
return min(RMQ(ss,mid,qs,qe,2*ci+1),RMQ(mid+1,se,qs,qe,2*ci+2));
}

int main(){
int t,n,q,c=0;
cin>>t;
while(t--){
    c++;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int size=2*((int)pow(2,ceil((((int)log2(n))+1))));
    st = new int[size];
    makeSegmentTree(0,n-1,0);
    printf("Scenario #%d:\n",c);
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",RMQ(0,n-1,x-1,y-1,0));
    }
}
return 0;
}
