/* Tarea 1. Implementar los siguientes ejercicios de forma secuencial y en paralelo
usando OpenMP:
4a. Dadas dos matrices A y B de tamaño N x M con valores enteros positivos, programar lo siguiente:
    C_2(i, j) = alpha A(i,j) + (1-alpha)B(i, j), para i = 0, ... , N − 1 y j = 0, ... , M − 1,
    con alpha un valor real constante entre [0,1] y C_2 otra matriz de tamaño N x M.

Este codigo se corre poniendo en la terminal:
gcc T1_E4b.cpp -lstdc++ -fopenmp -o T1_E4b
y despues 
.\T1_E4b.exe
*/

#include<iostream>
#include<fstream>
#include<vector>
#include <time.h>
#include <random>

//OpenMP
#include <omp.h>
int main()
{
    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(0, 1);
    omp_set_num_threads(8); //Debido a que mi laptop tiene 8 procesador logicos

    // Tamaño de las matrices
    int N = 10000;
    int M = 20000;
    std::vector<std::vector<int>> A(N, std::vector<int>(M));
    std::vector<std::vector<int>> B(N, std::vector<int>(M));
    std::vector<std::vector<long long>> C2(N, std::vector<long long>(M));
    double alpha = dist(gen);

    // Inicialización de las matrices 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = i + j + 1;
            B[i][j] = i + j + 1;
        }
    }

    // Variable para almacenar la suma total
    long long suma = 0;

    // Inicio de la sección paralela
    double t_int = clock();
    #pragma omp parallel for shared(A, B, C2)
    for (int i = 0; i < N; i++) {
        int tid = omp_get_thread_num();
		std::cout<<"Hola mundo, soy el hilo = "<< tid <<'\n';
        for (int j = 0; j < M; j++) { 
                C2[i][j] = alpha * A[i][j] + (1-alpha)*B[i][j];
        }
    }
    

    double t_fin = clock();
    double time_cpu_seconds = (t_fin - t_int) / CLOCKS_PER_SEC;

	std::cout << "El tiempo total de ejecucion fue: " <<time_cpu_seconds << std::endl;

    return 0;
}
