/*Este codigo se corre poniendo en la terminal:
gcc Ej1_sec.cpp -lstdc++ -fopenmp -o Ej1_sec
y despues 
.\Ej1_sec.exe
*/
#include <iostream>
#include <vector>
#include <omp.h>
#include <random>

int main() {
    int a = 2;
    int b = 3;
    int c = 5;
    int V1[8];
    int V2[8];


    a = 1;
    int id = 4;
    V1[id * 2] = a + b;
    V1[id * 2 + 1] = 2*b;
    

    for (int i = 0; i < 8; i++)
    {
        c = a * i + b;
        V2[i] = c;
    }
    
    std::cout << a << " " << b << " " << c <<std::endl;

    for (int i = 0; i < 8; i++)
    {
        std::cout << V1[i]<<" ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 8; i++)
    {
        std::cout << V2[i]<<" ";
    }
    std::cout << std::endl;
    

    return 0;
}