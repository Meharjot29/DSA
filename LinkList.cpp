#include <iostream>

using namespace std;



struct Node
{
    int data;
    Node *next;

}*nn,*start,*temp,*loc;

void insert_after(int v)
{
    int d;
    cout<<"\n Enter Element after which u want to insert";
    cin>>d;
    nn= new Node;
    nn->data=v;
    temp=start;
    while(temp!=NULL)
    {
        if(temp->data==d && temp->next!=NULL)
        {

            nn->next=temp->next;
            temp->next=nn;
        }
        else if (temp->data==d && temp->next==NULL)

      {
            nn->next=temp->next;
            temp->next=nn;

      }

        temp=temp->next;

    }
}

void insert_beg(int v)
{
    nn = new Node;
    nn->data=v;
    if(start==NULL)
    {
        start=nn;
        nn->next=NULL;
    }
    else{
        nn->next=start;
        start=nn;
    }

}
void insert_end(int v)
{

    nn=new Node;
    nn->data=v;
    nn->next=NULL;
    if(start==NULL)
    {
        start=nn;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nn;

    }

}
void traverse()
{

    temp=start;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
}


void del_beg()
{

    if(start==NULL)
    {
        cout<<"Linkedlist is empty";
    }
    else if(start->next==NULL)
        {
        delete(start);
    }
    else
    {
        loc=start;
        start=start->next;
    delete(loc);
    }

}
void del_end()
{
    if(start==NULL)
    {
        cout<<"Linkedlist is empty";
    }
    else if(start->next==NULL)
        {
        delete(start);
    }
    else
    {
        temp=start;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        loc=temp->next;
        temp->next=NULL;
        delete(loc);


}
}
void del_any()
{
    int e;
    cout<<"Enter element to delete";
    cin>>e;
    temp=start;
    while(temp!=NULL)
    {
        if(temp->next->data==e)
        {
            loc=temp->next;
            temp->next=loc->next;
            delete(loc);
            break;
        }
        temp=temp->next;
    }
}

int main()
{
    int ch,ch1,x;
    do{
    cout<<"Press 1 to insert at Beg"<<endl;
    cout<<"Press 2 to insert after an element"<<endl;
    cout<<"Press 3 to insert at End"<<endl;
    cout<<"Press 4 to delete from Beg"<<endl;
    cout<<"Press 5 to delete from End"<<endl;
    cout<<"Press 6 to delete any element"<<endl;
    cout<<"Press 7 to Traverse"<<endl;

    cout<<"\n Enter choice";
    cin>>ch;
    switch(ch)
    {
        case 1:
        cout<<"Enter value to insert"<<endl;
        cin>>x;
        insert_beg(10);
    insert_beg(20);

    insert_beg(30);

    insert_beg(40);

    insert_beg(50);

        break;
        case 2:
        cout<<"Enter value to insert"<<endl;
        cin>>x;
        insert_after(x);
        break;
        case 3:
        cout<<"Enter value to insert"<<endl;
        cin>>x;
         insert_end(x);
        break;
        case 4:
            del_beg();
        break;
        case 5:
            del_end();
        break;
case 6:
            del_any();
        break;

        case 7:
            traverse();
            break;
        default:
            cout<<"Invalid Operation";
    }
    cout<<"\n Do you want to continue";
    cin>>ch1;
    }while(ch1==1);
    return 0;
}
