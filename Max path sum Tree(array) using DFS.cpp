#include<iostream>
#include<vector>
#include<cstdio>
#include<climits>
#include<cstring>
using namespace std;


//Magic-sum on HackerEarth
vector<int> list[515];
int visited[515],ans,sum;


int dfs(int i,int a[],int firstNode=0){
visited[i]=1;

//If it is a leaf node , then update ans in the case the path starts and ends at the same node
if(list[i].size()==1)
    ans=max(ans,a[i]);

//If it is a leaf node and and not the starting leaf node.
if(list[i].size()==1&&!firstNode)
    return a[i];

int sum=INT_MIN;
for(int j=0;j<list[i].size();j++){
        if(!visited[list[i][j]])
            sum=max(sum,dfs(list[i][j],a));
    }
    return a[i]+sum;
}


int main(){
int t,n,i;
cin>>t;
while(t--){
    cin>>n;
    int a[n];
    assert(N>=1 && N<=511);

    if(n==1)
        {cin>>a[0];
        cout<<a[0]<<endl;
        continue;
        }

    for(i=0;i<n;i++)
        list[i].clear();
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<n/2;i++){
        list[i].push_back(2*i+1);
        list[i].push_back(2*i+2);
        list[2*i+1].push_back(i);
        list[2*i+2].push_back(i);
    }
     ans=INT_MIN;


    for(i=n/2;i<n;i++){
        //Apply DFS on all leaf nodes as the starting point.
        memset(visited,0,sizeof visited);
        ans = max(ans,dfs(i,a,1));
    }
    printf("%d\n",ans);
}
return 0;

}
