#include<stdio.h>
#include<stdlib.h>
void insertAtBeginning();
void insertAtEnd();
void insertAfter();
void deleteBeginning();
void deleteEnd();
void deleteSpecific();
void display();
void create();

struct Node
{
	int data;
	struct Node *next;
	struct Node *pev;
}*head = NULL,*tail=NULL;

int main()      
{
	int ch;
	    
	    while(1){
	    printf("\n\n---- circular Linked List(CLL) Menu ----");
	    printf("MENU\n1.Create\n2.Insert\n3.Delete\n4.Display\n5.Exit\n");
	    printf("Enter your choice(1-5):");
	    scanf("%d",&ch);
	    switch(ch)
	    {
			case 1:
	            create();
	            break;
	        case 2:
	                printf("\n---- Insert Menu ----");
	                printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at specified position\n4.Exit");
	                printf("\n\nEnter your choice(1-4):");
	                scanf("%d",&ch);
 
	                switch(ch)
	                {
	                    case 1: insertAtBeginning();
	                            break;
	                    case 2: insertAtEnd();
	                            break;
	                    case 3: insertAfter();
	                            break;
	                    case 4: exit(0);
	                    default: printf("Wrong Choice!!");
	                }
	                break;         
 
	        case 3: printf("\n---- Delete Menu ----");
	                printf("\n1.Delete from beginning\n2.Delete from end\n3.Delete from specified position\n4.Exit");
	                printf("\n\nEnter your choice(1-4):");
	                scanf("%d",&ch);
 
	                switch(ch)
	                {
	                    case 1: deleteBeginning();
	                            break;
	                    case 2: deleteEnd();
	                            break;
	                    case 3: deleteSpecific();
	                            break;
	                    case 4: exit(0);
	                    default: printf("Wrong Choice!!");
	                }
	                break;
	        case 4: display();
	                break;
	        case 5: exit(0);
			break;
	        default: printf("Wrong Choice!!");
	    }
	    
}
	    return 0;
}
void create()
{int ch;
struct Node *newNode,*temp;
temp=head;
	do{
	
	
	newNode=(struct Node*)malloc(sizeof(struct Node));
	printf("\nEnter the node value : ");
	scanf("%d",&newNode->data);
	newNode->next=NULL;
	newNode->pev=NULL;
	
	if(tail==NULL)
	head=tail=newNode;
	else
	{
		temp->next=newNode;
		newNode->pev=temp;
		temp=newNode;
	}
		temp=newNode;
		tail=temp;
	
	printf("Do you want to contiune press (Type 0)  : ");
  scanf("%d",&ch);
}while(ch==0);
}


void insertAtBeginning()
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	int value;
	printf("Enter any number:");
	scanf("%d",&value);
	newNode -> data = value;
	if(head == NULL)
	{
		head = newNode;
		newNode -> next = head;
		newNode->pev=NULL;
	}
	else
	{
		newNode -> next = head;
		newNode->pev=NULL;
		head = newNode;
	printf("\nInsertion success!!!");
}
}
void insertAtEnd()
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	int value;
	printf("Enter any number:");
	scanf("%d",&value);
	
   newNode -> data = value;
   if(head == NULL)
   {
	  head = newNode;
	  newNode -> next = head;
		newNode->pev=NULL;
   }
   else
   {
	  struct Node *temp = head;
		tail->next=newNode;
		newNode->pev=tail;
		newNode=tail;
   }
   printf("\nInsertion success!!!");   
}
void insertAfter( )
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	int a,location;
	printf("Enter any number:");
	scanf("%d",&a);
	printf("Enter key:");
	scanf("%d",&location);
	newNode -> data = a;
   if(head == NULL)
   {      
	  head = newNode;
	  newNode -> next = head;
		newNode->pev=NULL;
   }
   else
   {
	  struct Node *temp = head;
		for (int i=0;i==location;i++)
		{
			printf("%d",i);
			temp = temp -> next;
			if(i == location){
				temp->next=newNode;
				newNode->next=temp->next->next;
				newNode->pev=temp;
				temp->next->next->pev=newNode;
				printf("\nInsertion success!!!");
	     }
	     else
	     {
	        printf("Hey dude recheck the key value :D");
	     }
		   
	  
   }
}
}
void deleteBeginning()
{
   if(head == NULL)
	  printf("List is Empty!!! Deletion not possible!!!");
   else
   {
	  struct Node *temp = head;
	  if(temp -> next == head)
	  {
	     head = NULL;
	     free(temp);
	  }
	  else{
	     head = head -> next;
	     free(temp);
	  }
	  printf("\nDeletion success!!!");
   }
}
void deleteEnd()
{
   if(head == NULL)
	  printf("List is Empty!!! Deletion not possible!!!");
   else
   {
	  struct Node *temp1 = head, *temp2;
	  if(temp1 -> next == head)
	  {
	     head = NULL;
	     free(temp1);
	  }
	  else{
	     while(temp1 -> next != head){
	        temp2 = temp1;
	        temp1 = temp1 -> next;
	     }
	     temp2 -> next = head;
	     free(temp1);
	  }
	  printf("\nDeletion success!!!");
   }
}
void deleteSpecific()
{
	int delValue;
	printf("Enter any number:");
	scanf("%d",&delValue);
   if(head == NULL)
	  printf("List is Empty!!! Deletion not possible!!!");
   else
   {
	  struct Node *temp1 = head, *temp2;
	  while(temp1 -> data != delValue)
	  {
	     if(temp1 -> next == head)
	     {
	        printf("\nGiven node is not found in the list!!!");
	    
	     }
	     else
	     {
	        temp2 = temp1;
	        temp1 = temp1 -> next;
	     }
	  }
	  if(temp1 -> next == head){
	     head = NULL;
	     free(temp1);
	  }
	  else{
	     if(temp1 == head)
	     {
	        temp2 = head;
	        while(temp2 -> next != head)
	           temp2 = temp2 -> next;
	        head = head -> next;
	        temp2 -> next = head;
	        free(temp1);
	     }
	     else
	     {
	        if(temp1 -> next == head)
	        {
	           temp2 -> next = head;
	        }
	        else
	        {
	           temp2 -> next = temp1 -> next;
	        }   
	        free(temp1);
	     }
	  }
	  printf("\nDeletion success!!!");
   }
}
void display()
{
	    struct Node *temp;
	    if(head==NULL)
	    {
	            printf("\nList is empty:\n");
	            return;
	    }
	    else
	    {
	            temp=head;
	            printf("\nThe List elements are:\n");
	            do
	            {
	                    printf("%d\t",temp->data );
	                    temp=temp->next ;
	            }while(temp !=NULL);
	    }
}
