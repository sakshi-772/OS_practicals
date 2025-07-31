#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void insertionsort(int arr[],int n)
{
int i,j,key;
for(i=1;i<n;i++)
{
key=arr[i];
for(j=i-1;j>=0 && arr[j]>key;j--)
{
arr[j+1]=arr[j];
}
arr[j+1]=key;
}
}

int main() {
    int n, i;
    int chi_pid,pid;
    int arr[40];
    int carr[40];
    int parr[40];

    printf("Enter number of integers: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        parr[i]=arr[i];
        carr[i]=arr[i];
    }
    printf("parent process id=%d\n",getpid());
    printf("forking child process\n");
    chi_pid =fork();

    if (chi_pid < 0) {
        printf("child process creation is failed\n");
        exit(1);
    }

    else if (chi_pid == 0) {
        // Child process
        printf("the child process\n");
        printf("Child process (PID: %d)\n", getpid());
        printf("child is sort element using insertion sort\n");
        insertionsort(carr,n);
        printf("sorted array by child process\n");
        for(i=0;i<n;i++)
        {
        printf("%d\n",carr[i]);
        }
        printf("child process completed\n");
        sleep(7); // simulate work
        printf("parent of child process %d\n",getpid());
        
    }

    else {
        printf("Child process (PID: %d)\n", getpid());
        // Parent process
        sleep(5);
        printf("Parent process \n");
        printf("The parent %d is sorting array using bubble sort\n",getpid());

        bubbleSort(parr, n);

        printf("Sorted array: \n");
        for (i = 0; i < n; ++i) {
            printf("%d \n", parr[i]);
        }
        printf("\n");
        printf("parent process completed\n");
    }

    return 0;
}


