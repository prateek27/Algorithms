/* Problem : HORRIBLE (Spoj) */
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <memory>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))
#define CLEAR(a) memset((a),0,sizeof(a))
#define INF 1000000000
#define PB push_back
#define ALL(c) (c).begin(), (c).end()
#define pi 2*acos(0.0)
#define SQR(a) (a)*(a)
#define MP make_pair
#define MAX 110
#define si(n) scanf("%d",&n);
#define sl(n) scanf("%lld",&n);
#define MOD 1000000007
#define printl(n) ("%lld\n",n);
#define ll long long



struct node{
ll sum;
int lazy;
};

node tree[300000];
int arr[100005];

void init(int idx,int ss,int se){
tree[idx].sum = arr[ss];
tree[idx].lazy = 0;
}

node combine(struct node left,struct node right)
{
 node temp;
    temp.sum = left.sum + right.sum;
    temp.lazy = 0;
 return temp;
}


void build(int idx,int ss,int se){
if(ss==se){
    init(idx,ss,se);
    }
    else{
        int mid = ss + (se-ss)/2;
        build(2*idx+1,ss,mid);
        build(2*idx+2,mid+1,se);
        tree[idx] = combine(tree[2*idx+1],tree[2*idx+2]);
        }
}


void lazyProp(int idx,int ss,int se){
    if(tree[idx].lazy==0)
        return ;
    if(ss!=se){
        int left=2*idx+1 ; int right = left + 1;
        tree[left].lazy+=tree[idx].lazy;
        tree[right].lazy+=tree[idx].lazy;
        tree[idx].sum += ((se-ss+1)*tree[idx].lazy);
       // cout<<tree[idx].sum
        tree[idx].lazy = 0 ;
    }
    else
    {   //Do this for Leaf Nodes
        tree[idx].sum += tree[idx].lazy;
        tree[idx].lazy = 0 ;
    }
}

void update(int idx,int ss,int se,int qs,int qe,int val){
lazyProp(idx,ss,se);
if(qs>se || qe < ss)
    return;
if(ss>=qs && se <= qe){
    tree[idx].lazy +=val;
    lazyProp(idx,ss,se);
    return;
    }
if(ss!=se){
    int left = 2*idx +1 ; int right = left+1; int mid = ss + (se-ss)/2;
    update(left,ss,mid,qs,qe,val);
    update(right,mid+1,se,qs,qe,val);
    tree[idx]=combine(tree[left],tree[right]);
    }
}

node query(int idx,int ss,int se,int qs,int qe){
lazyProp(idx,ss,se);
// Four types of cases are possible
if(ss>=qs && se <= qe)
    return tree[idx];

int mid = ss + (se-ss)/2;
int left = 2*idx+1;
int right = left + 1;

if(qe<=mid){
    return query(left,ss,mid,qs,qe);
    }
if(qs>mid)
    return query(right,mid+1,se,qs,qe);

return combine(query(left,ss,mid,qs,qe),query(right,mid+1,se,qs,qe));
}

int main(){
int t,n,c,ch,p,q,v,i;
si(t);
while(t--){
    si(n); si(c);
    CLEAR(arr);

    FOR(i,0,3*n)
        {
            tree[i].sum = tree[i].lazy = 0;
        }
    build(0,0,n-1);
     //FOR(i,0,2*n)
        //cout<<tree[i].sum<<" ";
        //cout<<endl;
    while(c--){
        si(ch);
        if(ch==0){
            si(p); si(q); si(v);
            update(0,0,n-1,p-1,q-1,v);
        }
        else{
            si(p); si(q);
            printf("%lld\n",query(0,0,n-1,p-1,q-1).sum);
        }
    }

}

return 0;
}

