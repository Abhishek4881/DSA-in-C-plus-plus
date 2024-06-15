#include<iostream>
using namespace std;

struct node{

    int data;
    struct node*left;
    struct node*right;

    node(int value){

        data= value;
        left=right=NULL;

    }
};

int main() {

    struct node* root=new node(1);

    root->left=new node(2);
    root->right=new node(3);
    root->left->right=new node(5);

    // Optional: Print the tree to verify
    cout << "Root Node: " << root->data << endl;
    cout << "Left Child of Root: " << root->left->data << endl;
    cout << "Right Child of Root: " << root->right->data << endl;
    cout << "Right Child of Left Child: " << root->left->right->data << endl;

    return 0;
}
