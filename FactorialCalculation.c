#include <stdio.h>
#include <time.h>

unsigned long long factorial(int n) {
	            if (n == 0) {
			                                return 1;
							                                } else {
												                                    unsigned long long result = 1;
																                           for (int i = 1; i <= n; ++i) {
																				   						result *= i;
																										                                  }
																			                             return result;
																						                            }
}

int main() {
	            int n = 10; // Change n to calculate factorial for a different number
		    //  Measure execution time
		    clock_t start_time = clock();
		                             unsigned long long result = factorial(n);
					                                  clock_t end_time = clock();

									                                   double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

													                                        printf("Factorial of %d is: %llu\n", n, result);
																		                                         printf("Execution Time: %f seconds\n", execution_time);

																							                                              return 0;
}
