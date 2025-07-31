#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i 	< n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
               
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int pid = fork();

    if (pid > 0) {
        
        int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
        int n = sizeof(arr) / sizeof(arr[0]);

        printf("Parent process id %d\n", getpid());
        printf("Parent process sorting array...\n");

     
        printf("Original array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        
        wait(NULL);  
        
        
        printf("Array after child process sorts: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

    } else if (pid == 0) {
        
        int arr[] = {64, 34, 25, 12, 22, 11, 90};
        int n = sizeof(arr) / sizeof(arr[0]);

        printf("Child process id %d\n", getpid());
        printf("Child process sorting array...\n");

      
        bubbleSort(arr, n);

        
        printf("Sorted array by child process: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

       
        sleep(5);
        
       
        printf("Child process id %d\n", getpid());
        printf("Parent id %d\n", getpid());
    } else {
    
        printf("Child process could not be created.\n");
    }

    return 0;
}

