#include<bits/stdc++.h>
#include <numeric>
#define pb push_back
#define pob pop_back()
#define mp make_pair
#define all(v) v.begin(),v.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fin(i,n1,n2);for(ll i=n1;i<n2;i++)
#define fde(i,n1,n2);for(ll i=n1;i>n2;i--)
#define M 1000000007
using ll=long long;
using ld=long double;
using namespace std;
//Arpcoder


bool comp(pair <ll,ll> &a,pair <ll,ll> &b)
{
    if(a.first!=b.first)
    return a.first>b.first;
    else return a.second<b.second;
}

class Node
{
   public:
   ll data;
   Node *next;
   
   Node(ll Data)
   {
       data=Data;
       next=NULL;
   }
};

void InsertAtPosition(Node *&head,Node *&tail,ll pos,ll d)
{
    if(pos==1)
    {
       Node *temp=new Node(d); 
       temp->next=head;
       head=temp;
       return;
    }

    Node *temp=head;
    ll cnt=1;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }
    
    if(temp->next==NULL)
    {
       Node *NodeToInsert=new Node(d);
       temp->next=NodeToInsert;
       NodeToInsert->next=NULL;
       tail=NodeToInsert;
       return;
    }
    Node *NodeToInsert=new Node(d);
    NodeToInsert->next=temp->next;
    temp->next=NodeToInsert;
}

void print(Node *&head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

void Delete(Node *&head,ll pos)
{
    if(pos==1)
    {
        Node *q=head;
        head=head->next;
        free(q);
        return;
    }
    Node *p=head;
    Node *q=head->next;
    ll cnt=1;
    while(cnt<pos-1)
    {
        p=p->next;
        q=q->next;
        cnt++;
    }
    p->next=q->next;
    free(q);
}

int main()
{
       IOS;
       //we can do the following also-
       //Node *node1=new Node(data);
       //Node *head=node1;
       //Node *tail=node1;
       Node *head=new Node(3);
       Node *node1=new Node(4);
       Node *tail=new Node(5);
       head->next=node1;
       node1->next=tail;
       tail->next=NULL;
       print(head);
       InsertAtPosition(head,tail,4,6);
       print(head);
       Delete(head,1);
       print(head);
       //cout<<head->data<<" "<<tail->next<<" "<<head->next;
       return 0;
}       
       
