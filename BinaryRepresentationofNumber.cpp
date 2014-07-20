#include<iostream>
#include<list>
#include<cstring>
using namespace std;



//This program prints the Binary Representation of a Number upto N (uses BFS traversal)
void printBinUptoN(int n){
if(n==0)
     return;
list<string> q;
q.push_back("1");


while(1){
string temp = q.front();
cout<<temp<<" "<<endl;
n--;
if(n==0) break;
q.pop_front();
q.push_back(temp+"0");
q.push_back(temp+"1");
}
}

int main(){
int n;
cin>>n;
printBinUptoN(n);

system("pause");
return 0;    
}
