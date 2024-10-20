#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High, int i = 0, int j = 0);
void Print(int** a, const int k, const int n, int i = 0, int j = 0);
int MaxInRow(int** a, const int n, int row, int j = 0, int max = 0);
int SearchMinOfMax(int** a, const int k, const int n, int i = 0, int minOfMaxes = 0);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int k, n;

    cout << "Enter number of rows (k): ";
    cin >> k;
    cout << "Enter number of columns (n): ";
    cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    Print(a, k, n);

    int minOfMaxes = SearchMinOfMax(a, k, n);
    cout << "Minimum of the maximum elements in each row = " << minOfMaxes << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High, int i, int j)
{
    if (i == k) return; 
    a[i][j] = Low + rand() % (High - Low + 1);

    if (j == n - 1)
        Create(a, k, n, Low, High, i + 1, 0); 
    else
        Create(a, k, n, Low, High, i, j + 1); 
}

void Print(int** a, const int k, const int n, int i, int j)
{
    if (i == k) return; 
    cout << setw(4) << a[i][j];

    if (j == n - 1)
    {
        cout << endl;
        Print(a, k, n, i + 1, 0); 
    }
    else
        Print(a, k, n, i, j + 1); 
}

int MaxInRow(int** a, const int n, int row, int j, int max)
{
    if (j == n) return max; 
    if (a[row][j] > max)
        max = a[row][j];

    return MaxInRow(a, n, row, j + 1, max); 
}

int SearchMinOfMax(int** a, const int k, const int n, int i, int minOfMaxes)
{
    if (i == k) return minOfMaxes;

    int maxInRow = MaxInRow(a, n, i, 0, a[i][0]);

    if (i == 0)
        minOfMaxes = maxInRow;
    else if (maxInRow < minOfMaxes)
        minOfMaxes = maxInRow;

    return SearchMinOfMax(a, k, n, i + 1, minOfMaxes);
}