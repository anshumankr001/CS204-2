#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct node{
  int x,y;
  struct node *ptr;
};
struct node *createNode()
{
struct node *temp = (struct node *) malloc(sizeof(struct
node));
temp->ptr = NULL;
return temp;
}
void freeNode(struct node *node)
{
free(node);
}
void addStart(struct node **str, int x,int y) {
struct node *newNode;
newNode = createNode();
newNode->x = x;
newNode->y = y;
if(*str==NULL)
newNode->ptr=NULL;
else
newNode->ptr = *str;
*str = newNode;
}
void deleteStart(struct node **str) {
if(*str == NULL) {
  cout<<"-1"<<endl;
return;
}
else {
  //cout<<"0"<<endl;
struct node *temp = *str;
*str = (*str)->ptr;
free(temp);
}
}
int search(struct node *str, int x,int y){
struct node *temp;
temp = str;
ll num=0;
while(temp != NULL){
if(temp->x==x&&temp->y==y)
{
  return 1;
}
else temp = temp->ptr;
}
if(temp==NULL)
return 0;
}
int length(struct node *str)
{
  int len=0;
  while(str!=NULL)
  {
    str=str->ptr;
    len++;
  }
  return len;
}
void searchpoints(struct node *str,int d)
{
  ll flag=0,count=0;
  struct node *temp = str;
  while(temp!=NULL)
  {
    float k =(float) sqrt(temp->x*temp->x+temp->y*temp->y);
    if(k<=d)
      {//cout<<"("<<temp->x<<","<<temp->y<<")"<<endl;
    count++;
    flag=1;}
    temp = temp->ptr;
  }
  if(temp==NULL&&flag==0)
    cout<<"-1"<<endl;
  else 
    cout<<count<<endl;
}
void printList(struct node *start)
{
struct node *temp;
temp = start;
while(temp != NULL)
{
printf("%d %d", temp->x,temp->y);
cout<<endl;
temp = temp->ptr;
}
}
int main()
{
  ll t;
  cin>>t;
   struct node *head=NULL;
  for(ll i=0;i<t;++i)
  {
    ll n;
    cin>>n;
    if(n==1)
    {
      ll x,y;
      cin>>x>>y;
      addStart(&head,x,y);
    }
    else if(n==2)
    {
      deleteStart(&head);
    }
    else if(n==3)
    {
      ll x,y,flag1=0;
      cin>>x>>y;
      struct node *temp=head,*prev;
      if(temp!=NULL&&temp->x==x&&temp->y==y)
      {
        head = temp->ptr;
        free(temp);
        //cout<<"0"<<endl;
      }
      else
      {
      while(temp!=NULL&&(temp->x!=x||temp->y!=y))
      {
        prev = temp;
        temp = temp->ptr;
      }
      if(temp==NULL)
      {
        cout<<"-1"<<endl;
        flag1= 1;
      }
      if(flag1==0)
      {prev->ptr=temp->ptr;
      free(temp);
      //cout<<"0"<<endl;
    }}

  }
   else if(n==4)
    {
      ll a;
      cin>>a;
      searchpoints(head,a);
    }
    else if(n==5)
    {
      ll x,y;
      cin>>x>>y;
      ll ans = search(head,x,y);
      if(ans==1)
        cout<<"True"<<endl;
      else
        cout<<"False"<<endl;
    }
    else if(n==6)
    {
      int ans = length(head);
      cout<<ans<<endl;
    }
  }
  //printList(head);
}
