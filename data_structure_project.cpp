//******************************************************************PROJECT ON DATA STRUCTURE*********************************************************************************************//

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<math.h>
#include<stdlib.h>
using namespace std;
# define max 10
#define SIZE 10
int item,temp,ch;
int stack[max],qu[max],q[max];
int count=0,c=0;
int top=-1;

struct node               // structure for singly linked list and  singly circular linked list.
{
        int data;
        struct node *next;
};
struct node *s;

struct DLL                //structure for doubly linked list and circular doubly linked list.
{
        int data;
        struct DLL *next;
        struct DLL *prev;
};
struct DLL *st, *start,*last;


class Array
{
	private:
		int arr[10], size, pos, value,i,s;
	public:
		void create();
		void del();
		void search();
		void insertion();
		void sort();
		void display();
};

void Array :: create()		//ARRAY DATA STRUCTURE
{
	cout<<"enter the size of array:\n";
	cin>>size;
	cout<<"enter the "<<size<<" elements in array:\n";
	for( i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	
        cout<<"array elements are:"<<endl;

        for(i=0;i<size;i++)
        {
                cout<<arr[i]<<" ";
        }
        cout<<endl;

	
}

void Array :: display()
{
	
	cout<<"The array elements are"<<endl;
	for(i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
}
void Array :: insertion(){

	
	cout<<"enter position where you want to insert element:\n";
	cin>>pos;
	cout<<"enter element to insert at"<<pos<<" position:\n";
	cin>>value;
	if(pos>=size)
		cout<<"array is full "<<endl;
		for(i=size-1;i>=pos-1;i--)
		{
			arr[i+1]=arr[i];
		
		}
		arr[pos-1]=value;
		size=size+1;
	cout<<"element inserted successfully:\n";
	
	display();
}

void Array :: del()
{
	
	int count=0,b[50],j;
	cout<<"\nenter position where you want to delete any element:\n";
	cin>>pos;
	cout<<"enter element to delete:\n";
	cin>>value;
	for(i=pos-1;i<size-1;i++)
	{
		arr[i]=arr[i+1];
	}
	size=size-1;
	cout<<value<<" element deleted successfully"<<endl;
	cout<<"Array elements after deletion"<<endl;
	display();
	
}

void Array :: search()
{
	int k=0;
	cout<<"enter element to search:\n";
	cin>>s;
	for(i=0;i<size;i++)
	{
		if(s==arr[i])
		{	
			cout<<s<<" element is found at"<<i+1<<" position:\n";
			k=1;
		}
		
	}
	if(k==0)
		cout<<"element not found:\n";
	
}
void Array :: sort()
{
        int tmp=0;
        int j,i;
        cout<<"sorting array elements in ascending oredr:\n";
        for(i=0;i<size;i++)
        {
                for(j=i+1;j<size;j++)
                {
			if(arr[j]<arr[i])
			{
                                tmp=arr[i];
                               	arr[i]=arr[j];
                                arr[j]=tmp;
			}
                      
                }
        }

	cout<<"after sorting the array elements are:\n";
	display();
}
//end of array  data structure

class simple_queue		//SIMPLE QUEUE DATA STRUCTURE
{
        private:
                int item,front,rear;
        public:
		simple_queue()
		{
			front=-1;
			rear=-1;
		}

                void enqueue();
                void dequeue();
                void display();
                void search();
                void sort();
};

void simple_queue :: enqueue()
{

        if(rear== max-1)
                cout<<"queue is full:\n";
        else
        {
                if(front==-1)
                {
                        front=0;
                }
                cout<<"enter element to insert:\n";
                cin>>item;
                rear++;
                qu[rear]=item;
		cout<<"element inserted in queue"<<endl;
        }
}


void simple_queue :: dequeue()
{

                if(front== -1 || front>rear)
                {
                        cout<<"queue is empty:\n";
                }
                else
		{
			cout<<" element  deleted from queue is:-"<<qu[front]<<endl;
                        front++;
                }

}

void simple_queue :: display()
{
        int i;
        if(front==-1)
        {
                cout<<" queue underflow:\n";
        }
        else
        {
                cout<<" Queue elements are:\n";
                for(i=front;i<=rear;i++)
                {
                        cout<<qu[i]<<" ";
                }
        }
	cout<<endl;
}

void simple_queue :: search()
{
                int s,i,x,j,t=0;
                int a=0;
                cout<<"enter element to search:\n";
                cin>>s;
                if(front==-1 || front>rear)
                        cout<<"queue is empty:\n";
                else
                {
                        for(i=front;i<=rear;i++)
                        {
                                a++;
                        }
                        i=0;
                        while( i<a && s!=qu[i]){
                        i++;
                        }
                             if(i<a)
                                {
                                     cout<<" element is found in position: "<<i+1<<endl;

                                }
                                else
                                        cout<<"element not found:\n";
                }
}

void simple_queue :: sort()
{
        int tmp=0;
        int j,i;
        cout<<"sorting queue elements in ascending oredr:\n";
        for(i=front;i<=rear;i++)
        {
                for(j=i+1;j<=rear;j++)
                {
                        if(qu[j]<qu[i])
                        {
                                tmp=qu[i];
                                qu[i]=qu[j];
                                qu[j]=tmp;
                        }
                }
        }
        for(i=front;i<=rear;i++)
        {
                cout<<qu[i]<<endl;
        }
}
//end simple queue data structure.

class circular_queue		//CIRCULAR QUEUE DATA STRUCTURE
{
        private:
		int item,c,front,rear;
        public:
		circular_queue()
		{
			front=-1;
			rear=-1;
		}
                void enqueue();
                void dequeue();
                void display();
		void searching();
};

void circular_queue :: enqueue()
{
        if((rear+1)%max==front)
        {
                cout<<"queue is full:\n";
        }
        else
        {

                if(front==-1)
                {
                        front=0;
                }
                cout<<"enter element to insert:\n";
                cin>>item;
                rear = (rear +1)% max;
                q[rear] = item;
                c++;
        }
}

void circular_queue :: dequeue()
{
        if(front==-1)
                cout<<"circular queue is empty:\n";
	else
        {
                cout<<q[front]<<" element is deleted:\n";
                front = (front +1)% max;
                c--;
        }
}
void circular_queue :: display()
{
        int i=front;
	if(front==-1)
		cout<<"queue is empty"<<endl;
	else
	{
		cout<<"Circular Queue elements are"<<endl;
		while(i!=rear)
		{
			cout<<q[i]<<" ";
			i=(i+1)%max;
		}
		cout<<q[i];
		cout<<endl;
	}

}


void circular_queue :: searching()
{
	int item,c=0;
	cout<<"enter element you want to serach"<<endl;
	cin>>item;
	for(int i=front;i<=rear;i++)
	{
		if(item==q[i])
		{
			cout<<"element"<<item<<" found at "<<i+1<<" position"<<endl;
			c++;
		}
	}
	if(c==0)
		cout<<item<<" is not present in circular queue"<<endl;
	else
		cout<<item<<" found "<<c<<" times in circular queue"<<endl;
}
//end circular queue data structure.

class dequeue	//double ended queue 
{
   int a[20],f,r;
   public:
      dequeue();
      void insert_at_beg(int);
      void insert_at_end(int);
      void delete_fr_front();
      void delete_fr_rear();
      void show();
};

dequeue::dequeue() 
{
   f=-1;
   r=-1;
}

void dequeue :: insert_at_end(int i) 
{
   if(r>=SIZE-1) 
      cout<<"\n insertion is not possible, overflow!!!!";
   else 
   {
      if(f==-1) {
         f++;
         r++; } 
      else {
         r=r+1;
      	   }
      a[r]=i;
      cout<<"\nInserted item is"<<a[r];
   }
}

void dequeue :: insert_at_beg(int i) 
{
   if(f==-1) 
   {
      f=0;
      a[++r]=i;
      cout<<"\n inserted element is:"<<i;
   } 
    else if(f!=0) {
      a[--f]=i;
      cout<<"\n inserted element is:"<<i;
   } 
    else {
      cout<<"\n insertion is not possible, overflow!!!";
   }
}

void dequeue :: delete_fr_front() 
{
   if(f==-1) 
   {
      cout<<"deletion is not possible::dequeue is empty";
      return;
   }
   else 
   {
      cout<<"the deleted element is:"<<a[f];
      if(f==r) {
         f=r=-1;
         return;
      } 
       else
         f=f+1;
   }
}

void dequeue :: delete_fr_rear() 
{
      if(f==-1) 
      {
         cout<<"deletion is not possible::dequeue is empty";
         return;
      }
      else {
         cout<<"the deleted element is:"<<a[r];
         if(f==r) {
            f=r=-1;
         } else
            r=r-1;
      }
}

void dequeue :: show() 
{
      if(f==-1) 
      {
         cout<<"Dequeue is empty";
      } 
      else {
         for(int i=f;i<=r;i++) {
            cout<<a[i]<<" ";
         }
      } 
 }
//end double ended queu data structure.

class stack1	//stack data structure
{

        public:
                stack1()
                {
                        top=-1;
                }
                void push(int a[], int b);
                void pop();
                void display();
		
};

void stack1 :: push(int stack[], int item)
{
        if(top==max-1)
                cout<<" stcak is full:\n";
        else
        {
                top++;
                stack[top]=item;
        }
}

void stack1 :: pop()
{

        if(top==-1)
                cout<<" stack is empty:\n";
        else
        {
                temp=stack[top];
                cout<<temp<<" element deleted:\n";
                top--;
        }
}

void stack1 :: display()
{
        if(top==-1)
                cout<<" stack is empty:\n";
        else
        {
                cout<<" stcak elements are:\n";
                for(int i=top;i>=0;i--)
                {
                        cout<<stack[i]<<" ";
                }
        }

}

//implement queue using stack
class Stack
{
	private:
    		int top;
    		
    public:
		int a[10];
		char input[20];
	Stack()
	{
		top=-1;
	}
	void push(int x);
	int pop();
	int isEmpty();
	int evaluate(char input[]);
};

void Stack::push(int x)
{
    if(top >= 10)
    {
        cout << "Stack Overflow \n";
    }
    else
    {
        a[++top] = x;
        //"Element Inserted into Stack\n";
    }
}

int Stack::pop()
{
    if(top < 0)
    {
        cout << "Stack Underflow \n";
        return 0;
    }
    else
    {
	
        int d = a[top--];
        return d;
    }
}

int Stack::isEmpty()
{
    if(top < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


class queueue
{
	public:
		Stack S1,S2;
		void enqueue(int x);
		int dequeue();
};

void queueue :: enqueue(int x) 
{
    S1.push(x);
    cout << "Element Inserted into Queue\n";
}

int queueue :: dequeue() 
{
    int x, y;
    while(!S1.isEmpty())
    {
    	x = S1.pop();
    	S2.push(x);
    } 
    y = S2.pop();
    cout<<"element deleted is :- "<<y<<endl;
    while(!S2.isEmpty()) 
    {
        x = S2.pop();
        S1.push(x);
   }
	return y;
     cout<<"eleement deletd is :- "<<y<<endl;
}//end implementation of stack using queue


//implement stack using queue
class STACK
{
   public:
        queue<int> Q1,Q2;
		void push(int x);
		int pop();
};

void STACK :: push(int x)
{
        while(!Q1.empty())
        {
                Q2.push(Q1.front());
		Q1.pop();
        }
        Q1.push(x);
        while(!Q2.empty())
        {
             	Q1.push(Q2.front());
		Q2.pop();
        }
	cout<<"element inserted into Stack"<<endl;
}
int STACK :: pop()
{
	int x;
	if(Q1.empty())
	{
		cout<<"stack underflow"<<endl;
	}
        x = Q1.front();
	Q1.pop();
	return x;
	cout<<"deleted element is:- "<<x<<endl;
	
}//end implementation of stack using queue.

int Stack :: evaluate(char input[])	//postfix evaluation using stack
{
        int i,top=-1;
        int p,b,c,value;
        for(i=0;i<strlen(input);i++)
        {
                if(input[i]<='9' && input[i]>='0')
                {
                        push(input[i]-'0');
                }
                else
                {
                        b=pop();
                        p=pop();
                        switch(input[i])
                        {
                                case '+':
                                        c=p+b;
                                        push(c);
                                        break;
                                case '-':
                                        c=p-b;
                                        push(c);
                                        break;
                                case '*':
                                        c=p*b;
                                        push(c);
                                        break;
                                case '/':
                                        c=p/b;
                                        push(c);
                                        break;
                                case '^':
                                        c=pow(p,b);
                                        push(c);
                                        break;
                                default:
                                        cout<<" inavlid:\n";
                        }
                                                      
    		}
	}
   value= pop();
        cout<<"answer= "<<value<<endl;

}


class single_list	//Singly linked list
{
        public:
                void last_node();
                void second_node();
                void insert_front();
                void insert_end();
                void insert_pos(int x,int pos);
                void delete_front();
                void delete_end();
                void delete_pos();
                void search_data();
                void rev();
                void display();
                single_list()
                {
                        s=NULL;
                }
};
void single_list::last_node()
{


        if(s==NULL)
        {
                cout<<"linked list is empty:\n";
        }
        else
        {
                while(s->next!=NULL)
                {
                        s=s->next;
                }
        cout<<s<<endl;
        }
}

void single_list:: second_node()
{
        struct node *p;
        if(s==NULL)
        {
                cout<<"linked list is empty:\n";
        }
        else
        {

                while(s->next!=NULL)
                {
                        p=s;
                        s=s->next;
                }
                cout<<p<<endl;
        }
}

void single_list::  insert_end()
{
        struct node *p,*s1;
        int data,x;
        cout<<"enter:\n";
        cin>>x;
        p=(struct node*)malloc(sizeof(struct node));
        p->data=x;
        p->next=NULL;


        if(s==NULL)
        {
            // cout<<"linked list is empty:\n";
             s=p;
             s->next=NULL;
         }
	else
	{
            s1=s;
            while(s1->next!=NULL)
            {
                 s1=s1->next;
            }
	s1->next=p;                                                                                                                                                                                  p->next=NULL;                                                                                                                                                                           cout<<"element inserted at last:\n";
        }
}
void single_list:: insert_front()
{
        struct node *p,*temp;
            int data,x;
        cout<<"enter element at front\n";
        cin>>x;
        p=(struct node*)malloc(sizeof(struct node));
        p->data=x;
        p->next=s;
        s=p;
        cout<<"element inserted at beginning:\n";
}

void single_list::insert_pos(int x,int position)
{
        struct node *ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data=x;
        int i;
        struct node *temp=s;
        if(position==1)
        {
                ptr->next=temp;
                s=ptr;
    
        }
        for(i=1;i<position-1;i++)
        {
                temp=temp->next;
        }
        ptr->next=temp->next;
        temp->next=ptr;
}

void single_list:: display()
{
        struct node *print=s;
        int data,c=0;
        cout<<"\n linked list is:\n";
        cout<<endl;
        while(print!=NULL)
        {
                cout<<print->data<<" ";
                print=print->next;
                c++;
        }
}

void single_list:: delete_end()
{
        struct node *p,*s1;
        if(s==NULL)
        {
                cout<<"linked list is empty:\n";
        }
        else
        {
                s1=s;
                while(s1->next!=NULL)
                {
                        p=s1;
                        s1=s1->next;
                }
                p->next=NULL;
                free(s1);
                s1==NULL;
                cout<<"Last element deleted."<<endl;
        }

}
void single_list:: rev()
{
        struct node *pre, *cur, *s1, *print;


        if(s!=NULL)
        {
                pre = s;
                cur = s->next;
                s   = s->next;

                pre->next = NULL;//MAKE FIRST NODE AS LAST NODE.

                while(s!=NULL)
                {
                        s=s->next;
                        cur->next=pre;
                        pre=cur;
                        cur=s;
                }
                s=pre;
	display();
	}
}
void single_list :: delete_front()
{

        struct node *p;
        if(s==NULL)
        {
                cout<<"linked list is emptyt:\n";
        }
        else
        {
                p=s;
                s=s->next;
                free(p);
                p=NULL;
                cout<<" element deletd at front:\n";
        }
}


void single_list:: delete_pos()
{
        int i=1,pos,c=0;
        struct node *s1,*ptr;
        cout<<"enter pos:\n";
        cin>>pos;
        if(s==NULL)
        {
                cout<<"linked list is empty:\n";
        }
        s1=s;
        if(pos==1)
        {
                s=s1->next;
        }
        else
        {

                while(s1!=NULL)
                {
                        s1=s1->next;
                        c++;

                }
                if(pos>0 && pos<=c)
                {
                        s1=s;
                        for(i=1;i<pos;i++)
			{
                                ptr=s1;
                                s1=s1->next;
                        }
                        ptr->next=s1->next;
                }
                else
                {
                        cout<<"position not exist:\n";
                }
                free(s1);
                s1=NULL;
                cout<<"element deleted at "<<pos<<" position"<<endl;
        }
}


void  single_list:: search_data()
{
        int value,pos=0;

        if(s==NULL)
        {
                cout<<"linked list is empty:\n";
        }
        cout<<"enter value to serach:\n";
        cin>>value;
        struct node *start;
        bool flag=false;
        start=s;
        while(start!=NULL)
        {
                pos++;

                if(start->data==value)
                {
                  flag=true;
                cout<<"element found:"<<pos<<"at\n";
                }
                start=start->next;
        }
        if(!flag)
        {
                cout<<"element not found:\n";
        }
}
//end singly linked list.

class circular	//Singly circular linked list.
{
        public:
                void insert_front();
                void insert_end();
                void insert_pos(int x, int pos);
                void display(struct node*);
                void delete_front(struct node*);
                void delete_end();
                void delete_pos();
                circular()
                {
                        s=NULL;
                }
};

void circular :: insert_front()
{
        int data,x;
        struct node *p,*s1;
        cout<<"enter element:\n";
        cin>>x;
        p=(struct node *)malloc(sizeof(struct node));
        p->data=x;
        p->next=NULL;
        if(s==NULL)
        {

           s=p;
                p->next=s;
        }
                s1=s;
        while(s1->next!=s)
        {
                s1=s1->next;
        }
        s1->next=p;
        p->next=s;
        s=p;
        cout<<"element has inserted in front:\n";
       
}


void circular :: insert_end()
{
        int data,x;
        struct node *p,*s1;
        cout<<"enter element:\n";
        cin>>x;
        p=(struct node *)malloc(sizeof(struct node));
        p->data=x;
        p->next=NULL;
        if(s==NULL)
        {
		
  	           s=p;
                 p->next=p;
        }

                s1=s;
                while(s1->next!=s)
                {
                        s1=s1->next;
                }
                s1->next=p;
                p->next=s;
        cout<<"element has inserted at end:\n";
       

}

void circular::insert_pos(int x,int position)
{
        struct node *ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data=x;
        int i;
        struct node *temp=s;
        if(position==1)
        {
                ptr->next=temp;
                s=ptr;

        }
        for(i=1;i<position-1;i++)
        {
                temp=temp->next;
        }
        ptr->next=temp->next;
        temp->next=ptr;
     
}

void circular :: delete_front(struct node*)
{
        struct node *p=s, *next=s;
        if(s==NULL)
        cout<<"empty"<<endl;
        if(p->next==p)
        {
                s=NULL;
        return;
        }
        while(p->next!=s){
                p=p->next;
                        next=p->next;
        }
        p->next=next->next;
        s=p->next;
        free(next);
        return;


}

void circular :: delete_end()
{
        struct node *s1,*p;
        if(s==NULL)
        {
                cout<<"linked list is empty:\n";
        }
        s1=s;
        while(s1->next!=s)
        {
                p=s1;
                s1=s1->next;
        }
        p->next=s;
        free(s1);
        s1==NULL;
        cout<<"element deleted at end:\n";
                                             
}



void circular:: delete_pos()
{
        int i=1,pos,c=0;
        struct node *s1,*p;
        cout<<"enter pos:\n";
        cin>>pos;
        if(s==NULL)
        {
                cout<<"linked list is empty:\n";
        }
        s1=s;
        while(s1->next!=NULL && i<pos)
        {
                i++;
                p=s1;
                s1=s1->next;
        }
        p->next=s1->next;
        free(s1);
        s1=NULL;
        cout<<"element deleted at "<<pos<<" position:\n";
        
}
void circular :: display(struct node*)
{

        struct node *print;
        int n=1;
        if(s==NULL)
                cout<<"empty"<<endl;
        else
        {

                print=s;
                do{

                cout<<print->data<<" ";
                print=print->next;
                n++;
                }while(print!=s);
        }

}
//end singly circular linked list.

class doubly	//doubly linked list
{
        public:
                void insert_beg();
                void insert_end();
                void insert_pos();
                void delete_beg();
                void delete_end();
                void delete_pos();
                void display();
};

void doubly :: insert_beg()
{
        struct DLL *p;
        int x;
        cout<<"enter elment:\n";
        cin>>x;
        p=(struct DLL *)malloc(sizeof(struct DLL));
        p->data=x;
        p->next=NULL;
        p->prev=NULL;
        if(st==NULL)
        {
                cout<<"linked list empty:\n";
                st=p;
        }
        else
        {
                st->prev=p;
                p->next=st;
                st=p;
                cout<<"element inserted at beginning:\n";
        }
}


void doubly :: insert_end()
{
        struct DLL *p,*s1;
        int x;
        cout<<"eneter element:\n";
        cin>>x;
        p=(struct DLL *)malloc(sizeof(struct DLL));
        p->data=x;
        p->next=NULL;
        p->prev=NULL;
        if(st==NULL)
        {
                cout<<"linked list empty:\n";
        }
        else
        {
                s1=st;
                while(s1->next!=NULL)
                {
                        s1=s1->next;
                }
                s1->next=p;
                p->prev=s1;
                cout<<" element inserted at end:\n";
        }
}

void doubly :: insert_pos()
{
        struct DLL *p,*tmp,*q;
        int i=1,pos,x;
        cout<<"enter element:\n";
        cin>>x;
        p=(struct DLL *)malloc(sizeof(struct DLL));
        p->data=x;
        p->next=NULL;
        p->prev=NULL;
        cout<<"enter position:\n";
        cin>>pos;
        if(st==NULL)
        {
                cout<<"linked list empty:\n";
        }

                q=st;
                tmp=p;
                tmp->data=x;
                if(q->next==NULL)
                {
                        q->next=tmp;
                        tmp->next=NULL;
                        tmp->prev=q;
                }
                else
                {
                tmp->next=q->next;
                tmp->next->prev=tmp;
                q->next=tmp;
                tmp->prev=q;
                }

                cout<<"element inserted at "<<pos<<" position:\n";

}
                          

void doubly :: delete_beg()
{
        struct DLL *p;
        if(st==NULL)
        {
                cout<<"linked list empty:\n";
        }
        else
        {
        p=st;
        st=st->next;
        st->prev=NULL;
        free(p);
        p=NULL;
        cout<<"element delted at first:\n";
        }
}

void doubly :: delete_end()
{
        struct DLL *p,*s1;
        if(st==NULL)
        {
                cout<<"linked list empty:\n";
        }
        else
        {
                s1=st;
                while(s1->next!=NULL)
                {
                        p=s1;
                        s1=s1->next;
                }
                p->next=NULL;
                s1->prev=NULL;
                free(s1);
                s1=NULL;
        }
        cout<<"element delted at last:\n";
}

void doubly :: delete_pos()
{
        struct DLL *p,*s1,*ptr;
        int i=1,pos,c=0;
        cout<<"enter position:\n";
        cin>>pos;
        if(st==NULL)
        {
                cout<<"linked list empty:\n";
        }
        else{
                s1=st;
                while(s1!=NULL)
                {
                        s1=s1->next;
                        c++;

                }
                if(pos>0 && pos<=c)
                {
                        s1=st;
                        for(i=1;i<pos;i++)
                        {
                                ptr=s1;
                                s1=s1->next;
                        }
                        ptr->next=s1->next;
                }
                else
                {
                        cout<<"position not exist:\n";
                }
                free(s1);
                s1=NULL;
                cout<<"element deleted at "<<pos<<" position"<<endl;
        }


}
void doubly :: display()
{
        struct DLL *print;
        print=st;
        int data;
        if(st==NULL)
        {
                cout<<" linked list empty:\n";
        }
        else
        {
                cout<<"linked list is:\n";

                while(print!=NULL)
                {
                        cout<<print->data<<" ";
                        print=print->next;
                }
                cout<<endl;
        }
}
//end doubly linked list.

class circular_doubly		//circular doubly linked list
{
        public:
                circular_doubly()
                {
                        start=NULL;
                        last =NULL;
                }
        void insert_end(struct DLL*, int x);
        void insert_front(struct DLL*, int x);
        void display();
        void insert_pos();
        void delete_end();
        void delete_pos(int pos);
        void delete_front();
        struct DLL* create_node(int);
};

struct DLL*  circular_doubly :: create_node(int x)
{
        count++;
        struct DLL *p;
        p=(struct DLL *)malloc(sizeof(struct DLL));
        p->data=x;
        p->next=NULL;
        p->prev=NULL;
        return p;
}

void circular_doubly :: insert_end(struct DLL*, int x)
{
        struct DLL* p;
        p= create_node(x);
        if(start==last && start==NULL)
        {
                start=last=NULL;
                start->next= last->next = NULL;
                start->prev= last->prev= NULL;
        }
        else{
                last->next=p;
                p->prev=last;
                last=p;
                start->prev=last;
                last->next=start;
        }
        cout<<"element inserted at end"<<endl;
}

void circular_doubly :: insert_front(struct DLL*, int x)
{
        struct DLL *p;
        p= create_node(x);
        if(start==last && start==NULL)
        {
                start=last=p;
                start->next= last->next= NULL;
                start->next= last->prev=NULL;
        }
        else{
                p->next=start;
                start->prev=p;
                start=p;
                start->prev=last;
                last->next=start;
        }
        cout<<"element inserted at front"<<endl;
}
void circular_doubly :: delete_pos(int position)
{
    if(start==NULL)  return;

    if(position==1)
    {
        delete_front();
        return;
    }

    DLL *current = start;
    DLL *temp;
    int count = 0;

    do
    {
        count++;
        temp = current;
        current = current->next;
    }   while(current->next != start && count<position-1);

    if(count==position-1)
    {
        if(current==last)
        {
            delete_end();
            return;
        }

        temp->next = current->next;
        current->next->prev = temp;
        free(current);
        return;
        cout<<"element deleted at "<<position<<" position"<<endl;
    }

    cout<<"position not exist"<<endl;
}



void circular_doubly :: display()
{
    if(start==NULL)  return;

    DLL *current = start;
        cout<<"linked list is"<<endl;
    do
    {
        cout<<current->data<<" ";
        current = current->next;
    }   while(current !=start);


}
void circular_doubly :: insert_pos()
{
   int v, pos, i;
   cout<<endl<<"Enter the element to be inserted: ";
   cin>>v;
   cout<<endl<<"Enter the position of element inserted: ";
   cin>>pos;
   struct DLL *p, *s, *ptr;
   p = create_node(v);
   if (start == last && start == NULL)
   {
      if (pos == 1)
      {
         start = last = p;
         start->next = last->next = NULL;
         start->prev = last->prev = NULL;
      }
      else
      {
         cout<<"Position out of range"<<endl;
         count--;
         return;
      }
   }
   else
   {
      if (count < pos) {
        cout<<"Position out of range"<<endl;
         count--;
         return;
      }
      s = start;
      for (i = 1;i <= count;i++) {
         ptr = s;
         s = s->next;
         if (i == pos - 1) {
            ptr->next = p;
            p->prev= ptr;
            p->next= s;
            s->prev = p;
            cout<<"Element inserted"<<endl;
            break;
         }
      }
 }  
}
 
void circular_doubly :: delete_front()
{
    if(start==NULL)  return;

    DLL *temp = start;

    last->next = start->next;
    start = start->next;
    start->prev = last;

    free(temp);
}

void circular_doubly :: delete_end()
{
    if(start==NULL)  return;

    DLL *temp = start;
    DLL *current = start;

    while(current->next != start)
    {
        temp = current;
        current = current->next;
    }
        temp->next= start;
        last = temp;
    start->prev = last;
    free(current);
}
//end circular doubly linked list.

struct tree		//Binary tree implementation
{
        int data;
        struct tree *left;
        struct tree *right;
};
struct tree* root;
class Binary_tree
{
        public:
                Binary_tree()
                {
                        root=NULL;
                }
                void insert(struct tree*&,int);
                void preorder(struct tree*);
                void postorder(struct tree*);
                void inorder(struct tree*);
                void leafprint(struct tree*);
                int num_node(struct tree*);
                int internal(struct tree*);
                int FindHeight(struct tree*);
                void mirror(struct tree*);
};

struct tree *newNode(int x)
{
        struct tree* p;
        p=(struct tree*)malloc(sizeof(struct tree));
        p->data=x;
        p->left=NULL;
        p->right=NULL;
        return p;

}

void Binary_tree :: preorder(struct tree* p)
{
        if(p==NULL)
                return;
        cout<<p->data<<" ";
        preorder(p->left);
        preorder(p->right);
}

void Binary_tree :: postorder(struct tree *p)
{

    if (p == NULL)
        return;
    postorder(p->left);
    postorder(p->right);
    cout<<p->data<<" ";
}

void Binary_tree :: inorder(struct tree* p)
{
        if (p == NULL)
                return;
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
}

void Binary_tree :: leafprint(struct tree* root)
{
    if(root==NULL)
        return;

    if(!root->left && !root->right)  {
        cout<<root->data<<" ";
        return;
        }
     if(root->left)
                leafprint(root->left);
      if(root->right)
                leafprint(root->right);

}

int Binary_tree :: internal(struct tree *root)
{

     if(root != NULL)
     {
         internal(root->left);
         if((root->left != NULL) || (root->right != NULL))
         {
             c++;

         }
        internal(root->right);
     }
	return c;
}

void Binary_tree ::insert(tree *&root,int val)
{
        if(root==NULL)
        {
                root=newNode(val);
                return;
        }

        if(val<=root->data)
        {
                insert(root->left,val);
        }
        else
        {
                insert(root->right,val);
       }
}

static int t=0;
int Binary_tree ::  num_node(struct tree *root)
{
    if(root != NULL)
    {
        num_node(root->left);
        t++;
        num_node(root->right);
    }
    return t;
   cout<<t;
}

int Binary_tree :: FindHeight(tree* root)
{
        if(root==NULL)
                return 0;

        else
        {
                int lb=FindHeight(root->left);
                int rb=FindHeight(root->right);
                if(lb > rb)
                        return lb+1;
                else
                        return rb+1;
        }
}



void Binary_tree ::  mirror(struct tree* root)
{
  if (root != NULL)
    {
        struct tree* temp;
        /*first traversing the left subtree */
        mirror(root->left);
        /* Traversing the right subtree. */
        mirror(root->right);

        /* swap the left and right child of all the nodes to create
 *           * a mirror image of a tree*/

        temp = root->left;
        root->left  = root->right;
        root->right = temp;

    }
}
//end Binary tree


struct tree* newnode( int item)	// Binary Search Tree Implementation
{

        struct tree* ptr;
        ptr =(struct tree*) malloc(sizeof(struct tree));
        ptr->data=item;
        ptr->left=NULL;
         ptr->right=NULL;
        return ptr;
}

struct tree* inorder(struct tree *root)
{
        struct tree* temp=root;
        if(temp!=NULL)
        {
                inorder(root->left);
                cout<<root->data<<" ";
                inorder(root->right);
        }

}

struct tree* preorder(struct tree *root)
{
        struct tree* temp=root;
        if(temp!=NULL)
        {
                cout<<root->data<<" ";
                preorder(root->left);
                preorder(root->right);
        }
}

struct tree* postorder(struct tree *root)
{
        struct tree* temp=root;
        if(temp!=NULL)
        {
                postorder(root->left);
                postorder(root->right);
                cout<<root->data<<" ";
        }
}
void   insert(struct tree* &root, int data)
{

        if(root==NULL)
        {
                root= newnode(data);
        }
        else if(root->data > data)
        {
                insert(root->left,data);
        }
        else
        {
                insert(root->right,data);
        }

}
void  findmin(struct tree *t)
{
        if(t==NULL)
        {
                cout<<"tree empty:\n";
        }
        else if(t->left==NULL)
        {
                cout<<"minimum element is:-"<<t->data<<endl;
        }
        else
        {
                 findmin(t->left);
        }
}

void findmax(struct tree *t)
{

        if(t==NULL)
        {
                cout<<"tree empty:\n";
        }
        else if(t->right==NULL)
        {
                cout<<"maximum element is :-"<<t->data<<endl;
        }
        else
        {
                 findmax(t->right);
        }
}

struct tree * minval(struct tree* root)
{
        while(root->left!=NULL)
        {
                root=root->left;
        }
        return root;
}
struct tree* deletenode(struct tree* root, int data)
{
        if(root==NULL)
        {
                cout<<" tree empty:\n";
        }
        else if(data < root->data)
        {
                root->left = deletenode(root->left, data);

        }
        else if(data > root->data)
        {
                root->right= deletenode(root->right, data);
        }
        else
        {
                /*case 1: no child*/

                if(root->left==NULL)
                {
                        struct tree *temp = root->right;
                         free(root);
                        root=NULL;
                        return temp;

                }
                /*case 2: one child*/
                else if(root->right==NULL)
                {
                        struct tree *temp= root->left;
                        free(root);
                        root=NULL;
                        return temp;

                }
                /*case 3: two child*/
                else{
                        struct tree *temp;
                        temp = minval(root->right);
                        root->data = temp->data;
                        root->right= deletenode(root->right, temp->data);

                }


        }
        return root;
        cout<<"element successfully deleted:\n";
}

//end Binary Search TREE

class sort	//sorting in array data structure
{
	public:
		int hold, size,array[10];
		int m,n,temp,index,small,flag,a,t;
	public:
		sort()
		{
			flag=0;
		}
		void insert();
		void bubble_sort();
		void quick_sort(int,int);
		void insertion_sort();
		void selection_sort();
};

void sort :: bubble_sort()	
{
 	cout<<"enter the size of array"<<endl;
	cin>>size;
	cout<<"enter "<<size<<" elements in array"<<endl;
	for(m=0; m<size; m++) 
	{
		cin>>array[m];
	}
	cout<<endl;
	cout<<"Orignally entered array by the user is: "<<endl;
	for( n=0; n<size; n++)
	{
		cout<<array[n]<<" ";
	}
	cout<<endl;
	
	for( m=0; m<size-1; m++)
	{
		for( n=0; n<size-m-1; n++) 
		{
		  if(array[n]>array[n+1])
		  {
			temp=array[n];
			array[n]=array[n+1];
			array[n+1]=temp;
		   }
		}
	}
	cout<<"Sorted Array is: "<<endl;
	for(m=0; m<size;m++)
	{
		cout<<array[m]<<" ";
	}
	cout<<endl;
}

void sort :: insertion_sort()
{

        cout<<"enter the size of array"<<endl;
        cin>>size;
        cout<<"enter "<<size<<" elements in array"<<endl;
        for(m=0; m<size; m++)
        {
                cin>>array[m];
        }
        cout<<endl;
        cout<<"Orignally entered array by the user is: "<<endl;
        for( n=0; n<size; n++)
        {
                cout<<array[n]<<" ";
        }
        cout<<endl;

    	for (m=1;m<size;m++) {
        t = array[m];
        n = m - 1;

        while (n >= 0 && array[n] > t) {
            array[n + 1] = array[n];
            n = n - 1;
        }
        array[n + 1] = t;
        
    }

    cout << "\n\nSorted Data :";
    for (m = 0;m < size; m++) {
        cout<<array[m]<<" ";
}
cout<<endl;
}

void sort :: insert()
{

        cout<<"enter the size of array"<<endl;
        cin>>size;
        cout<<"enter "<<size<<" elements in array"<<endl;
        for(m=0; m<size; m++)
        {
                cin>>array[m];
        }
        cout<<endl;
        cout<<"Orignally entered array by the user is: "<<endl;
        for( n=0; n<size; n++)
        {
                cout<<array[n]<<" ";
        }
        cout<<endl;
	quick_sort(0,size-1);
	cout<<"Aftre Quick sorting elements are"<<endl;
	for(m=0;m<size;m++)
	{
		cout<<array[m]<<" ";
	}
}


void sort :: quick_sort(int f, int l) 
{
    int i, j, t, p = 0;

    if (f < l) {
        p = f;
        i = f;
        j = l;

        while (i < j) {
            while (array[i] <= array[p] && i < l)
                i++;
            while (array[j] > array[p])
                j--;
            if (i < j) {
                t = array[i];
                array[i] = array[j];
                array[j] = t;
            }
        }

        t = array[p];
        array[p] = array[j];
        array[j] = t;
        quick_sort(f, j - 1);
        quick_sort(j + 1, l);
    }
}

void sort :: selection_sort()
{
  cout<<"enter the size of array"<<endl;
        cin>>size;
        cout<<"enter "<<size<<" elements in array"<<endl;
        for(m=0; m<size; m++)
        {
                cin>>array[m];
        }
        cout<<endl;
        cout<<"Orignally entered array by the user is: "<<endl;
        for( n=0; n<size; n++)
        {
                cout<<array[n]<<" ";
        }
        cout<<endl;

	cout<<"Sorting array using selection sort...\n";
    	for(m=0; m<(size-1); m++)
    	{
        small = array[m];
        for(n=(m+1); n<size; n++)
        {
            if(small>array[n])
            {
                small = array[n];
                flag++;
                index = n;
            }
        }
        if(flag!=0)
        {
            temp = array[m];
            array[m] = small;
            array[index] = temp;
        }
        flag=0;
    }
    cout<<"Now the Array after sorting is :\n";
    for(m=0; m<size; m++)
        cout<<array[m]<<" ";
}

//end of sorting.

int main()
{
	system("clear");
	sort z;
	int ch,t,r,p;
	x2:
	do{
	cout<<"*************************************************ALL IN ONE DATA STRUCTURE****************************************"<<endl;
	cout<<endl;
	cout<<"					1.Array Data Structure\n"<<endl;
	cout<<"					2.Simple Queue Data Structure\n"<<endl;
	cout<<"					3.Circular Queue Data Structure\n"<<endl;
	cout<<"					4.Double ended Queue Data Structure\n"<<endl;
	cout<<"					5.Implementaion of Queue using Stack\n"<<endl;
	cout<<"					6.Stack Data Structure \n"<<endl;
	cout<<"					7.Implementation of stack using Queue\n"<<endl;
	cout<<"					8.Postfix Evaluation Of stack\n"<<endl;
	cout<<"					9.Singly Linked List\n"<<endl;
	cout<<"					10.Circular Singly Linked list\n"<<endl;
	cout<<"					11.Doubly Linked List\n"<<endl;
	cout<<"					12.Circular Doubly Linked List\n"<<endl;
	cout<<"					13.Binary Tree Data Structure\n"<<endl;
	cout<<"					14.Binary Search Tree\n"<<endl;
	cout<<"					15.Bubble sort\n"<<endl;
	cout<<"					16.Insertion Sort\n"<<endl;
	cout<<"					17.Selection sort\n"<<endl;
	cout<<"					18.Quick sort\n"<<endl;
	cout<<"					19.EXIT"<<endl;
	cout<<"enter your choice:-";
	cin>>ch;
	cout<<endl;
	switch(ch)
	{
		case 1:
			{
			system("clear");
			Array a;
			cout<<"&>>>>>>>>>>>>>>>>>>>>>>>>> ARRAY DATA STRUCTURE <<<<<<<<<<<<<<<<<<<<<<<<<<<&"<<endl;
			cout<<endl;
			cout<<"ARRAY:- An Array is finite ,ordered and collection of similar type data elements.\n";
			cout<<endl;
			do{
			cout<<"@*************************OPERATION ON ARRAY*************************@"<<endl;
			cout<<"	1.Create Array\n2.Insertion\n3.deletion\n4.searching\n5.Sorting\n6.Display\n7.Back to menu\n8.EXIT"<<endl;
			cout<<"		enter your choice:-\n";
			cin>>p;
			switch(p)
			{
				case 1:
					a.create();
					break;
				case 2:
					a.insertion();
					break;
				case 3:
					a.del();
					break;
				case 4:
					a.search();
					break;
				case 5:
					a.sort();
					break;
				case 6:
					a.display();
					break;
				case 7:
					goto x2;
					break;
				case 8:
					exit(0);
					break;
				default:
					cout<<"invalid choice entered"<<endl;
			}
			}while(p!=0);
			}
			break;
		case 2:
			{
			system("clear");
			simple_queue q;
			cout<<"$<><><><><><><><><><><>Queue data structure<><><><><><><><><><><>$"<<endl;
			cout<<endl;
			cout<<"QUEUE :-Queue is a linear data structure in which the first element is inserted from one end called the REAR(also called tail), and the removal\n";
			cout<<" of existing element takes place from the other end called as FRONT(also called head).\n";
			cout<<"queue follows the FIFO(First in First Out) data structure, which means that element inserted first will be removed first.\n"<<endl;
			do{
			cout<<"********************Operations on simple queue********************"<<endl;
					
                	cout<<" \n1. Insertion\n2. Deletion \n3.Display\n4. search\n5.sort\n6.Back to menu\n7.EXIT"<<endl;
                	cout<<" 	Enter your choice:- ";
                	cin>>r;
			cout<<endl;
                	switch(r)
                	{	
                        	case 1:
                                	q.enqueue();
                                	break;

                        	case 2:
                                	q.dequeue();
                               	 	break;
                        	case 3:
                                	q.display();
                                	break;
                        	case 4:
                                	q.search();
                               		 break;
                        	case 5:
                                	q.sort();
                                	break;
				case 6:
					goto x2;
					break;
				case 7:
					exit(0);
					break;
                       		 default:
                                	cout<<" invalid choice entered:\n";
                	}

        		}while(r!=6);
			}
			break;
		case 3:{
				system("clear");
				cout<<"**********************operation on circular queue*****************"<<endl;
				cout<<endl;
				    int ch;
				 circular_queue d;
       				 do{
        				cout<<"1.Insert\n2.delete\n3.searching\n4.display\n5.Back to menu\n6.EXIT\n";
					cout<<endl;
        				cout<<"		enter your choice:- ";
        				cin>>ch;
					cout<<endl;
        				switch(ch)
       					 {
               				 case 1:
                        			d.enqueue();
                       				 break;
               				 case 2:
                        			d.dequeue();
                        			break;
                			case 3:
                     			        d.searching();
                        			break;
					case 4:
						d.display();
						break;
					case 5:
						goto x2;
						break;
					case 6:
						exit(0);
						break;
					
                			default:
                        			cout<<"invalid choic:\n";
        			}
        			}while(ch!=0);
			
			}
			break;
		case 4:{
				system("clear");
				 int c,i;
      				dequeue d;
      				do{
					cout<<"**************Operations on Dequeue***************"<<endl;
					cout<<endl;
      					cout<<"\n 1.insert at beginning";
      					cout<<"\n 2.insert at end";
      					cout<<"\n 3.show";
      					cout<<"\n 4.deletion from front";
      					cout<<"\n 5.deletion from rear";
      					cout<<"\n 6.exit";
					cout<<"\n 7.Back to menu"<<endl;
      					cout<<"\n 	enter your choice:-";
      					cin>>c;
					cout<<endl;
      					switch(c) {
         				case 1:
            					cout<<"enter the element to be inserted";
            					cin>>i;
            					d.insert_at_beg(i);
         					break;
         				case 2:
            					cout<<"enter the element to be inserted";
            					cin>>i;
            					d.insert_at_end(i);
         					break;
         				case 3:
            					d.show();
         					break;
         				case 4:
            					d.delete_fr_front();
         					break;
         				case 5:
            					d.delete_fr_rear();
        					 break;
      					case 6:
            					exit(0);
         					break;
					case 7:
						goto x2;
						break;
         				default:
            					cout<<"invalid choice";
         					break;
      						}
   				} while(c!=7);
			}
			break;
		case 5:{
				int c;
				queueue r;
				do{
				cout<<"****************Implementation of queue using stack*****************"<<endl;
				cout<<endl;
				cout<<"1.insert\n2.delete\n3.Back to menu\n4.EXIT"<<endl;
				cout<<endl;
				cout<<"enter your choice:- ";
				cin>>c;
				cout<<endl;
				switch(c)
				{
					case 1:
						cout<<"enter element in queue"<<endl;
						cin>>item;
						r.enqueue(item);
						break;
			
					case 2:
						r.dequeue();
						break;

					case 3:
						goto x2;
						break;
					case 4:
						exit(0);
						break;
					
					default:
						cout<<"invalid choice"<<endl;
				}
				}while(c!=0);
   				break;
			}
		case 6:{
			system("clear");
			cout<<"*:::::::::::::::::::::::::::::::Stack Data Structure::::::::::::::::::::::::::::::::*"<<endl;
			cout<<endl;
			cout<<"STACK :- Stack is a linear data structure which follows a particular  order  LIFO(Last In First Out).\n";
			cout<<"push(insertion) and pop(deletion) is performed on stack from  the top of  stack."<<endl;
			cout<<endl;
	
				cout<<"************Operation on stack***************"<<endl;
				cout<<endl;
				stack1 obj;
        			int ch;
        			do{
       			 	cout<<"\n 1.Insertion in Stack\n2.Deletion in Stack\n3.find out the size of stack\n4.Display \n5.Back to Menu:\n6.EXIT\n";
				cout<<endl;
        			cout<<" 	enter your choice:-";
        			cin>>ch;
				cout<<endl;
        			switch(ch)
       			 	{
                		case 1:
                		{       cout<<"enter element:\n";
                        		cin>>item;
                        		obj.push(stack,item);
                        		break;
               			 }
                		case 2:
                        		obj.pop();
                        		break;
				case 3:
					break;
                		case 4:
                        		obj.display();
                       			 break;
                		case 5:
                        		goto x2;
                       	 		break;
				case 6:
					exit(0);
					break;
				default:
					cout<<"invalid choice"<<endl;
				}
				}while(ch!=0);
				}
				
				break;

		case 7:{
			system("clear");	
			int item,ch;
			STACK S;
					
			do{
				cout<<"********************Implementation of Stack using Queue**************"<<endl;
				cout<<endl;
				cout<<"\n1.insert\n2.Delete\n3.Back to menu\n4.EXIT";
				cout<<endl;
				cout<<"		enter your choice:- ";
				cin>>ch;
				switch(ch)
				{
					case 1:{
						cout<<"enter element to insert"<<endl;
						cin>>item;
						S.push(item);}
						break;
					case 2:
						cout<<" element deleted is :- "<<S.pop()<<endl;
						break;
					case 3:
						goto x2;
						break;
					case 4:
						exit(0);
						break;
					default:
						cout<<"invalid choice"<<endl;
				}
			}while(ch!=0);
			}
			break;
			
		case 8:
			{
			system("clear");
			Stack a;
			char input[20];
			cout<<"************Postfix Evaluation of Stack*****************"<<endl;
			cout<<endl;
			cout<<"enter valid postfix expression:-"<<endl;
			cin>>input;
 	      		a.evaluate(input);
			}
			break;
		
		case 9:{
			system("clear");
			cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>LINKED LIST<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
			cout<<endl;
			cout<<"LINKED LIST:- A linked list is a linear data structure.which consists of group of nodes in a sequence.\n";
			cout<<"Each node holds its own data and the address of the next node hence forming a chain like structure.\n";
			cout<<endl;
			cout<<"-------------------Singly Linked List-----------------"<<endl;
			cout<<endl;
			single_list a;
			int ch,x,pos,search;
			s=NULL;
			do{
				
				cout<<"1.Find last node address:\n";
   				cout<<"2.Find second last node address:"<<endl;
				cout<<"3.Insert at Front:"<<endl;
				cout<<"4.Insert at end:"<<endl;
    				cout<<"5.Insert at specific position:"<<endl;
				cout<<"6.Delete at Front:"<<endl;
				cout<<"7.Delete at end:"<<endl;
				cout<<"8.Delete at specific position:"<<endl;
				cout<<"9.Display:"<<endl;
				cout<<"10.Searching element:"<<endl;
				cout<<"11.Reverse the linked list:"<<endl;
			        cout<<"12.EXIT:"<<endl;
				cout<<"13.Back to menu"<<endl;
				cout<<endl;
				cout<<"		Enter your choice:- ";
				cin>>ch;
							
				switch(ch)
	        		{
				   case 1:
				         a.last_node();
  					 break;
				   case 2:
				         a.second_node();
      					 break;
				   case 3:
      					 a.insert_front();
              				 break;
				   case 4:
				         a.insert_end();
   				         break;
				   case 5:{
				         cout<<"enter element"<<endl;
					 cin>>x;
				         cout<<"enter position"<<endl;
				         cin>>pos;
           	       		         a.insert_pos(x,pos);
         				  }
              				 break;
            			   case 6:
        				 a.delete_front();
         				 break;
      				   case 7:
                 			 a.delete_end();
        				 break;
     				   case 8:
               				 a.delete_pos();
          				 break;
            			   case 9:
                     			 a.display();
          				 break;
         			   case 10:
               				 a.search_data();
                 			 break;
         			   case 11:
               				 cout<<"reverse order:\n";
                 			 a.rev();
                  			 break;
         			   case 12:
                   			 exit(0);
       				         break;
        			}
	 		}while(ch!=0);
			}	
			break;
			case 10:
					{
					system("clear");
					cout<<"--------------Singly Circular linked list-------------"<<endl;
					cout<<endl;
					  circular a;
       					s=NULL;
      					  int ch,x,pos;
       					 do{
        					cout<<"1.Insert at begin:\n";
      					        cout<<"2.Insert at end:\n";
					        cout<<"3.Insert at position:\n";
					        cout<<"4.display\n";
	      					cout<<"5.delete at front\n";
       						cout<<"6.delete at end:\n";
        					cout<<"7.delete at position:\n";
        					cout<<"8.exit:\n";
						cout<<endl;
    						cout<<"		enter your choice:-";
        					cin>>ch;
       						 switch(ch)
      						{
                				case 1:
                			       		 a.insert_front();
                        				 break;
              					case 2:
                        				a.insert_end();
                     					break;
              					case 3:
                        				cout<<"enter element"<<endl;
                       					 cin>>x;
                        				cout<<"enter position"<<endl;
                        				cin>>pos;
                        				a.insert_pos(x,pos);
                        				break;
                				case 4:
                        				a.display(s);
                        				break;
                				case 5:
                        				a.delete_front(s);
                        				break;
                				case 6:
                        				a.delete_end();
                        				break;
                				case 7:
                        				a.delete_pos();
                       					 break;
                				case 8:
                        				exit(0);
                        				break;
                				default:
                        				cout<<"invalid choice:\n";
        					}
  					}while(ch!=0);
				

				}
					break;
			case 11:
					{
					system("clear");
					cout<<"-----------------Doubly linked list-------------------"<<endl; 
					cout<<endl;
					    int ch;
				        doubly d;
        				do{
        					cout<<"1.Insert at begining:\n";
        					cout<<"2.Insert at end:\n";
        					cout<<"3.Insert at position:\n";
        					cout<<"4.Delete at beggining:\n";
        					cout<<"5.Delete at end:\n";
        					cout<<"6.Delete at position:\n";
        					cout<<"7.Display:\n";
        					cout<<"8.EXIT:\n";
						cout<<endl;
        					cout<<" enter your choice:- ";
        					cin>>ch;
						cout<<endl;

        					switch(ch)
       						 {
                					case 1:
                        					d.insert_beg();
                        					break;
                					case 2:
                        					d.insert_end();
                        					break;
                					case 3:
                       						 d.insert_pos();
                        					break;
                					case 4:
                        					d.delete_beg();
                        					break;
                					case 5:
                        					d.delete_end();
                        					break;
                					case 6:
                        					d.delete_pos();
                        					break;
               						case 7:
                        					d.display();
                        					break;
                					case 8:
                        					exit(0);
                        					break;
                					default:
                       						 cout<<" invalid choice:\n";
        					}
  					      }while(ch!=0);
					}
					break;
			case 12:
					{
					system("clear");
					cout<<"------------------Circular doubly linked list------------"<<endl;
					cout<<endl;
					int ch,x,pos;
        				circular_doubly f;
        				do{
        					cout<<"1.insert at front"<<endl;
        					cout<<"2.insert at end"<<endl;
        					cout<<"3.insert at position"<<endl;
        					cout<<"4.Delete at front"<<endl;
        					cout<<"5.Delete at end"<<endl;
        					cout<<"6.Delete at position"<<endl;
      					  	cout<<"7.Display"<<endl;
						cout<<endl;
        					cout<<"		enter your choice:-"<<endl;
       						cin>>ch;
						cout<<endl;
        					switch(ch)
        					{
                				case 1:
                        				cout<<"enter element"<<endl;
                        				cin>>x;
                        				f.insert_front(start,x);
                        				break;
                				case 2:
                        				cout<<"enter element"<<endl;
                        				cin>>x;
                        				f.insert_end(start, x);
                        				break;
                				case 3:
                        				f.insert_pos();
                        				break;
                				case 4:
                        				f.delete_front();
                        				break;
                				case 5:
                        				f.delete_end();
                        				break;
                				case 6:
                        				cout<<"enter position"<<endl;
                        				cin>>pos;
                        				f.delete_pos(pos);

                        				break;
                				case 7:
                        				f.display();
                        				break;
                				default:
                        				cout<<"invalid choice"<<endl;
        					}
        				}while(ch!=0);
					}
					break;
			case 13:{
				system("clear");
			 	Binary_tree b;
       				 do{
        				cout<<"*******************BINARY TREE******************"<<endl;
					cout<<endl;
        				cout<<"\n1.insert\n2.preorder\n3.postorder\n4.inorder\n5.find no. of nodes\n";
					cout<<"6.find leaf nodes\n7.Find internal nodes\n8.Find height of binary tree\n9.Find mirror tree\n10.EXIT"<<endl;
					cout<<endl;
  				        cout<<"		enter your choice:-";
        				cin>>ch;
					cout<<endl;
        				switch(ch)
       					 {
                			case 1:
                        			cout<<"enter element to insert in binary tree"<<endl;
                        			cin>>item;
                        			b.insert(root,item);
                        			break;
                			case 2:
                        			b.preorder(root);
                        			break;
                			case 3:
                        			b.postorder(root);
                       				 break;
                			case 4:
                        			b.inorder(root);
                       				 break;
                			case 5:{
                        			cout<<"\nno. of nodes in binary tree:- "<<b.num_node(root)<<endl;
                        			}
                        			break;
                			case 6:{
                        			cout<<"\nleaf nodes are:- ";
                        			b.leafprint(root);
                      				 cout<<endl;
                        			}
                        			break;
                			case 7:
                        			cout<<"\nnumber of internal nodes are:-"<<b.internal(root)<<endl;
                        			break;
                			case 8:
                        			cout<<"\nHeight of the tree is "<<b.FindHeight(root)<<endl;
                        			break;
                			case 9:{
                        			cout<<"\nInorder traversal of original tree:- "<<endl;
                        			b.inorder(root);
                        			b.mirror(root);
                        			cout<<"\nInorder traversal of Mirror Binary tree is- "<<endl;
                        			b.inorder(root);}
                        			break;
					case 10:
						exit(0);
                			default:
                        			cout<<"invalid choice"<<endl;
        				}
        			}while(ch!=0);

			}
			break;
		case 14:{
			system("clear");
			  struct tree *root=NULL;
        		  int ch,item;
        		do{
        		cout<<"*****************&Binary Search Tree&*************************"<<endl;
			cout<<endl;
        		cout<<"1.Insert element\n2.Inorder traversal\n3.Preorder traversal\n4.Postoreder\n";
			cout<<"5.Find minimum element\n6.Find maximum element\n7.Delete element\n8.EXIT"<<endl;
			cout<<endl;
        		cout<<" 	Enter your choice:-";
       			cin>>ch;
			cout<<endl;
        		switch(ch)
        		{
                	case 1:
                        	cout<<"Enter element to insert:\n";
                        	cin>>item;

                        	insert(root, item);
                        	break;
               		case 2:
                       		 cout<<" Inorder traversal - ";
                        	inorder(root);
                        	cout<<endl;
                        	break;
                	case 3:
                        	cout<<" Preorder traversal - ";
                        	preorder(root);
                        	cout<<endl;
                       		break;
                	case 4:
                        	cout<<" Postorder traversal - ";
                       		 postorder(root);
                        	cout<<endl;
                        	break;
                	case 5:
                        	findmin(root);
                        	break;
                	case 6:
                        	findmax(root);
                        	break;
               		case 7:
                        	cout<<"Enter element to delete:\n";
                        	cin>>item;
                        	deletenode(root,item);
                        	break;

                	case 8:
                        	exit(0);
                        	break;
               		default:
                        	cout<<" invalid choice entered:\n";
			}
		}while(ch!=0);
		}
		break;
		
		case 15:{
			system("clear");
			cout<<"**************BUBBLE SORT**************"<<endl;
			cout<<endl;
			z.bubble_sort();
			break;}
		case 16:
			{
			system("clear");
			cout<<"************Insertion Sort*************"<<endl;
			cout<<endl;
			z.insertion_sort();}
			break;
		case 17:{
			system("clear");
			cout<<"*********Selection Sort*****************"<<endl;
			cout<<endl;
			z.selection_sort();}
			break;
		case 18:{
			system("clear");
			cout<<"***********Quick Sort*****************"<<endl;
			cout<<endl;
			z.insert();}
			break;
		case 19:cout<<"****************************THANKYOU FOR WATCHING*****************************"<<endl;
			cout<<"Developed by- Ambika Sadh"<<endl;
			cout<<"Project Name- All In One Data Structure"<<endl;
			exit(0);
			break;
		
		default:
			cout<<"invalid choice"<<endl;
		}
	}while(ch!=0);
	
return 0;
}	