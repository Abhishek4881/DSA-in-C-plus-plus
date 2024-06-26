#include<bits/stdc++.h>
using namespace std;

int main(){

    //FOR ONLY LOWER CASE 
    string s;
    cout << "Enter the string\n";
    cin >>s;

    //Precompute
    int hash[26]={0};

    for(int i=-0; i< s.length();i++){

        hash[s[i]-'a']++;
    }

    int q;
    cout << "Enter the querry no.\n";
    cin >> q;

    while(q--){

        char ch;
        cout << "Enter the character \n";
        cin >> ch;

        cout << hash[ch-'a']<< endl;
    }

   // FOR BOTH UPPER AND LOWER CASE
    // string s;
    // cout << "Enter the string\n";
    // cin >>s;

    // //Precompute
    // int hash[256]={0};

    // for(int i=-0; i< s.length();i++){

    //     hash[s[i]]++;
    // }

    // int q;
    // cout << "Enter the querry no.\n";
    // cin >> q;

    // while(q--){

    //     char ch;
    //     cout << "Enter the character \n";
    //     cin >> ch;

    //     cout << hash[ch]<< endl;
    // }

    return 0;
}