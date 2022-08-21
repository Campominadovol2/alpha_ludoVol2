#include <random>
#include <iostream>

using namespace std;

int main()
{
    int vetor[10] = {0};
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 6);

    for (int i = 0; i < 10; i++)
    {
        vetor[i] = dist(gen);
    }
    for (int i = 0; i < 10; i++)
    {
        cout << vetor[i] << "  ";
    }

    return 0;
}