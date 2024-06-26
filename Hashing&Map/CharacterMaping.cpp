#include<bits/stdc++.h>
using namespace std;

int main(){

    //FOR ONLY LOWER CASE 
    string s;
    cout << "Enter the string\n";
    cin >>s;

    //Precompute
   map<char,int>map;

    for(int i=-0; i< s.length();i++){

       map[s[i]]++;
    }

    //iterating in map
    for(auto it :map){
        cout << it.first<< "->" << it.second << endl;
    }

    int q;
    cout << "Enter the querry no.\n";
    cin >> q;

    while(q--){

        char ch;
        cout << "Enter the character \n";
        cin >> ch;

        cout << map[ch]<< endl;
    }

}