#include<iostream>
using namespace std;

#define ll long long
ll a[50000];
ll st[1000000];

void update(int )

int main(){
int n,q,t,x,y;
cin>>n;
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);

    cin>>q;
    while(q--){
        scanf("%d%d%d",&t,&x,&y)

        if(t==0) // Modify Ax into y
        {
            update(x,y);
        }

        //Else Print the max of range x,y
        else{
            rangeSumMaxQuery(0,n-1,x-1,y-1);
        }


    }

return 0;
}
