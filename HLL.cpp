#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Node
{
    int data;
    Node *next;
    friend class Header_linked_list;

public:
    Node(int value = 0)
    {
        data = value;
        next = NULL;
    }
};

class Header_node : public Node
{
    int max;
    int min;
    int avg;
    friend class Header_linked_list;
    Node *next;

public:
    Header_node()
    {
        next = NULL;
    }
};

class Header_linked_list
{
    Node *head;

public:
    Header_linked_list()
    {
        head = new Header_node;
    }

    void insert_at_beginning(int value)
    {
        Node *p = new Node(value);
        }
};