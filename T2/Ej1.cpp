/*Este codigo se corre poniendo en la terminal:
gcc Ej1.cpp -lstdc++ -fopenmp -o Ej1
y despues 
.\Ej1.exe
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

    omp_set_num_threads(4);
    #pragma omp parallel private(a) firstprivate(b)
    {
        a = 1;
        int id = omp_get_thread_num();
		std::cout<<"Hola mundo, soy el hilo = "<< id <<'\n';
        V1[id * 2] = a + b;
        V1[id * 2 + 1] = 2*b;
    }

    #pragma omp parallel for firstprivate(a, b) lastprivate(c)
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