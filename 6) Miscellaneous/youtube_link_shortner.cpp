// Transforms long youtube links into short youtu.be links
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i = 2;
    string link;
    cout << "Enter youtube link:" << endl;
    cin >> link;

    int pos = link.find("v=");

    cout << "\nShortened youtube link:" << endl;
    cout << "https://youtu.be/";
    do
    {
        cout << link[pos + i++];
    } while (!(link[pos + i] == '\0' || link[pos + i] == '&' || link[pos + i] == '?'));

    cin.sync();
    cin.get();
    return 0;
}