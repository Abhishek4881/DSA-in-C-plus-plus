#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    int arr[n];

    cout << "Enter the values inside the array\n";

    unordered_map<int, int> mp;
    // map<int, int> mp;
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
        mp[arr[i]]++;
    }

    // Precomputation

    // map<int,int>mpp;

    // for(int i=0; i<n;i++){

    //    mpp[arr[i]]++;
    // }

    int q;
    cout << "Enter the query no.\n";
    cin >> q;

    while (q--)
    {

        int num;
        cout << "Enter the no. whose frequency u want\n";
        cin >> num;

        cout << "Frequency of " << num << " is " << mp[num] << endl;
    }
}