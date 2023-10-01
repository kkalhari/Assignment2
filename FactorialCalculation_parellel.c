#include <stdio.h>
#include <omp.h>

unsigned long long parallelFactorial(int n) {
	    unsigned long long result = 1;

	        #pragma omp parallel for reduction(*:result)
	        for (int i = 1; i <= n; ++i) {
			        result *= i; /*Multiply the current result by the next integer*/
				    }

		    return result;
}

int main() {
	    int n = 20; /*Change n to calculate factorial for a different number

			       Measure execution time*/
	        double start_time = omp_get_wtime();
		    unsigned long long result = parallelFactorial(n);
		        double end_time = omp_get_wtime();

			    double execution_time = end_time - start_time;

			        printf("Factorial of %d is: %llu\n", n, result);
				    printf("Execution Time: %f seconds\n", execution_time);

				        return 0;
}
