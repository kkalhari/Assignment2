#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void merge(int arr[], int left, int mid, int right) {
	    int i, j, k;
	        int n1 = mid - left + 1;
		    int n2 = right - mid;

		        /* Create temporary arrays*/
		        int L[n1], R[n2];

			    /*Copy data to temporary arrays L[] and R[]*/
			    for (i = 0; i < n1; i++)
				            L[i] = arr[left + i];
			        for (j = 0; j < n2; j++)
					        R[j] = arr[mid + 1 + j];

				    /* Merge the temporary arrays back into arr[left..right]*/
				    i = 0; /*Initial index of left subarray*/
				        j = 0; /* Initial index of right subarray*/
					    k = left; /* Initial index of merged subarray*/
					        while (i < n1 && j < n2) {
							        if (L[i] <= R[j]) {
									            arr[k] = L[i];
										                i++;
												        } else {
														            arr[k] = R[j];
															                j++;
																	        }
								        k++;
									    }

						    /* Copy the remaining elements of L[], if there are any*/
						    while (i < n1) {
							            arr[k] = L[i];
								            i++;
									            k++;
										        }

						        /* Copy the remaining elements of R[], if there are any*/
						        while (j < n2) {
								        arr[k] = R[j];
									        j++;
										        k++;
											    }
}

void parallelMergeSort(int arr[], int left, int right) {
	    if (left < right) {
		            /* Same as (left+right)/2, but avoids overflow for large left and right*/
		            int mid = left + (right - left) / 2;

			            /* Parallelize the divide step*/
			            #pragma omp parallel sections
			            {
					                #pragma omp section
					                parallelMergeSort(arr, left, mid);
							            #pragma omp section
							            parallelMergeSort(arr, mid + 1, right);
								            }

				            /* Merge the sorted halves*/
				            merge(arr, left, mid, right);
					        }
}

int main() {
	    int arr[] = {12, 11, 13, 5, 6, 7};
	        int arr_size = sizeof(arr) / sizeof(arr[0]);

		    /* Measure execution time*/
		    double start_time = omp_get_wtime();
		        parallelMergeSort(arr, 0, arr_size - 1);
			    double end_time = omp_get_wtime();

			        double execution_time = end_time - start_time;

				    printf("Sorted array: ");
				        for (int i = 0; i < arr_size; i++)
						        printf("%d ", arr[i]);
					    printf("\n");

					        printf("Execution Time: %f seconds\n", execution_time);

						    return 0;
}

