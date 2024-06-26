#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    int arr[n];

    cout << "Enter the values inside the array\n";

    for(int i=0; i<n;i++){

        cin >> arr[i];
    }

    //Precomputation

    int hash[13]={0};

    for(int i=0; i<n;i++){

        hash[arr[i]]+=1;
    }


    int q;
    cout << "Enter the frequency no.\n";
    cin >> q;
    
    while(q--){

        int num;
        cout << "Enter the no. whose frequency u want\n";
        cin >> num;

        cout << "Frequency of " << num << " is " << hash[num] << endl;
    }


}