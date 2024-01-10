#include <iostream>
#include <istream>
#include <fstream>
#include <string>
using namespace std;

struct names{
    string fname;
    string lname;
    int age;
    char gender;
    string dept;
};

struct node{
    names name;
    node *nxt;
};

typedef node *pnode;

pnode head, p,q, prev, last,temp,ptr1,ptr2,curr;


void create (pnode *head){
    *head = NULL;
}

bool is_empty(pnode head){
    if ( head == NULL)
        return true;
    else
        return false;
}

pnode getnode()
{
    return new node;
}

void free_node(pnode p)
{
    delete p;
}

void insert_first(pnode *head, pnode p)
{
    if(*head == NULL)
    {
        *head = p;
        p -> nxt = NULL;
    }else
    {
        p -> nxt = *head;
        *head = p;
    }
}

void insert_last(pnode *head, pnode p)
{
    if (*head == NULL)
        insert_first(&(*head), p);
    else
    {
        last = *head;
        while(last -> nxt != NULL)
            last = last -> nxt;
        last -> nxt = p;
        p -> nxt = NULL;

    }
    ofstream myfile("project.txt",ios::app);
    myfile<<p->name.fname<<"\t";
    myfile<<p->name.lname<<"\t";
    myfile<<p->name.age<<"\t";
    myfile<<p->name.gender<<"\t";
    myfile<<p->name.dept<<"\n";
    myfile.close();
}

pnode search_node(pnode head, string x,string y)
{
    pnode temp=NULL;
    bool found =false;
    while(head!=NULL&&!found){
    if(head->name.fname == x&&head->name.lname == y){
    temp=head;
    found=true;
    }
    else{
    head=head->nxt;
    }
}
if(!found){
    cout <<"The record is not found\n";
}
else{
return temp;
}
}

pnode search_previous_node(pnode head, string x,string y)
{
    pnode prev=NULL;
    bool found =false;
    while(head!=NULL&&!found){
    if(head->name.fname == x&&head->name.lname == y){
    found=true;
    }
    else{
    prev=head;
    head=head->nxt;
    }
}
return prev;
}

void search_record(pnode head)
{
    cout <<"Enter data to be searched(Full Name): ";
    string fname,lname;
    cin >>fname;
    cin>>lname;
    pnode temp=NULL;
    bool found =false;
    while(head!=NULL&&!found){
    if(head->name.fname == fname&&head->name.lname == lname){
    temp=head;
    found=true;
    }
    else{
    head=head->nxt;
    }
}
if(!found){
    cout <<"Record not found\n";
}
else{
    p = search_node(head, fname,lname);
    cout << "First name\tLast name\tAge\tGender\tDepartment\n";
    cout<<temp->name.fname<<"\t\t" << temp->name.lname<< "\t\t" << temp->name.age<<"\t" << temp->name.gender<<"\t\t" << temp->name.dept<<endl;

}
}

bool search_record2(pnode head,string fname,string lname)
{
    pnode temp=NULL;
    bool found =false;
    while(head!=NULL&&!found){
    if(head->name.fname == fname&&head->name.lname == lname){
    temp=head;
    found=true;
    }
    else{
    head=head->nxt;
    }
}
if(!found){
    return false;
}
else{
    return true;
}
}

void delete_first(pnode *head)
{
    if(*head == NULL)
    {
        cout << "\n No Node to delete!\n";
    }else
    {
        p = *head;
        *head = p -> nxt;
        free_node(p);
        cout <<"The record has been deleted\n";
    }
}

void delete_middle(pnode *head, pnode p, pnode prev)
{
    if (prev == NULL)
        cout << "\n No Node to delete!\n";
    else
    {
        prev -> nxt = p -> nxt;
        free_node(p);
        cout <<"The record has been deleted\n";
    }
}

void delete_last(pnode *head)
{
    if(*head == NULL)
        cout << "\n No Node to delete!\n";
    else
    {
        last = *head;
        while(last -> nxt != NULL){
            temp = last;
            last = last -> nxt;

        }
        temp -> nxt = NULL;
        free_node(last);
        cout <<"The record has been deleted\n";
    }
}

void delete_record(){
    string data,data2;
    cout << "Enter data to delete: ";
    cin >> data;
    cin >> data2;
    bool found=search_record2(head,data,data2);
    if(found){
    p = search_node(head, data,data2);
    q = search_previous_node(head, data,data2);

     if(head->name.fname == data&&head->name.lname == data2)
        {
            delete_first(&head);
        }
    else if(p->nxt==NULL)
        {
            delete_last(&head);
        }
    else if(q!=NULL)
        {
            delete_middle(&head, p, q);
        }
    else{
          cout <<"The record is not found\n";
        }
    }
    else{
        cout <<"The record is not found\n";
    }
}


void update_record(pnode *head){
    string data,data2;
    cout <<"To search record to be updated\n";
    cout <<"Enter record(Full Name): ";
    cin >>data;
    cin>>data2;
    bool found=search_record2(*head,data,data2);
    if(found){
    p = search_node(*head, data,data2);
    cout <<"Which data would you like to update\n\n";
    cout <<"1. First name\n";
    cout <<"2. Last name\n";
    int ch2;
    cout <<"choice: ";
    cin >>ch2;
    switch(ch2){
        case 1:
            cout <<"Enter the updated data: ";
            cin >>p->name.fname;
            cout <<"Record is updated\n";
            break;

        case 2:
            cout <<"Enter the updated data: ";
            cin >>p->name.lname;
            cout <<"Record is updated\n";
            break;
        default:
            cout <<"There is no such type of data in the record\n";
            break;
    }
    }
    else{
        cout <<"The record is not found\n";
    }
}

void bubble_sort(pnode& head) {
    if (head == NULL || head->nxt == NULL)
        return;

    bool swapped;
    pnode curr;
    pnode last = NULL;

    do {
        swapped = false;
        curr = head;

        while (curr->nxt != last) {
            if (curr->name.fname > curr->nxt->name.fname) {
                swap(curr->name, curr->nxt->name);
                swapped = true;
            }
            else if(curr->name.fname == curr->nxt->name.fname){
                if (curr->name.lname > curr->nxt->name.lname) {
                swap(curr->name, curr->nxt->name);
                swapped = true;}
            }
            curr = curr->nxt;

        }
        last = curr;
    } while (swapped);
}

void printList(pnode head) {
    pnode temp = head;

    if (head == NULL){
        cout << "No record created\n";
        return;
    }
        cout << "First name\tLast name\tAge\tGender\n";
    while (temp != NULL) {
        cout<<temp->name.fname<<"\t\t" << temp->name.lname <<"\t\t" << temp->name.age<<"\t"<<temp->name.gender<<"\ndepartment" << temp->name.dept<<endl;
        temp = temp->nxt;
    }
    cout << endl;
}


#define Max 30
#define null -1

struct Queue{
    string data[Max];
    int rear;
    int Front;
};

struct Node1
{
   string data;
   Node1* nxt;
};

struct L_Queue
{
    Node1 *Lfront;
    Node1 *Lrear;
};
L_Queue Lq;

Queue lq, cq;

string x;
int ch;

void circular_create (Queue &cq)
{
    cq.Front = 0;
    cq.rear = 0;
}

bool circular_isEmpty(Queue cq)
{
    return cq.Front == cq.rear;
}

bool circular_isFull(Queue cq)
{
    return (cq.rear + 1) % Max == cq.Front;
}

void circular_enqueue(Queue &cq, const string& x)
{
    if(circular_isFull(cq))
        cout << "\nStudents in the waitlist is full";
    else {
        cq.rear = (cq.rear + 1) % Max;
        cq.data[cq.rear] = x;
    }
}

bool linear_isEmpty(Queue lq)
{
    return lq.Front == lq.rear;
}

string circular_dequeue(Queue &cq)
{
    if(linear_isEmpty(cq))
        cout<<"\nNo student in the waitlist";
    else{
        x = cq.data[++cq.Front];
    }
    return x;
}

string circular_front(Queue &cq)
{
    if (linear_isEmpty(cq))
        cout<<"\nNo student in the waitlist";
    else{
        x = cq.data[cq.Front + 1];
    }
    return x;
}

void circularDisplay(Queue cq)
{
    if (linear_isEmpty(cq)) {
        cout << "No student in the waitlist" << endl;
    } else {
        cout << "All students in the waitlist are \n";
        for (int i = cq.Front + 1; i <= cq.rear; i++) {
            cout << cq.data[i] ;
        }
        cout << endl;
    }
}

int main()
{
    string fname,lname,dept,dat,y;
    int age,ch3,ch1;
    char gender;
    circular_create(cq);
    create(&head);
    bool exit=true,exit2=true;
    do {
            d:
        cout << "\nMenu\n1.Register to Waitlist\n2.Student registration\n3.Exit\n";
        a:
            cout<<"Enter your choice: ";
        cin >> ch3;
    switch (ch3){
        case 1:
            do{
                cout << "\n\nCircular Queue Operations:\nWaitlist\n1. Register to waitlist\n2. Display all students in the waitlist \n3. Display First student in the waitlist \n4. Go back\n";
                c:
                    cout<<"Enter your choice: ";
                cin >> ch1;
                 switch (ch1) {
                    case 1:
                        cout << "Enter your name(end with 0): ";
                        getline(cin,dat,'0');
                        circular_enqueue(cq,dat);
                        system("CLS");
                        break;
                    case 2:
                        circularDisplay(cq);
                        break;
                    case 3:
                        y = circular_front(cq);
                        cout<<"\nThe first student in the waitlist is: "<<y;
                        break;
                    case 4:
                        system("CLS");
                        goto d;
                        break;
                    default:
                        cout << "Invalid choice for Linear Queue. Please enter a valid option." << endl;
                        goto c;
                        break;
                }
                } while(ch1 != 5);
            break;
        case 2:
    do
    {
        cout << "\n\nLinked list operations: \n";
        cout << "*STUDENT REGISTRATION SYSTEM*\n\n";
        cout << "1. Insert record\n";
        cout << "2. Delete record\n";
        cout << "3. Update record\n";
        cout << "4. Search record\n";
        cout << "5. Sort the records\n";
        cout << "6. Display records\n";
        cout << "7. Go back\n";
        cout << "8. Exit\n";
         b:
        cout << "Enter your choice: ";
        cin>> ch;

        switch(ch){

        case 1:
             y = circular_dequeue(cq);
            cout << "\nThe first student in the waitlist is: "<<y<<endl;
            cout << "Enter data\n";
            cout << "First name: ";
            cin >>fname;
            cout << "Last name: ";
            cin >>lname;
            cout << "Age: ";
            cin >>age;
            cout <<"Gender('M' or 'F'): ";
            cin >>gender;
            cout <<"Department(end with 0): ";
            getline(cin,dept,'0');
            p = getnode();
            p->name.fname = fname;
            p->name.lname = lname;
            p->name.age = age;
            p->name.gender = gender;
            p->name.dept = dept;
            insert_last(&head, p);
            system("CLS");
        break;

        case 2:
            delete_record();
            break;
        break;

        case 3:
            update_record(&head);
            break;

        case 4:
            search_record(head);
            break;

        case 5:
            bubble_sort(head);
            printList(head);
            break;

        case 6:
            printList(head);
            break;

        case 7:
            system("CLS");
            goto d;
            break;

        case 8:
            exit=false;
            break;

            
        default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                goto b;
                break;
        }}while(exit);
        system("CLS");
        break;

        case 3:
                cout << "Exiting the program." << endl;
                exit2=false;
                break;
        default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                goto a;
                break;
    }}while(exit2);
    return 0;
}
