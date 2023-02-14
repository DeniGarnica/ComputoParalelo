/* Tarea 1. Implementar los siguientes ejercicios de forma secuencial y en paralelo
usando OpenMP:
3_a. Dado un vector de números reales V de tamaño N, programar lo siguiente:
    S_1[𝑖] = V[i] + V[i + 1] para i = 0, ... , N − 2, con S_1 otro vector de tamaño N − 1.

Este codigo se corre poniendo en la terminal:
gcc T1_E3b_sec.cpp -lstdc++ -fopenmp -o T1_E3b_sec
y despues 
.\T1_E3b_sec.exe
*/

#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    long long n = 500000;
    int *V, *S2;
    V = (int *)malloc(n* sizeof(int));
    S2 = (int *)malloc((n-2)* sizeof(int));

    // Inicialización de V
    for (int i = 0; i < n; i++) {
        V[i] = i;
    }

    // Sin sección paralela
    double t_int = clock();
    for (int i = 0; i < n - 1; i++) {
        int tid = omp_get_thread_num();
		std::cout<<"Hola mundo, soy el hilo = "<< tid <<'\n';
        S2[i] = (V[i + 1] + V[i - 1])/2;
    }
    double t_fin = clock();
    double time_cpu_seconds = (t_fin - t_int) / CLOCKS_PER_SEC;


    std::cout << "El tiempo total de ejecucion fue: " <<time_cpu_seconds << std::endl;
    free(V);
    free(S2);
    return 0;
}