#include <pthread.h>
#include <stdio.h>

// define the array and its length
float arr[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
int len = sizeof(arr) / sizeof(arr[0]);

// define the global variable to hold the sum
float sum = 0.0;

// define a function to add half of the elements from the beginning of the array
void* add_first_half(void *arg)
{
    for (int i = 0; i < len / 2; i++){
        sum += arr[i];
    }
    return NULL;
}

// define a function to add half of the elements from the end of the array 
void* add_second_half(void *arg)
{
    for (int i = len / 2; i < len; i++)
    {
        sum += arr[i];
    }
    return NULL;
}

int main()
{
    // create the threads
    pthread_t t1, t2;
    pthread_create(&t1, NULL, add_first_half, NULL);
    pthread_create(&t2, NULL, add_second_half, NULL);

    // wait for the threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // print the sum of all the elements in the array
    printf("The sum of all elements in the array is: %.2f\n", sum);

    return 0;
}
