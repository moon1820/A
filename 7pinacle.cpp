#include <iostream>
#include<string.h>
using namespace std;

struct node
 {
  int PRN;
  char name[50];
  struct node* next;
 };
 
 
class info
 {
  public:
  int a;
  node *head=NULL;
  node *temp=NULL;
  char b[50];
  void addmember();
  void deletpresident();
  void deletemember();
  void deletesecretory();
  node* create();
  void addpresident();
  void print();
 };
 
 
node * info :: create()
 {
  node * p = new(struct node);
 
  cout <<"Enter PRN no.=";
  cin>>a;
  p->PRN= a;
 
  cout <<"Enter Student name=";
  cin>>b;
  strcpy(p->name,b);
  p->next = NULL;
 
 
  return(p);
  }

void info :: addmember()
 {
  node * p = create();
  if (head==NULL)
   {
    head = p ;
   }
 
  else
  {
   temp = head;
   while (temp->next!=NULL)
   {
    temp=temp->next;
   }
   
   temp -> next = p;
  }
 }
   
void info :: addpresident()
 {
  node * p = create();
 
  if (head==NULL)
   {
    p=head;
   }
   
  else
   {
    temp= head;
    head= p;
    head -> next = temp;
   }
 }

void info :: print()
 {
  temp=head;
  cout<<"   \n"<<"PRN"<<"   "<< "Name"<<"\n";
  while(temp ->next != NULL)
   {
    cout<<"    " <<temp -> PRN<<"    " << temp -> name<<"\n";
    temp= temp->next;
   }
   cout<<"    " << temp -> PRN<<"    "  << temp -> name<<"\n";
 }

void info :: deletpresident()
{
 node *p ;
 p=head;
 head= p->next ;
 p-> next =NULL;
 delete (p);
}
 

void info :: deletemember()
{
  node*p;
  int key;
  cout<<"Enter prn of the member to delete=";
  cin>> key;
  p=head;
  while(temp->PRN!=key)
  {
    temp=p;
    p=p->next;
  }
  temp->next=p->next;
  delete(p);
}


void info :: deletesecretory()
{
  node*p;
  p=head;
  head=p->next;
  p->next=NULL;
  delete(p);
}



int main()
 {
  info s;
  int ch;
  do
  {
  cout<<"MENU"<<"\n";
  cout<<"1.Add president"<<"\n";
  cout<<"2.Add member"<<"\n";
  cout<<"3.Add secratory"<<"\n";    
  cout<<"4. Print"<<"\n";
  cout<<"5.Delet president"<<"\n";
  cout<<"6.Delet member"<<"\n";
  cout<<"7.Delet secratory"<<"\n";
  cout<<"8.Exit"<<"\n";
  cout<<"Enter your choice";
  cin>> ch;
 
 
  switch(ch)
  {
   case 1: s.addpresident();
             break;
   
   case 2: s.addmember();
             break;
 
   case 3: s.addmember();
             break;
 
   case 4: s.print();
             break;
   
   case 5: s.deletpresident();
             break;
   
   case 6: s.deletemember();
             break;
   case 7: s.deletesecretory();
             break;
   case 8: exit(0);
   
   default : cout<<"wrong choice"<<"\n";
              break;
 }
 }
  while(ch!=8);
  return 0;
}
