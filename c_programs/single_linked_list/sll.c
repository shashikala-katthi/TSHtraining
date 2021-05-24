#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *begin=NULL;
//struct node **base;
void insert_at_begin(struct node **,int);
void insert_at_end(struct node **,int);
void display(struct node **);
void delete_from_begin(struct node **);
void delete_from_end(struct node **);
void insert_at_position(struct node **, int , int);
void delete_at_position(struct node **, int);
void distroy(struct node **);
void detect_loop(struct node **);
void reverse_list(struct node **);
void copy_list(struct node **);
 int main()
{
    int ch,data,pos;
struct node *start=NULL;

  //  base=&start;
  jump:  printf("1.insertion at begin 2.insertion at end 3.display 4.delete from begin 5.delete from end 6.insert_at_position 7.delete_at_position 8.distroy 9.detect_loop 10.reverse_list 11.copy_list 12.exit\n");
    scanf("%d",&ch);
    switch (ch)
    {
        case 1:
        printf("enter the data\n");
        scanf("%d",&data);
        insert_at_begin(&start,data);
        goto jump;
        case 2:
        printf("enter the data\n");
        scanf("%d",&data);
        insert_at_end(&start,data);
        goto jump; 
	case 3:
	display(&start);
	goto jump;
        case 4:
        delete_from_begin(&start);
        goto jump;
        case 5:
        delete_from_end(&start);
        goto jump;
	case 6:
	printf("enter the data and position\n");
        scanf("%d %d",&data,&pos);	
        insert_at_position(&start,pos,data);
        goto jump;
	case 7:
	printf("enter the position\n");
        scanf("%d",&pos);	
        delete_at_position(&start,pos);
        goto jump;
	case 8:
	distroy(&start);
	goto jump;
	case 9:
	detect_loop(&start);
	goto jump;
	case 10:
	reverse_list(&start);
	goto jump;
	case 11:
	copy_list(&start);
	display(&begin);
	goto jump;
        case 12:
        exit(0);
       default:printf("enter the number between 1-11");
        goto jump;
        
    }

    return 0;
}
void insert_at_begin(struct node **base,int data)
{
	struct node *temp,*n;
	temp=*base;
	if(temp==NULL)
	{
		temp= (struct node *)malloc(sizeof(struct node));
		temp->data=data;
		temp->next=NULL;
		*base=temp;	
	}
	else
	{
		n=(struct node *)malloc(sizeof(struct node));
		n->data=data;
		n->next=temp;
		*base=n;		
	}
}
void insert_at_end(struct node **base,int data)
{
	struct node *temp,*n;
	temp=*base;
	if(temp==NULL)
	{
		temp= (struct node *)malloc(sizeof(struct node));
		temp->data=data;
		temp->next=NULL;
		*base=temp;	
	}
	else
	{
		while(temp->next !=NULL)
			temp=temp->next;
		n=(struct node *)malloc(sizeof(struct node));
		n->data=data;
		n->next=NULL;
		temp->next=n;		
	}
}
void delete_from_begin(struct node **base)
{
	struct node *temp;
	temp=*base;
	if(temp==NULL)
	{
		printf("No elements ro delete");	
	}
	else
	{
		*base=temp->next;
		 free(temp);
		 temp=*base;		
	}
}
void delete_from_end(struct node **base)
{
	struct node *temp,*temp1;
	temp=*base;
	if(temp==NULL)
	{
		printf("No elements ro delete");	
	}
	else
	{
		while(temp->next !=NULL)
			{
				temp1=temp;
				temp=temp->next;
			}
		 free(temp);
		 temp1->next=NULL;
		 temp=*base;		
	}
}
void display(struct node **base)
{
	struct node *temp;
	temp=*base;
	if(temp==NULL)
	printf("no elements to display");
	else
	{ 
		while (temp->next!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
		printf("%d\n",temp->data);		
	}

}
void insert_at_position(struct node **base, int pos, int data)
{
printf("inside fun\n");	
struct node *temp,*n;
	temp=*base;
	if(temp==NULL)
	{
		temp= (struct node *)malloc(sizeof(struct node));
		temp->data=data;
		temp->next=NULL;
		*base=temp;	
	}
	else
	{
		for(int i=1;i<pos-1;i++)
			{
				printf("inside loop\n");			
				temp=temp->next;
			}
		n=(struct node *)malloc(sizeof(struct node));
		n->data=data;
		n->next=temp->next;
		temp->next=n;		
	}
}
void delete_at_position(struct node **base, int pos)
{
	struct node *temp,*temp1;
	temp=*base;
	if(temp==NULL)
	printf("no elements to display");
	else
	{ 
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		temp1=temp->next;
		temp->next=temp->next->next;
		free(temp1);
				
	}

}
void distroy(struct node **base)
{
	struct node *temp;
	temp=*base;
	if(temp==NULL)
	printf("no elements in the list");
	else
	{ 
		while (temp->next!=NULL)
		{
		*base=temp->next;
		 free(temp);
		 temp=*base;
		}
		free(temp);
		*base=NULL;
		printf("link is distroyed\n");		
	}
}
void detect_loop(struct node **base)
{
	struct node *temp1,*temp2;
	temp1=*base;
	temp2=temp1;
	while(temp1!=NULL && temp2!=NULL && temp2->next !=NULL)
	{
		temp1=temp1->next;
		temp2=temp2->next->next;
		if(temp1==temp2)
		{
			printf("LOOP IS FOUND\n");
			return 0;		
		}
	}
	
}
void remove_loop(struct node **base, struct node *loop_node)
{
    struct node *near = *base;
    struct node *far = *base;
    struct node *ptr = loop_node;
    struct node *prev = NULL;
 
    while(ptr->next != loop_node)
    {
        ptr = ptr->next;
        far = far->next;
    }
 
    prev = far;
    far = far->next;
 
    while(near != far)
    {
        prev = far;
        far = far->next;
        near = near->next;
    }
 
    prev->next = NULL;
}
 
void detect_and_remove_loop(struct node **base)
{
    struct node *slow = *base;
    struct node *fast = *base;
 
    while(slow && fast->next && fast->next->next)
    {
        if ((slow == fast->next) || (slow == fast->next->next ))
        {
            printf("Linked list has a loop.\n");
            remove_loop(*base, slow);
            return;
        }
 
        slow = slow->next;
        fast = fast->next->next;
    }
 
    printf("Linked list does not have any loop.\n");
}

/*void copy(struct node *q,struct node *s)
{
	if(q!=NULL)
	{
		*s=(struct node *)malloc(sizeof(struct node))
		*s->data=q->data;
		*s->next=NULL;
		copy(q->link,&((*s)->next));
	}
}
int compare(struct node *list1,struct node *list2)
{
	static int flag;
	if((list1==NULL)&&(list2==NULL))
	{
		flag =1;		
	}
	else
	{
		if((list1==NULL)||(list2==NULL))
		flag=0;
		if(list1->data != list2->data)
		flag=0;
		else
			compare(list1->next,list2->next);
	}
	return flag;
}*/
void reverse_list(struct node **base)
{
	struct node *tempprev,*tempnxt,*temp;
	tempprev=*base;
	tempnxt=*base;
	temp=*base;
	temp=temp->next;
	tempnxt=tempnxt->next;
	tempprev->next=NULL;
	while(tempnxt->next!=NULL)
	{	
		temp=temp->next;
		tempnxt->next=tempprev;
		tempprev=tempnxt;
		tempnxt=temp;
			
	}
	tempnxt->next=tempprev;
	*base=tempnxt;
}
void copy_list(struct node **base)
{
	struct node *temp,*temp1,*temp2;
		temp=*base;
		begin=NULL;
		temp1=NULL;
		if(temp==NULL)
		printf("NO ELEMTNS IN THE LIST\n");
		else
		{
			while(temp!=NULL)
			{
				if(temp1==NULL)
				{
					temp1=(struct node *) malloc(sizeof(struct node));
					temp1->data=temp->data;
					temp=temp->next;
					temp1->next=NULL;
					temp2=temp1;
					begin=temp1;		
				}
				else
				{
					temp1=(struct node *) malloc(sizeof(struct node));
					temp1->data=temp->data;
					temp=temp->next;
					temp2->next=temp1;
					temp1->next =NULL;
					temp2=temp1;
				}
			}
		}

	return 0;
}




