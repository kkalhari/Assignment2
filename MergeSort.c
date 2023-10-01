#include <stdio.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right) {
	    int i, j, k;
	        int n1 = mid - left + 1;
		    int n2 = right - mid;

		      
		        int L[n1], R[n2];

			    for (i = 0; i < n1; i++)
				            L[i] = arr[left + i];
			        for (j = 0; j < n2; j++)
					        R[j] = arr[mid + 1 + j];

				    i = 0; 
				        j = 0; 
					    k = left; 
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


						    while (i < n1) {
							            arr[k] = L[i];
								            i++;
									            k++;
										        }


						        while (j < n2) {
								        arr[k] = R[j];
									        j++;
										        k++;
											    }
}

void mergeSort(int arr[], int left, int right) {
	    if (left < right) {

		            int mid = left + (right - left) / 2;

			         
			            mergeSort(arr, left, mid);
				            mergeSort(arr, mid + 1, right);

					            merge(arr, left, mid, right);
						        }
}

int main() {
	    int arr[] = {12, 11, 13, 5, 6, 7};
	        int arr_size = sizeof(arr) / sizeof(arr[0]);

		 
		    clock_t start_time = clock();
		        mergeSort(arr, 0, arr_size - 1);
			    clock_t end_time = clock();

			        double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

				    printf("Sorted array: ");
				        for (int i = 0; i < arr_size; i++)
						        printf("%d ", arr[i]);
					    printf("\n");

					        printf("Execution Time: %f seconds\n", execution_time);

						    return 0;
}

