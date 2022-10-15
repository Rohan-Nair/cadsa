#include <conio.h>
#include <iostream>

using namespace std;

struct node
{
    int eid;
    int salary;
    node *link;
};

node *start = NULL, *last = NULL;

void delete_beg()
{
    if (start == NULL)
        cout << "List is Empty";
    else
    {
        node *temp = start;
        if (start->link == start)
            start = NULL; // Only one node
        else
        {
            start = start->link;
            last->link = start;
        }
        cout << "\nDeleted element is: " << temp->eid;
        delete temp;
    }
}

void insert_beg()
{
    node *nd = new node;
    cout << "\nEnter the Employee Id: ";
    cin >> nd->eid;
    cout << "\nEnter the Salary: ";
    cin >> nd->salary;
    if (start == NULL)
    {
        nd->link = nd;
        start = nd;
        // maintaining the last node address
        last = nd;
    }
    else
    {
        nd->link = start;
        start = nd;
        last->link = start;
    }
}

void delete_end()
{
    node *p = start;
    if (start == NULL)
    {
        cout << "Linked List is empty";
    }
    else
    {
        while (p->link->link != start)
        {
            p = p->link;
        }
        node *temp = p->link;
        p->link = start;
        last = p;
        cout << "\nDeleted element is: " << temp->eid;
        delete temp;
    }
}

void del_ele()
{
}

void display()
{
    node *p = start;
    cout << "\n\n***LINKED LIST***\n[ ";
    if (p->link == NULL)
    {
        cout << "]";
    }
    else
    {
        while (p->link != start)
        {
            cout << p->eid << ", ";
            p = p->link;
        }
        cout << p->eid << " ]";
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\n 1. insert in the beginning";
        cout << "\n 2. delete from the beginning";
        cout << "\n 3. delete from the end";
        cout << "\n 0. EXIT";
        cout << "\n\nEnter Your Choice:\t";
        cin >> choice;

        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            insert_beg();
            break;
        case 2:
            delete_beg();
            break;
        case 3:
            delete_end();
            break;
        default:
            cout << "\nIncorrect CHOICE, kindly re-enter" << endl;
        }

        display();
    } while (choice != 0);

    getch();
    return 0;
}