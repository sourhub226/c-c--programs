#include <iostream>
#include <iostream>
using namespace std;

int main()
{
    string p = "abacab";
    int i = 1, j = 0;
    int k = 0;
    int f[p.length()];
    f[0] = 0;

    cout << endl;
    cout << "                               f[0]=" << f[0] << endl;
    while (i < p.length())
    {
        if (p[j] == p[i])
        {
            cout << "j=" << j << " "
                 << "i=" << i << "    ";
            cout << "Compare " << p[j] << " with " << p[i] << "    ";
            f[i] = j + 1;
            cout << "f[" << i << "]=" << f[i];
            i++;
            j++;
        }
        else if (j > 0)
        {
            cout << "j=" << j << " "
                 << "i=" << i << "    ";
            cout << "Compare " << p[j] << " with " << p[i] << "    ";
            j = f[j - 1];
        }
        else
        {
            cout << "j=" << j << " "
                 << "i=" << i << "    ";
            cout << "Compare " << p[j] << " with " << p[i] << "    ";
            f[i] = 0;
            cout << "f[" << i << "]=" << f[i];
            i++;
        }
        cout << endl;
    }
}