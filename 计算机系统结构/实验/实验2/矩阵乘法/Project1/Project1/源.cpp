#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void add_vectors(float* a, float* b, float* c, int n, int num_threads) {
    int i;
#pragma omp parallel for num_threads(num_threads)
    for (i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }
}

int main() {
    int n = 10000000;
    int num_threads = 4;
    float* a, * b, * c;
    int i;

    // 分配内存
    a = (float*)malloc(n * sizeof(float));
    b = (float*)malloc(n * sizeof(float));
    c = (float*)malloc(n * sizeof(float));

    // 初始化向量
    for (i = 0; i < n; i++) {
        a[i] = i;
        b[i] = i;
    }

    // 串行计算
    double start = omp_get_wtime();
    for (i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }
    double end = omp_get_wtime();
    printf("Serial time: %f seconds\n", end - start);

    // 多线程并行计算
    start = omp_get_wtime();
    add_vectors(a, b, c, n, num_threads);
    end = omp_get_wtime();
    printf("Parallel time: %f seconds\n", end - start);

    // 检查结果
    for (i = 0; i < n; i++) {
        if (c[i] != 2 * i) {
            printf("Error: c[%d] = %f\n", i, c[i]);
            break;
        }
    }
    if (i == n) {
        printf("Result is correct.\n");
    }

    // 释放内存
    free(a);
    free(b);
    free(c);

    return 0;
}