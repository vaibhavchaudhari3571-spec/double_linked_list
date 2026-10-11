#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node*next;
    node*prev;
    node(int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};

class LinkedList{
    private:
    node*head;

    public:
    LinkedList(){
        head=NULL;
    }
    void insert(int x)
    {
        node*p=new node(x);
        if(head==NULL)
        {
            head=p;
        }
        else
        {
            node*q=head;
            while(q->next !=NULL)
            q=q->next;
            q->next=p;
            p->prev=q;
        }
    }
    void remove(int x)
    {
        node*p=NULL;
        if(head->data==x)
        {
            p=head;
            head=head->next;
            head->prev=NULL;
            delete p;
            return;
        }
        node*q=head;
        while (q->next !=NULL)
        {
            if(q->next->data==x)
            {
                p=q->next;
                q->next=p->next;
                p->next->prev=q;
                delete p;
                return;
            }
            q=q->next;
        }
        cout<<endl<<"Data not found in list";
        
    }

    void display(){
        node*q=head;
        while(q!=NULL)
        {
            cout<<q->data<<"<=>";
            q=q->next;
        }

    }

};
int main()
{
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    cout<<endl;
    list.display();

    list.insert(40);
    list.insert(50);
    list.insert(60);
    cout<<endl;
    list.display();


    list.remove(20);
    cout<<endl;
    list.display();

    list.remove(50);
    cout<<endl;
    list.display();

    list.remove(100);
    cout<<endl;
    list.display();

    return(0);

}
    





    /*PS D:\vaibhav> cd "d:\vaibhav\" ; if ($?) { g++ double_linklist.cpp -o double_linklist } ; if ($?) { .\double_linklist }

10<=>20<=>30<=>
10<=>20<=>30<=>40<=>50<=>60<=>
10<=>30<=>40<=>50<=>60<=>
10<=>30<=>40<=>60<=>
Data not found in list
10<=>30<=>40<=>60<=>
PS D:\vaibhav> */