#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
    
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int K, const int N, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, N,  Low, High, 0);
    if (rowNo < K - 1)
        CreateRows(a, K, N, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int K, const int N, int rowNo)
{
    PrintRow(a, rowNo, N, 0);
    if (rowNo < K - 1)
        PrintRows(a, K, N, rowNo + 1);
    else
        cout << endl;
}

int minElem(int** a, const int N, int rowNo, int colNo, int min)
{
    if (a[rowNo][colNo] < min)
    {
        min = a[rowNo][colNo];
    }
    
   
    if (colNo < N - 1)
        min = minElem(a, N, rowNo, colNo + 1, min);
    else return min;

}

int sumElem(int** a, const int K, const int N, int rowNo, int suma)
{
    suma += minElem(a, N, rowNo, 0, a[rowNo][0]);
    if (rowNo < K - 1)
        sumElem(a, K, N, rowNo + 1, suma);
    else 
        return suma;
}

int main()
{
    srand((unsigned)time(NULL));

    int K, N;
    cout << "K = "; cin >> K;
    cout << endl;
    cout << "N = "; cin >> N;
    cout << endl;

    int** a = new int* [K];
    for (int i = 0; i < K; i++)
        a[i] = new int[N];

    int Low = -10, High = 10;
    CreateRows(a, K, N, Low, High, 0);

    PrintRows(a, K, N, 0);

    
    cout << "suma min elem = " << sumElem(a, K, N, 0, 0);
   

    for (int i = 0; i < K; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
