#include<iostream>
using namespace std;

struct node{
int data;
struct node*next;
};

//-------------------------------New Node
struct node*newNode(int data)
{
    struct node*node=new struct node;
    node->data=data;
    node->next=NULL;
    return node;
};
//----------------------------------Insert Front
void push(struct node**head,int data)
{
    if(*head==NULL)
        *head=newNode(data);
    else
    {
        struct node*temp= newNode(data);
        temp->next=*head;
        *head=temp;
    }

}
void print(struct node*node)
{
while(node!=NULL)
{
 cout<<node->data<<" -> ";
 node=node->next;
}
}
//--------------------------Pairwise swap
int getMiddle(struct node*node)
{
    struct node*slow=node;
    struct node*fast=slow->next;

        while(fast!=NULL&&fast->next!=NULL)
        {

            {
                slow=slow->next;
                fast=fast->next->next;
            }
        }

cout<<slow->data;
return 0;
};

int main(){
struct node*head=NULL;
for(int i=9;i>=1;i--)
    push(&head,i);

cout<<"Orginal LL :"<<endl;
print(head);


cout<<endl<<"Middle Element:"<<endl;
getMiddle(head);
//print(head);
return 0;
}
