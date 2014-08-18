#include<iostream>
#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long

//SuperTables on HackerEarth based on Binary Search.
int main(){
ll t,n,a,b,L,R,M;
ll ans;
cin>>t;
while(t--){
    cin>>a>>b>>n;
    L=1;
    R=max(a,b)*n;
    while(L<=R){
        ll mid = L + (R-L)/2;
        //No of factors till mid

        ll factors = mid/a + mid/b - mid*__gcd(a,b)/(a*b);
        if(n==factors)
        {
                ans = max( (mid/a)*a,(mid/b)*b);
                printf("%lld\n",ans);
                break;
        }
        else if(factors>n){
            L = mid;
        }
        else
            R = mid;

    }
}

return 0;
}
