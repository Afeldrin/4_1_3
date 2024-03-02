#include <iostream>
#include <string>

#define Z 1 // 1 - жадный алгоритм, иное - прямой перебор

using namespace std;

double maximum(double arr[], const int N)
{
    double max = 0;

    for (unsigned i = 0; i < N; i++) {
        if (arr[i] > max) {
            max = arr[i];
        };
    };
    return max;
};

int maximum_index(double arr[], const int N)
{
    double max = 0;
    int a = 0;
    for (unsigned i = 0; i < N; i++) {
        if (arr[i] > max) {
            max = arr[i];
            a = i;
        };
    };
    return a;
};


int main()
{
    const int N = 7;
    double masses[N] = {1,2,3,5,9,4,8};
    double values[N] = {3,2,1,4,7,10,11};
    const double W = 15;
    double M = 0;
    double P = 0;
    
#if Z == 1
    string indexes = "";
    double* relative_values{ new double[N] };

    for (unsigned i = 0; i < N; i++)
    {
        *(relative_values + i) = values[i] / masses[i];
    }


    while (M < W)

    {
        int index = maximum_index(relative_values, N);

        cout << "index " << index << endl;

        double max = maximum(relative_values, N);

        cout << "max " << max << endl;

        relative_values[index] = 0;

        if (max == 0) {
            break;
        };

        if ((M + masses[index] <= W) && (masses[index] != 0))
        {
            M = M + masses[index];
            P = P + values[index];
            indexes = indexes + to_string(index);
        }



    };

    cout << M << endl;
    cout << P << endl;
    cout << indexes << endl; // асимптотика О(N^2), выдаст неверное решение в сиутации: нужно выбрать 100 рублей купюраими по 90, 50, 1 р, правильно 50 + 50, алгоритм выдаст 90 + 1 + 1 + ... + 1

#else
    
    int k = powf(2, N);

    double max = 0;

    string indexes;

    for (int i = 0; i < k; i++)
    {   
        cout << "{";
        M = 0;
        P = 0;
        string temp = "";

        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j)) 
            {
                cout << masses[j] << " ";
                M = M + masses[j];
                P = P + values[j];
                temp = temp + to_string(j);
                
            }

        }
        cout << "}" << endl;

        if ((max < P) and (M <= W)) {
            max = P;
            indexes = temp;
        }

    }



    cout << max << endl;
    cout << indexes << endl;
#endif

    return 0;
}
