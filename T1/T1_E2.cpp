/* Tarea 1. Implementar los siguientes ejercicios de forma secuencial y en paralelo
usando OpenMP:
2. La multiplicación de dos matrices cuadradas de tamaño N x N.

Este codigo se corre poniendo en la terminal:
gcc T1_E2.cpp -lstdc++ -fopenmp -o T1_E2
y despues 
.\T1_E2.exe
*/

#include<iostream>
#include<fstream>
#include<vector>
#include <time.h>

//OpenMP
#include <omp.h>
int main()
{
    omp_set_num_threads(8); //Debido a que mi laptop tiene 8 procesador logicos

    // Tamaño de las matrices
    int n = 1000;
    std::vector<std::vector<int>> A1(n, std::vector<int>(n));
    std::vector<std::vector<int>> A2(n, std::vector<int>(n));
    std::vector<std::vector<long long>> B(n, std::vector<long long>(n));

    // Inicialización de las matrices 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A1[i][j] = i + j + 1;
            A2[i][j] = i + j + 1;
        }
    }

    // Variable para almacenar la suma total
    long long suma = 0;

    // Inicio de la sección paralela
    double t_int = clock();
    #pragma omp parallel for shared(A1, A2, B)
    for (int i = 0; i < n; i++) {
        int tid = omp_get_thread_num();
		std::cout<<"Hola mundo, soy el hilo = "<< tid <<'\n';
        for (int j = 0; j < n; j++) {
            int suma = 0;
            for (int k = 0; k < n; k++) {
                suma += A1[i][k] * A2[k][j];
            }
            B[i][j] = suma;
        }
    }
    double t_fin = clock();
    double time_cpu_seconds = (t_fin - t_int) / CLOCKS_PER_SEC;

	std::cout << "El tiempo total de ejecucion fue: " <<time_cpu_seconds << std::endl;

    return 0;
}
