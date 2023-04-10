#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define m 2000

float a[m][m];
float b[m][m];
float c[m][m];

void serial();

void parell();

int main() {
	clock_t start, end;

	int i, j, k;
	srand(0);
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			a[i][j] = (float)rand() / (RAND_MAX);
			b[i][j] = (float)rand() / (RAND_MAX);
			c[i][j] = 0;
		}
	}

	omp_set_num_threads(4);
	int pnum = omp_get_num_procs();
	fprintf(stderr, "Thread_pnum = %d\n", pnum);

	serial();
	parell();

	getchar();
	return 0;
}

void serial() {
	clock_t start, end;
	int i, j, k;

	start = clock();
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			for (k = 0; k < m; k++) {
				c[i][j] = c[i][j] + a[i][k] * b[k][j];
			}
		}
	}
	end = clock();
	printf("serial matrix multiply time: %0.6lf\n", ((double)end - start) / CLOCKS_PER_SEC);
}

void parell() {
	clock_t start, end;
	int i, j, k;

	start = clock();
#pragma omp parallel shared(a,b,c) private(j,k)
	{
#pragma omp for //schedule(dynamic)
		for (i = 0; i < m; i++) {
			// printf("i = %d, thread_num:%d\n", i, omp_get_thread_num());
			for (j = 0; j < m; j++) {
				// printf("j = %d, thread_num:%d\n",j, omp_get_thread_num());
				for (k = 0; k < m; k++) {
					c[i][j] = c[i][j] + a[i][k] * b[k][j];
					// printf("thread_num:%d\n", omp_get_thread_num);
				}
			}
		}
	}
	end = clock();
	printf("parell matrix multiply time: %0.6lf\n", ((double)end - start) / CLOCKS_PER_SEC);
}