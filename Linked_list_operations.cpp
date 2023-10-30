#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

class node
{
public:
    int data;
    node *next;
};
class linkedlist
{
public:
    node *head = NULL;
    int length = 0;

    void insertathead();
    void insertatend();
    void display();
    void deleteelementhead();
    void deleteelementend();
    void nthnode();
    void insertatposition();
    void reverse();
};

void linkedlist ::insertathead()
{
    node *newnode = new node;
    int x;
    cout << "\t\t\t\tEnter the number : ";
    cin >> x;
    newnode->data = x;
    newnode->next = head;
    head = newnode;
    length++;
}

void linkedlist ::insertatend()
{
    node *newnode = new node;
    int x;
    cout << "\t\t\t\tEnter the number : ";
    cin >> x;
    newnode->data = x;
    newnode->next = NULL;
    if (head == NULL)
    { // this cond is made when we insert at end while creation
        head = newnode;
        return;
    }
    node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newnode;
    length++;
}

void linkedlist ::deleteelementhead()
{
    node *current = head;
    head = head->next;
    length--;
    // free(current);
}

void linkedlist ::deleteelementend()
{
    node *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    current->next = NULL;
    length--;
}

void linkedlist ::nthnode()
{
    int x;
    cout << "\t\t\t\tEnter the node number from last to display : ";
    cin >> x;
    node *current = head;
    for (int i = 1; i <= length - x; i++)
    {
        current = current->next;
    }
    cout << "\t\t\t\tNode number " << x << " from the end has the data : " << current->data;
    cout << "\n_________________________________________________________________________________________\n";
}

void linkedlist ::insertatposition()
{
    int pos, current_pos = 0;
    cout << "\t\t\tEnter the postion(index) to insert a new node in the Linked list : ";
    cin >> pos;
    int x;
    cout << "\t\t\t\t\tEnter the number to insert :";
    cin >> x;
    node *newnode = new node;
    newnode->data = x;
    node *current = head;
    while (current_pos != pos - 1)
    {
        current = current->next;
        current_pos++;
    }
    newnode->next = current->next;
    current->next = newnode;
    length++;
}

void linkedlist ::reverse()
{
    node *current = head;
    node *prevptr = NULL;
    while (current != NULL)
    {
        node *nextptr = current->next;
        current->next = prevptr;
        prevptr = current;
        current = nextptr;
    }
    head = prevptr;
}

void linkedlist ::display()
{
    node *current = head;
    cout << "\n\t\t\t\t";
    while (current != NULL)
    {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "NULL";
    cout << "\n_________________________________________________________________________________________\n";
}

int main()
{
    linkedlist l1;
    cout << "_________________________________________________________________________________________\n";
    cout << "\n\t\t\t\tOPERATIONS ON SINGLI LINKED LIST\n";
    cout << "_________________________________________________________________________________________\n";
    cout << "\n\t\t\t\t\tTASK LIST\n";
    cout << "_________________________________________________________________________________________\n";
    cout << "\t\t\t\t1. Create a Linkedlist in the direction of head(To insert at head)\n";
    cout << "\t\t\t\t2. Create a Linkedlist in the direction of End(To insert at Tail)/tail\n";
    cout << "\t\t\t\t3. Delete node from the head\n";
    cout << "\t\t\t\t4. Delete node from the end/tail\n";
    cout << "\t\t\t\t5. To Display the nth node from tha end\n";
    cout << "\t\t\t\t6. To Reverse the Linked list\n";
    cout << "\t\t\t\t7. To insert a node at a postion\n";
    cout << "\t\t\t\t8. To Exit\n";

    cout << "_________________________________________________________________________________________\n";

    int k;
    int c = 0;
    while (c != 1)
    {
        cout << "\nEnter the Task Number to Perform : ";
        cin >> k;
        switch (k)
        {
        case 1:
            cout << "\t\t\t\tTo Insert a new Node at tha head  \n";
            int n;
            cout << "\t\t\t\tEnter total Number of nodes to insert at head :  ";
            cin >> n;
            for (int i = 1; i <= n; i++)
            {
                l1.insertathead();
            }
            l1.display();
            cout << "\n";
            break;

        case 2:
            cout << "\t\t\t\tTo Insert a New Node at the End / Tail \n";
            //    int n;
            cout << "\t\t\t\tEnter total Number of nodes to insert at End / Tail :  ";
            cin >> n;
            for (int i = 1; i <= n; i++)
            {
                l1.insertatend();
            }
            l1.display();
            break;

        case 3:
            cout << "\t\t\t\tTo Delete node from the head \n";
            cout << "\t\t\t\tEnter number of nodes u want to delete from head : ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                l1.deleteelementhead();
            }
            l1.display();
            break;

        case 4:
            cout << "\t\t\t\tTo Delete node from the head \n";
            cout << "\t\t\t\tEnter number of nodes u want to delete from end\tail : ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                l1.deleteelementend();
            }
            l1.display();
            break;

        case 5:
            l1.nthnode();
            break;

        case 6:
            l1.reverse();
            l1.display();
            break;

        case 7:
            l1.insertatposition();
            l1.display();
            break;

        case 8:
            system("cls");
            cout << "\t\t\t\t\tTHANK YOU";
            c++;
            break;
        }
    }
}