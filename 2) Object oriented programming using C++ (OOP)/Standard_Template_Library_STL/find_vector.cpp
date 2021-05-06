// Write a program using the find() algorithm to locate the position of a specified value in a sequence container.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, x;
    vector<int> vec;
    cout << "Enter no of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        vec.push_back(x);
    }

    vector<int>::iterator it;
    cout << endl
         << "Original vector :";
    for (int i = 0; i < vec.size(); i++)
        cout << " " << vec[i];
    int item;
    cout << endl
         << "Enter the elements to be searched: ";
    cin >> item;

    it = find(vec.begin(), vec.end(), item);
    if (it != vec.end())
    {
        cout << "Element " << item << " found at position : ";
        cout << it - vec.begin() + 1 << "\n";
    }
    else
        cout << endl
             << "Element not found.\n\n";
}