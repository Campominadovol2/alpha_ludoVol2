#include <iostream>
using namespace std;

void resto(int vetor[], int tam, int &pass)
{
    for (int i = 0; i < tam; i++)
    {
        if (vetor[i] != 0)
        {
            pass = 1;
            return;
        }
    }
    pass = 0;
}
int main()
{
    int vetor[10]={0}, pass=1;
    for (int i = 0; i < 4; i+=2)
    {
        cout << "Digite um numero";
        cin >> vetor[i];
    }
    for (int i = 0; i < 4; i+=2)
    {
        cout << vetor[i] << "  ";
    }
    cout << "\n";
    resto(vetor, 10, pass);
    cout << "SAIDAAA " << pass;
    return 0;
}