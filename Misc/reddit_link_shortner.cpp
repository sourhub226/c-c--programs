// Transforms long reddit post links into short redd.it links
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i = 9;
    string link;
    cout << "Enter reddit link:" << endl;
    cin >> link;

    int pos = link.find("comments");

    cout << "\nShortened reddit link:" << endl;
    cout << "https://redd.it/";
    do
    {
        cout << link[pos + i++];
    } while (link[pos + i] != '/');

    cin.sync();
    cin.get();
    return 0;
}