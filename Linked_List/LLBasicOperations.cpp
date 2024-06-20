#include <iostream>
#include <vector>
using namespace std;

struct node
{

    int data;
    node *next;

    node(int data1)
    {

        data = data1;
        next = nullptr;
    }

    node(int data1, node *next1)
    {
        data = data1;
        next = next1;
    }
};

node *arrTOLL(vector<int> &arr)
{

    if (arr.size() == 0)
        return NULL;

    node *head = new node(arr[0]);
    node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {

        node *temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
        // mover=mover->next;
    }
    return head;
}

void PrintLL(node *head)
{

    if (head == NULL)
    {
        cout << "    ";
    }
    node *traversal = head;
    while (traversal)
    // while(traversal!=nullptr)
    {
        cout << traversal->data << "->";
        traversal = traversal->next;
    }
    cout << "nullptr" << endl;
}

int LenOfLL(node *head)
{
    int count = 0;
    node *traversal = head;
    while (traversal)
    {
        traversal = traversal->next;
        count++;
    }
    return count;
}

int SearchLL(node *head, int key)
{
    node *traversal = head;
    while (traversal)
    {
        if (traversal->data == key)
        {
            return 1;
        }
        traversal = traversal->next;
    }

    return 0;
}

node *deleteHead(node *head)
{
    if (head == NULL)
    {
        return head;
    }
    node *temp = head;
    head = head->next;
    delete temp;
    // free (temp);

    return head;
}

node *deleteLast(node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

node *deletePosition(node *head, int position)
{

    if (head == nullptr)
        return head;

    if (position == 1)
    {

        node *temp = head;
        head = head->next;
        delete temp;
        // free (temp);

        return head;
    }

    node *temp = head;
    int index = 1;

    while (temp != nullptr && index != position - 1)
    {
        temp = temp->next;
        index++;
    }

    if (temp == nullptr)
    {
        cout << "invalid position :- position is greater than the length of the LL" << endl;
        return head;
    }

    // temp->next=temp->next->next;
    // free (temp->next);
    node *dlt = temp->next;
    temp->next = dlt->next;
    free(dlt);

    return head;
}

node *deleteK(node *head, int k)
{

    if (head == nullptr)
    {
        return head;
    }

    if (k == 1)
    {

        node *temp = head;
        head = head->next;
        delete temp;
        // free (temp);

        return head;
    }

    node *temp = head;
    int c = 0;
    node *prev = nullptr;

    while (temp != nullptr)
    {

        c++;
        if (c == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

node *deleteValue(node *head, int val)
{

    if (head == nullptr)
    {
        return head;
    }

    if (val == head->data)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        // free (temp);

        return head;
    }

    node *temp = head;
    node *prev = nullptr;

    while (temp != nullptr && temp->data != val)
    {

        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Value is not present in the LL" << endl;
        return head;
    }

    prev->next = prev->next->next;
    delete temp;

    return head;
}

node *InsertHead(node *head, int val)
{

    if (head == NULL)
        return new node(val);

    node *newHead = new node(val);
    newHead->next = head;
    return newHead;

    // return new node(val,head);
}

node *InsetTail(node *head, int val)
{

    if (head == NULL)
        return new node(val);

    node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    node *newEl = new node(val);
    temp->next = newEl;
    return head;
}

node *InsertAtKth(node *head, int k, int val)
{

    if (head == NULL)
    {
        if (k == 1)
        {
            return new node(val);
        }
        else
        {
            cout << "This is not practical\n";
        }
    }

    if (k == 1)
    {
        node *temp = new node(val);
        temp->next = head;
        return temp;
    }
 
    node *temp = head;
    int count = 1;

    while (temp != nullptr && count != k - 1)
    {

        temp = temp->next;
        count++;
    }

    node *Nod = new node(val);
    Nod->next = temp->next;
    temp->next = Nod;
    return head;
}

node* InsertBeforeElement(node* head, int element , int val){

    if(head==NULL){
        cout <<"Yahan toh koi element hi nhi hai\n";
    }

    if(head->data==element){

        return new node(val,head);
    }

    node* temp=head;

    while(temp->next->data!=element){

        temp=temp->next;
    }

    node* Nod= new node(val);
    Nod->next=temp->next;
    temp->next=Nod;
    return head;
}

int main()
{

    vector<int> arr = {2, 1, 5, 7, 4};
    // vector<int> arr = {};
    node *head = arrTOLL(arr);
    // cout << head->data << endl;
    // cout << head->next->data << endl;
    // cout << head->next->next->data<< endl;
    // cout << head->next->next->next->data<< endl;
    // cout << head->next->next->next->next->data<< endl;

    // PrintLL(head);

    // cout <<LenOfLL(head) << endl;

    // cout << SearchLL(head,4)<<endl;

    // ***DELETION***

    // head=deleteHead(head);

    // PrintLL(head);
    // cout <<LenOfLL(head) << endl;

    // head=deleteLast(head);
    // PrintLL(head);

    // head=deletePosition(head,3);
    // PrintLL(head);
    // head = deletePosition(head, 5);
    // PrintLL(head);

    // head = deleteK(head, 7);
    // PrintLL(head);

    // head = deleteValue(head, 10);
    // PrintLL(head);

    // ****INSERTION*****

    // without using any function ,Insertion in the begining:->  head= new node(12,head);
    //  PrintLL(head);

    // PrintLL(InsertHead(head,12));
    // OR:-  head= InsertHead(head,1253);
    // PrintLL(head);

    // head= InsetTail(head,5534);
    // PrintLL(head);
    // PrintLL(InsetTail(head,34));

    // head = InsertAtKth(head, 4, 65);
    // PrintLL(head);

     head=InsertBeforeElement(head,4,15);
     PrintLL(head);

    return 0;
}