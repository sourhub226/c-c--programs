#include <iostream>
#define MAX 20
using namespace std;

struct product
{
    int product_num;
    int profit;
    int weight;
    float ratio;
    float take_quantity;
};

int main()
{
    product P[MAX], temp;
    int i, j, total_product, capacity;
    float value = 0;
    cout << "ENTER NUMBER OF ITEMS : ";
    cin >> total_product;
    cout << "ENTER CAPACITY OF SACK : ";
    cin >> capacity;
    cout << "\n";

    for (i = 0; i < total_product; ++i)
    {
        P[i].product_num = i + 1;
        cout << "ENTER PROFIT AND WEIGHT OF PRODUCT " << i + 1 << " : ";
        cin >> P[i].profit >> P[i].weight;
        P[i].ratio = (float)P[i].profit / P[i].weight;
        P[i].take_quantity = 0;
    }

    cout << endl;
    for (i = 0; i < total_product; ++i)
        cout << "Product " << i + 1 << " P/W = " << P[i].ratio << endl;

    //HIGHEST RATIO BASED SORTING
    for (i = 0; i < total_product; ++i)
    {
        for (j = i + 1; j < total_product; ++j)
        {
            if (P[i].ratio < P[j].ratio)
            {
                temp = P[i];
                P[i] = P[j];
                P[j] = temp;
            }
        }
    }

    for (i = 0; i < total_product; ++i)
    {
        if (capacity == 0)
            break;
        else if (P[i].weight <= capacity)
        {
            P[i].take_quantity = 1;
            capacity -= P[i].weight;
        }
        else if (P[i].weight > capacity)
        {
            P[i].take_quantity = (float)capacity / P[i].weight;
            capacity = 0;
        }
    }

    cout << "\nPRODUCTS TO BE TAKEN -";
    for (i = 0; i < total_product; ++i)
    {
        cout << "\nTAKE PRODUCT " << P[i].product_num << " : " << P[i].take_quantity * P[i].weight << " UNITS, PROFIT = " << P[i].take_quantity * P[i].profit;
        value += P[i].profit * P[i].take_quantity;
    }

    cout << "\nTHE KNAPSACK VALUE IS : " << value;
    return 0;
}