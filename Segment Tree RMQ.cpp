#include<iostream>
#include<cmath>
#include<climits>
#include<cstdio>
using namespace std ;

int min(int a,int b)
{
    return a>b?b:a;
}

int RMQUtil(int *st,int ss,int se,int qs,int qe,int index){

    if(qs<=ss&&qe>=se)
        return st[index];

    if(se<qs||qe<ss)
        return INT_MAX;

    int mid = (ss+se)/2;

    return min(RMQUtil(st,ss,mid,qs,qe,2*index+1),RMQUtil(st,mid+1,se,qs,qe,2*index+2));

}


int RMQ(int *st,int n,int qs,int qe){

    if(qs<0||qe>n-1||qs>qe){
        cout<<"Invalid Input";
        return -1;
    }

    return RMQUtil(st,0,n-1,qs,qe,0);
}



// si - starting index , ei - ending index , ci - current index
int makeSegmentTreeUtil(int *arr,int *st,int ss,int se,int ci){

    if(ss==se){
        st[ci]=arr[ss];
        return arr[ss];
    }

    int mid = (ss+se)/2;
    st[ci] = min(makeSegmentTreeUtil(arr,st,ss,mid,2*ci+1),makeSegmentTreeUtil(arr,st,mid+1,se,2*ci+2));

    return st[ci];
}


int*makeSegmentTree(int *arr,int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2,x) - 1;

    int *st = new int[max_size];
    makeSegmentTreeUtil(arr,st,0,n-1,0);
    return st;
}


int main(){
int i;
int arr[] = {1, -3, 2, 7, 9, 11};
int n = sizeof(arr)/sizeof(int);

int *st = makeSegmentTree(arr,n);
for(i=0;i<=11;++i)
    cout<<i<<" "<<st[i]<<endl;
cout<<RMQ(st,n,1,n-1);
return 0;
}
