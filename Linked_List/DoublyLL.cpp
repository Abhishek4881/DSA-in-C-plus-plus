#include <iostream>
#include <vector>
using namespace std;

struct Node
{

    int data;
    Node *next;
    Node *back;

    Node(int data1)
    {

        data = data1;
        next = nullptr;
        back = nullptr;
    }

    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
};

void Print(Node *head)
{

    while (head)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

Node *Arr2DLL(vector<int> &arr)
{

    if (arr.size() == 0)
    {
        return nullptr;
    }
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {

        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node *deleteHead(Node *head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    Node *prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    free(prev);

    return head;
}

Node *deleteTail(Node *head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    Node *tail = head;

    while (tail->next != nullptr)
    {

        tail = tail->next;
    }

    tail->back->next = nullptr;
    tail->back = nullptr;
    free(tail);
    return head;
}

Node *deleteKth(Node *head, int k)
{

    if (head == NULL)
    {
        return nullptr;
    }

    if (head->next == nullptr)
    {

        if (k == 1)
        {
            return nullptr;
        }

        else
        {
            cout << "Invalid Position\n";
        }
    }

    Node *temp = head;
    int count = 1;

    while (temp != nullptr && count != k)
    {

        temp = temp->next;
        count++;
    }

    temp->back->next = temp->next;
    temp->next->back = temp->back;
    temp->next = nullptr;
    temp->back = nullptr;

    free(temp);

    return head;
}

void deleteNode(Node *nod)
{

    Node *prev = nod->back;
    Node *front = nod->next;

    // if(prev==nullptr){

    //     nod->next=nullptr;
    //     front->back=nullptr;
    //     free (nod);
    //     return;
    // }
    
    if (front == nullptr)
    {
        prev->next = nullptr;
        nod->back = nullptr;
        free(nod);
        return;
    }

    prev->next = front;
    front->back = prev;

    nod->next = nullptr;
    nod->back = nullptr;
    free(nod);

    return;
}

int main()
{

    vector<int> arr{5, 9, 4, 8, 2};

    Node *head = Arr2DLL(arr);
    Print(head);
    // head = deleteHead(head);
    // Print(head);

    // head = deleteTail(head);
    // Print(head);

    // head = deleteKth(head, 3);
    // Print(head);
    // cout << head->next->next->back->data;

    
    deleteNode(head->next);
    // deleteNode(head->next->next);
    Print(head);
    
}