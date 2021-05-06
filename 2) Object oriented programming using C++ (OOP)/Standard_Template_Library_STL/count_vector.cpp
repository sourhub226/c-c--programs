// Write a program using the algorithm count() to count how many elements in a container have a specified value.
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
    cout << endl
         << "Original vector :";
    for (int i = 0; i < vec.size(); i++)
        cout << " " << vec[i];

    cout << endl
         << "Enter the no to be counted: ";
    cin >> n;
    cout << "Number of times " << n << " appears = ";
    cout << count(vec.begin(), vec.end(), n);

    return 0;
}
