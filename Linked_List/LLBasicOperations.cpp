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
};

node *arrTOLL(vector<int> &arr)
{

     
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

void PrintLL(node* head){
    
    if(head==NULL)
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
    cout << "nullptr"<< endl;
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

int SearchLL(node* head, int key){
    node *traversal = head;
    while (traversal)
    {
        if(traversal->data==key){
        return 1;
        }
        traversal = traversal->next;
        
    }

    return 0;
}

node* deleteHead(node* head){
    if(head==NULL){
        return head;
    }
    node* temp=head;
    head=head->next;
    delete temp;
    // free (temp);

    return head;
}

node* deleteLast(node* head){

    if(head==NULL || head->next==NULL){
        return NULL;
    }

    node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head;
}

int main()
{

    vector<int> arr = {2, 1, 3, 7, 4};
    // vector<int> arr = {};
    node *head = arrTOLL(arr);
    // cout << head->data << endl;
    // cout << head->next->data << endl;
    // cout << head->next->next->data<< endl;
    // cout << head->next->next->next->data<< endl;
    // cout << head->next->next->next->next->data<< endl;

    PrintLL(head);

    cout <<LenOfLL(head) << endl;

    cout << SearchLL(head,4)<<endl;

    head=deleteHead(head);
    PrintLL(head);
    cout <<LenOfLL(head) << endl;

    head=deleteLast(head);
    PrintLL(head);

}