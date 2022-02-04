#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
//circular_doubly_link_list
class node
{
public:
    int info;
    node *prev;
    node *next;
};
node* creat(int data)
{
    node *ptr= new node;
    ptr->info=data;
    return ptr;
}
void display(node *head)
{
    node *ptr=head->next;

    do {
        cout<<" "<<ptr->info;
        ptr=ptr->next;
    } while(ptr!=head);

}
node* find(node *head,int key)
{
    node *ptr=head->next;
    while(ptr->info!=key)
    {
        ptr=ptr->next;
    }
    return ptr;
}
void insertat_last(node *head,int data)
{
    node *p1=creat(data);
    node *ptr=head->next;
    do {
        ptr=ptr->next;
    } while(ptr->next!=head);
    ptr->next=p1;
    p1->prev=ptr;
    p1->next=head;

}
void insertat_index(node *head,int key,int data)
{
    node *ptr=new node;
    ptr=find(head,key);
    ptr->info=data;

}
void insertat_start(node *head,int data)
{
    node *ptr=creat(data);
    ptr->next=head->next;
    head->prev=ptr;
    head->next=ptr;
    ptr->prev=head;
}
void insertafter_node(node *head,int key,int data)
{
    node *p1=creat(data);
    node *ptr=head->next;
    while(ptr->info!=key)
    {
        ptr=ptr->next;
    }
    p1->next=ptr->next;
    ptr->prev=p1;
    ptr->next=p1;
    p1->prev=ptr;
}
void deleteat_start(node *head)
{
    head->next=head->next->next;
}
void deleteat_index(node *head,int key)
{
    node *ptr=head->next;
    while(ptr->info!=key)
    {
        ptr=ptr->next;
    }
    ptr->prev->next=ptr->next;
}
void deleteafter_node(node *head,int key)
{
    node *ptr =find(head,key);
    ptr->next->next->prev=ptr;
    ptr->next=ptr->next->next;
}
void deleteat_last(node *head)
{
    node *ptr=head->next;

    do {
        ptr=ptr->next;
    } while(ptr->next->next!=head);

    ptr->next=head;
}
int main()
{

    node *head,*p1,*p2,*p3;
    head= new node;

    p1= creat(00);
    head->next=p1;
    p1->next=head;
    int cmd,data1,data2,data3,data4,index1,index2,index3,index4;
    while(1)
    {
        clrscr();
        cout<<"---------------------------"<<endl;
        cout<<"      current data         "<<endl;
        cout<<"-----------------------------"<<endl;
        display(head);
        cout<<endl<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1.insert at start"<<endl;
        cout<<"2.insert at index"<<endl;
        cout<<"3.insert after index"<<endl;
        cout<<"4.insert at last"<<endl;
        cout<<"5.delete at start"<<endl;
        cout<<"6.delete at index"<<endl;
        cout<<"7.delete after index"<<endl;
        cout<<"8.delete at last"<<endl;
        cout<<"9.display"<<endl;
        cout<<"10.exit"<<endl;
        cout<<"enter the command=>>";
        cin>>cmd;
        switch(cmd)
        {
        case 1:
            cout<<"enter the data=>"<<endl;
            cin>>data1;
            insertat_start(head,data1);
            break;
        case 2:
            cout<<"enter the index=>"<<endl;
            cin>>index1;
            cout<<"enter the data=>"<<endl;
            cin>>data2;
            insertat_index(head,index1,data2);
            break;
        case 3:
            cout<<"enter the index=>"<<endl;
            cin>>index2;
            cout<<"enter the data=>"<<endl;
            cin>>data3;
            insertafter_node(head,index2,data3);
            break;
        case 4:
            cout<<"enter the data=>"<<endl;
            cin>>data4;
            insertat_last(head,data4);
            break;
        case 5:
            deleteat_start(head);
            break;
        case 6:
            cout<<"enter the index=>>"<<endl;
            cin>>index3;
            deleteat_index(head,index3);
            break;
        case 7:
            cout<<"enter the index=>"<<endl;
            cin>>index4;
            deleteafter_node(head,index4);
            break;
        case 8:
            deleteat_last(head);
            break;
        case 9:
            display(head);
            getch();
            break;
        case 10:
            return 0;
            break;
        default:
            cout<<"command is not found ?"<<endl;
            break;
        }

        getch();
    }

    return 0;
}