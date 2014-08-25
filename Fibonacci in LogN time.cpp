#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
#include<cstring>
#define ll long long
#define MOD 1000000007
using namespace std;
#define int long long

void multiply(int F[2][2],int M[2][2])
{
   ll x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  ll y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  ll z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  ll w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x%MOD;
  F[0][1] = y%MOD;
  F[1][0] = z%MOD;
  F[1][1] = w%MOD;

}

int power(int F[2][2],int n){
int M[2][2]={{1,1},{1,0}};
if(n==0||n==1)
    return 0;

power(F,n/2);
multiply(F,F);

if(n%2!=0)
multiply(F,M);
}


int fib(int n){

if(n==0)
    return 0;
int F[2][2]={{1,1},{1,0}};
power(F,n-1);
return F[0][0];
}

main(){
int t,n;
cin>>t;
while(t--){
    scanf("%lld",&n);
    printf("%lld\n",fib(n+2));
}
return 0;
}
