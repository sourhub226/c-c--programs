// to read well formed formulas (WFFs) in Propositional Logic and determine whether the given WFF is satisfiable or valid.
#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

string infix, postfix, binstring;
stack<long int> opstack;

int priority(char symbol)
{
    switch (symbol)
    {
    case '(':
        return 0;
    case '+':
        return 1;
    case '*':
        return 2;
    default:
        return 0;
    }
}

long int evalpost()
{
    long int a, b, temp, result;
    unsigned int i;
    for (i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] <= '9' && postfix[i] >= '0')
            opstack.push(postfix[i] - '0');
        else
        {
            a = opstack.top();
            opstack.pop();
            b = opstack.top();
            opstack.pop();
            switch (postfix[i])
            {
            case '+':
                temp = b + a;
                break;
            case '*':
                temp = b * a;
                break;
            }
            opstack.push(temp);
        }
    }
    result = opstack.top();
    opstack.pop();
    return result;
}

void infixTOpostfix(string str)
{
    int size = 0;
    for (int k = 0; k < str.length(); k++)
    {
        if (str[k] != '(' && str[k] != ')')
            size++;
    }
    postfix.resize(size);
    unsigned int i, p = 0;
    char next;
    char symbol;
    for (i = 0; i < str.length(); i++)
    {
        symbol = str[i];

        switch (symbol)
        {
        case '(':
            opstack.push(symbol);
            break;
        case ')':
            next = opstack.top();
            opstack.pop();
            while (next != '(')
            {
                postfix[p++] = next;
                next = opstack.top();
                opstack.pop();
            }
            break;
        case '+':
        case '*':
            while (!opstack.empty() && priority(opstack.top()) >= priority(symbol))
            {
                postfix[p++] = opstack.top();
                opstack.pop();
            }
            opstack.push(symbol);
            break;
        default:
            postfix[p++] = symbol;
        }
    }
    while (!opstack.empty())
    {
        postfix[p++] = opstack.top();
        opstack.pop();
    }
    postfix[p] = '\0';
}

void convertInput()
{
    replace(infix.begin(), infix.end(), 'v', '+');
    replace(infix.begin(), infix.end(), 'V', '+');
    replace(infix.begin(), infix.end(), '^', '*');
    replace_if(infix.begin(), infix.end(), ::isalpha, 'a');
    infix.erase(remove_if(infix.begin(), infix.end(), ::isspace), infix.end());
}

void makeBinString(string s, int digitsLeft)
{
    if (digitsLeft == 0)
        binstring.append(s);
    else
    {
        makeBinString(s + "0", digitsLeft - 1);
        makeBinString(s + "1", digitsLeft - 1);
    }
}

string toggleBits(string data, string toFind)
{
    size_t pos = data.find(toFind);
    while (pos != string::npos)
    {
        int bit = stoi(to_string(toFind[1])) == 48 ? 1 : 0;
        data.replace(pos, toFind.size(), to_string(bit));
        pos = data.find(toFind, pos + 1);
    }
    return data;
}

int printTable(int alphabets)
{
    string temp, decision;
    int value = 0, sum = 0;

    for (int i = 0; i < pow(2, alphabets); i++)
    {
        temp = infix;
        for (int j = 0; j < alphabets; j++)
        {
            decision = (binstring[alphabets * i + j] == '0') ? "False" : "True";
            cout << " | " << setw(5) << decision;
            temp[temp.find_first_of('a')] = binstring[alphabets * i + j];
        }

        temp = toggleBits(temp, "~0");
        temp = toggleBits(temp, "~1");
        infixTOpostfix(temp);
        value = evalpost();
        decision = (value == 0) ? "False" : "True";
        cout << " || " << decision << endl;
        sum = sum + max(0, min(value, 1));
    }
    return sum;
}

int main()
{
    int alphabets = 0;
    int result = 0, valid;

    cout << "(Use v/V for OR, ^ for AND, ~ for NOT)" << endl;
    cout << "Enter the wff: ";
    getline(cin, infix);
    cout << endl;

    string::iterator it;
    for (it = infix.begin(); it != infix.end(); it++)
    {
        if (isalpha(*it) && *it != 'v' && *it != 'V')
        {
            alphabets++;
            cout << " | " << setw(5) << left << *it;
        }
    }
    cout << " || " << infix << endl;
    for (int l = 0; l < 9 * (alphabets + 1); l++)
        cout << "-";
    cout << endl;

    convertInput();
    makeBinString("", alphabets);
    result = printTable(alphabets);

    if (result == pow(2, alphabets))
        cout << "\n=> The wff is valid";
    else if (result == 0)
        cout << "\n=> The wff is insatisfiable";
    else
        cout << "\n=> The wff is satisfiable";
}
