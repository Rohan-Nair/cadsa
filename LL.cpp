#include <iostream>

using namespace std;

class Node
{
    int data;
    Node *next;
    friend class Linked_list;

public:
    Node(int value) : data{value}, next{NULL}
    {
    }
};

class Linked_list
{
    Node *head;
    int size;

public:
    Linked_list()
    {
        head = NULL;
        size = 0;
    }

    void insert_at_beginning(int value)
    {
        Node *nd = new Node(value);
        nd->next = head;
        head = nd;
    }

    void insert_at_end(int value)
    {
        Node *nd = new Node(value);
        Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = nd;
    }

    void delete_element(int value)
    {
        Node *p = head;
        if (p->data == value)
        {
            Node *temp = p;
            head = p->next;
            delete temp;
        }
        else
        {
            while (p->next->data != value)
            {
                p = p->next;
            }
            Node *temp = p->next;
            p->next = p->next->next;
            delete temp;
        }
    }

    void show()
    {
        Node *p = head;
        cout << "Elements of linked list are:\n";
        while (p != NULL)
        {
            cout << p->data << "\t";
            p = p->next;
        }
    }
};