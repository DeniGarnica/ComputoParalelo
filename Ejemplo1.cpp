#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <omp.h>
#include<fstream>

void Suma_vectores(float* c, float* a, float* b, long int N) {
	#pragma omp parallel shared(a,b,c, N)
	{
		
	#pragma omp for
		for (long int i = 0; i < N; i++)
		{
			int tid = omp_get_thread_num();
			std::cout<<"Hola Mundo, soy el Hilo = "<< tid<<'\n';
			c[i] = a[i] + b[i];
		}
	}
}


int main(void) {
	omp_set_num_threads(8);
	std::cout << "time_cpu_seconds" << std::endl;
	float* a_h, * b_h, * c_h;
	long int N = 100000000;
	double t_int, t_fin, time_cpu_seconds;

	size_t size_float = N * sizeof(float);
	a_h = (float*)malloc(size_float);
	b_h = (float*)malloc(size_float);
	c_h = (float*)malloc(size_float);


	for (long int i = 0; i < N; i++) {
		a_h[i] = (float)i;
		b_h[i] = (float)(i+1);
	}

	t_int = clock();
	Suma_vectores(c_h, a_h, b_h, N);
	t_fin = clock();
	time_cpu_seconds = (t_fin - t_int) / CLOCKS_PER_SEC;
	
	std::cout << time_cpu_seconds << std::endl;

	free(a_h);
	free(b_h);
	free(c_h);

	return 0;
}
