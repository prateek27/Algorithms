#include<iostream>
#include<list>
#include<cstdio>
using namespace std;


int customers[402];
int tables[202];
bool isPresent[402];

int findIndex(int s,int e,int cust){

int firstOcc = -1;
for(int i=s;i<=e;i++)
{
    if(customers[i]==cust)
        {firstOcc=i;
            break;
        }
}
return firstOcc;
}

int main(){
int t,i;
cin>>t;
int n,c;

while(t--){
cin>>n>>c;
int count=0;
int size=0;
int cno;

for(i=0;i<402;i++)
    isPresent[i]=false;
for(i=0;i<202;i++)
    tables[i]=0;

for(i=1;i<=c;i++)
{
scanf("%d",&cno);
customers[i]=cno;
}

int k=1;
int ans=0;
for(i=1;i<=c;i++){

    if(isPresent[customers[i]]==true)
        continue;


    else{

    ans++;


    if(k==n+1){
        int replaceWith = -1;
        int trueIndex = -1 ;
        int idx,j;
        for(j=1;j<k;j++)
        {   idx = findIndex(i+1,c,customers[j]);
            if(idx==-1)
                {
                    replaceWith=j;
                    break;
                 }
            else{
                if(idx>replaceWith)
                    replaceWith=j;
            }
       }
    isPresent[customers[replaceWith]]=false;
    isPresent[customers[i]]=true;
    tables[replaceWith]=customers[i];

    }

    else{
    tables[k++]=customers[i];
    isPresent[customers[i]]=true;
    }
}

}

printf("%d\n",ans);
}
return 0;
}
