#include<iostream>
#include<cstdio>
using namespace std;
//Problem - http://www.hackerearth.com/problem/algorithm/mehta-and-the-tricky-triplets/editorial/
#define ll long long
ll a[100005];
ll count[20];

ll nC3(ll n){
if(n<3)
    return 0;
ll ans ;
    ans = (n*(n-1)*(n-2))/6;
return ans;
}

int main(){
ll n,i;
cin>>n;
for(i=0;i<n;i++)
    scanf("%lld",&a[i]);

int c;
for(i=0;i<n;i++){
    ll num = a[i];
     c=0;
    while(num>0){
        ll rem = num%10;
        if(rem==2) c|=1;
        else if(rem==3) c|=2;
        else if(rem==5) c|=4;
        else if(rem==7) c|=8;
        num /= 10;
    }
    count[c]++;
}

ll numBits,answer=0;
//The i iteraters over the bit positions  and array positons.
for(i=1;i<16;i++){
        ll j = i ;
        numBits=0;
    //Just count the number of bits in that particular number at arr[i]
    while(j>0){
        if(j&1)
            numBits++;
        j=j/2;
    }

    //How many numbers after 2 contain 2..
    //How many numbers after 3 contain 3..
    //Like for 7 can come in 9,10,12,15.
    int total=0 ;
    for(ll k=i;k<16;k++){
            if((k&i)==i)
                total+=count[k];
        }

    //Include the positions having odd count and subtract having even count.
    if(numBits%2!=0)
        answer += nC3(total);
    else
        answer -= nC3(total);
}

cout<<answer;
}
