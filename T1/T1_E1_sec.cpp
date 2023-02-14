/* Tarea 1. Implementar los siguientes ejercicios de forma secuencial y en paralelo
usando OpenMP:
1. La suma de los elementos de un vector de tamaño N

Este codigo se corre poniendo en la terminal:
gcc Ejemplo1.cpp -lstdc++ -fopenmp -o Ejemplo1
y despues 
.\Ejemplo1.exe
*/

#include<iostream>
#include<fstream>
#include<vector>
#include <time.h>

//OpenMP
#include <omp.h>
int main()
{
    // Tamaño del vector
    long long n = 200000;
    std::vector<int> vec(n);

    // Inicialización del vector con valores
    for (int i = 0; i < n; i++) {
        vec[i] = i + 1;
    }

    // Variable para almacenar la suma total
    long long suma = 0;

    // Sin sección paralela
    double t_int = clock();
    for (int i = 0; i < n; i++) {
        //Veamos en que hilo se encuentra
        int tid = omp_get_thread_num();
		std::cout<<"Hola mundo, soy el hilo = "<< tid <<'\n';
        suma += vec[i];
    }
    double t_fin = clock();
    double time_cpu_seconds = (t_fin - t_int) / CLOCKS_PER_SEC;

    std::cout << "El resultado total es " <<suma << std::endl;
	std::cout << "El tiempo total de ejecucion fue: " <<time_cpu_seconds << std::endl;

    return 0;
}
