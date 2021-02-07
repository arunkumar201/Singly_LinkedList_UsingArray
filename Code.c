#include<stdio.h>
#include<stdlib.h>
void create(int a[],int n);
void display();
void insertAtbigin(); //Insert a node at the front of the linked list
void insertAtend();   //Insert a node at the end of the linked list
void deleteAtbigin(); //Delete the first node of the linked list
void delete_After_pos();  //Delete a node after specified position
void delete_Before_pos();//Delete a node before a specified position. 

struct node
{
 int data;
 struct node *link;
 
}*head=0;

void main()
{ int pos,pos1;
 int ch,n,a[43];
 while(1)
 {
  printf("\n\n singly linked list operations:\n");
  printf("1.create linked list");
  printf("\n2.display linked list");
  printf("\n3.insert at biginning ");
  printf("\n4.insert at end");
  printf("\n5.delete at biginning");
  printf("\n6.delete after a specified position");
  printf("\n7.delete at the before specified poition");
  printf("\n8.EXIT");
  
  printf("\nenter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: printf("enter the number of nodes:");
            scanf("%d",&n);
             printf("enter %d elements in the linked list\n",n);
            for(int i=0;i<n;i++)
            {
            scanf("%d",&a[i]);
            }
             create(a,n);
             break;
   case 2: display();
            break;
   case 3:  insertAtbigin();        
             break;
   case 4:  insertAtend();
             break;
   case 5:  deleteAtbigin();
             break;
   case 6:
          printf("enter the position:");
          scanf("%d",&pos);
          delete_After_pos(pos);
              break;
   case 7: 
          printf("enter the position:");
          scanf("%d",&pos1);  
      delete_Before_pos(pos1);
              break;
   case 8: exit(0);
             break;
   default:   printf("invalid choice");
                break;
     }

   }
}
void create(int a[],int n)
{
 struct node *temp,*p,*newnode;
 p=(struct node*)malloc(sizeof(struct node));
 p->data=a[0];
 p->link=NULL;
   head=p;
   temp=p;
 for(int i=1;i<n;i++)
 {
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=a[i];
  newnode->link=0;
  temp->link=newnode;
  temp=newnode;
 }
}
void display()
 { if(head==NULL)
        {
                printf("\nList is empty:\n");
        }
  struct node *temp;
  temp=head;
 
  printf("all elements are:\n");
  while(temp!=NULL)
  {
   printf("%d-> ",temp->data);
   temp=temp->link;
  }
 }
 
void insertAtbigin()
{  int x;
 struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
   if(temp==NULL)
   {
    printf("\nmemory can not allocate:");
   }
 else
 {
  printf("enter the new node data item:");
  scanf("%d",&x);
  temp->data=x;
  temp->link=head;
  head=temp;
   printf("after insert a data then display");
  display();
   }
}
void insertAtend()
{  int c;
 struct node *p,*q;
 q=head;
 p=(struct node*)malloc(sizeof(struct node));
 if(p==NULL)
 {
  printf("\n memory can not allocate");
 }
 else
  {
   printf("enter the data value for the node:");
   scanf("%d",&c);
   p->data=c;
   if(head==NULL)
   {
    head=p;
   }
   else
   {
    while(q->link!=NULL)
    {
     q=q->link;
    }
    q->link=p;
    p->link=0;
    }
   display();
  }
}
void deleteAtbigin()
{
 struct node *temp;
  temp=head;
  head=temp->link;
  temp->link=NULL;
  free(temp);
  printf("\nafter the deleting:");
  display();
}
void delete_After_pos(int pos)
{
 int i,loc;
 struct node *temp,*ptr;
 if(head==NULL)
 {
 printf("\nThe List is Empty:");
  exit(0);
  }
 else
   {
    if(pos==0)
     {
       ptr=head;
        head=head->link ;
         printf("\nThe deleted element is:%d\n",ptr->data);
        free(ptr);
       }
  else
  {
   ptr=head;
      for(i=0;i<pos;i++)
       {
         temp=ptr;
          ptr=ptr->link ;
           if(ptr==NULL)
           {
             printf("\nlocation not Found:\n");
           }
       }  
      temp->link=ptr->link;
   printf("\nThe deleted element is:%d:\n",ptr->data);
     display();
    free(ptr);
    }
  }   
 
}

void delete_Before_pos(int pos)
{
 int i;
 struct node *temp,*ptr;
 if(head==NULL)
 {
 printf("\nThe List is Empty:");
  exit(0);
  }
 else
   {
    if(pos==0)
     {
       ptr=head;
        head=head->link ;
         printf("The deleted element is:%d",ptr->data);
        free(ptr);
       }
  else
  {
   ptr=head;
      for(i=0;i<pos-2;i++)
       {
         temp=ptr;
          ptr=ptr->link ;
           if(ptr==NULL)
           {
             printf("\nlocation not Found:\n");
           }
       }  
      temp->link=ptr->link;
   printf("\nThe deleted element is:%d:\n",ptr->data);display();
    free(ptr);
    }
  }   
 
}


            
 
   
 
   
   
   

