/* Tarea 2. 

Este codigo se corre poniendo en la terminal:
gcc T2_E2.cpp -lstdc++ -fopenmp -o T2_E2
y despues 
.\T2_E2.exe
*/

#include<iostream>
#include<fstream>
#include<vector>
#include <time.h>
#include <omp.h>

void matrix_mult(int *A, int *B, int *C, int a_1, int a_2, int b_2)
{
    // Multiplicación de matrices en paralelo
    #pragma omp parallel for
    for (int i = 0; i < a_1; i++){
        for (int j = 0; j < b_2; j++){
            C[i * b_2 + j] = 0;
            for (int k = 0; k < a_2; k++){
                C[i * b_2 + j] += A[i * a_2 + k] * B[k * b_2 + j];
            }
        }
    }
}


#include <omp.h>
int main()
{
    srand(time(NULL));

    int m = 2000;
    int k = 5000;
    int n = 2000;

    int *A, *B, *C, *D, *E;

    A = (int *)malloc(m*k * sizeof(int));
    B = (int *)malloc(k*n * sizeof(int));
    C = (int *)malloc(m*n * sizeof(int));
    D = (int *)malloc(n*m * sizeof(int));
    E = (int *)malloc(k*m * sizeof(int));

    // Inicializa matrices
    for (int i = 0; i < m * k; i++) {
        A[i] = rand()%(500);
    }
    for (int i = 0; i < k * n; i++) {
        B[i] = rand()%(500);
    }
    for (int i = 0; i < n * m; i++) {
        D[i] = rand()%(500);
    }

    double t_int = clock();

    omp_set_num_threads(16);

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            matrix_mult(A, B, C, m, k, n);
        }
        #pragma omp section
        {
            matrix_mult(B, D, E, k, n, m);
        }
    }

    double t_fin = clock();
    double time_cpu_seconds = (t_fin - t_int) / CLOCKS_PER_SEC;

    std::cout << "El tiempo total de ejecucion fue: " <<time_cpu_seconds << std::endl;

    return 0 ;
}