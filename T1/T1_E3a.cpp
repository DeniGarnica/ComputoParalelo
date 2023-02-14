/* Tarea 1. Implementar los siguientes ejercicios de forma secuencial y en paralelo
usando OpenMP:
3_a. Dado un vector de números reales V de tamaño N, programar lo siguiente:
    S_1[i] = V[i] + V[i + 1] para i = 0, ... , N − 2, con S_1 otro vector de tamaño N − 1.

Este codigo se corre poniendo en la terminal:
gcc T1_E3a.cpp -lstdc++ -fopenmp -o T1_E3a
y despues 
.\T1_E3a.exe
*/

#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    long long n = 500000;
    int *V, *S1;
    V = (int *)malloc(n* sizeof(int));
    S1 = (int *)malloc((n-1)* sizeof(int));

    // Inicialización de V
    for (int i = 0; i < n - 1; i++) {
        V[i] = i;
    }

    // Inicio de la sección paralela
    double t_int = clock();
    #pragma omp parallel for shared(V, S1)
    for (int i = 0; i < n; i++) {
        int tid = omp_get_thread_num();
		std::cout<<"Hola mundo, soy el hilo = "<< tid <<'\n';
        S1[i] = V[i] + V[i + 1];
    }
    double t_fin = clock();
    double time_cpu_seconds = (t_fin - t_int) / CLOCKS_PER_SEC;


    std::cout << "El tiempo total de ejecucion fue: " <<time_cpu_seconds << std::endl;
    free(V);
    free(S1);
    return 0;
}
