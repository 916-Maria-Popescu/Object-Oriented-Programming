//
// Created by Maria on 03.03.2021.
//
#include <stdio.h>

int prime_number(int nr){
    /* this function checks if a number is prime number(it is divisible only by 1 and itself)
     * returns -> 1 if nr is prime
     *         -> 0 otherwise */
    int i;
    for (i = 2; i <= nr/2; i++){
        if (nr % i == 0){
            return 0;
        }
    }
    return 1;
}

int* first_prime_numbers(int n){
    /* returns the address of a vector which contains the first n prime numbers
     *  max = 1000 */
    int count = 0;
    int nr = 2;
    static int prime_numbers[1000];
    while(count < n){
        if (prime_number(nr) == 1) {
            prime_numbers[count] = nr;
            count ++ ;
        }
        nr = nr + 1;
    }
    return prime_numbers;
}

void exercise_1() {
    int n;
    int i;
    int* p;
    printf("Introduce a number: ");
    scanf("%d", &n);

    p = first_prime_numbers(n);
    printf("The first %d prime numbers are: ", n);
    for ( i = 0; i < n-1; i++ ) {
        printf("%d, ", p[i]);
    }
    printf("%d.", p[n-1]);

}

//--------------------------------------------------------------------------------------------------------------

int relative_prime(int a, int b){

    /* checks if two numbers are relatively prime (the only number that is a divisor of both of them is 1)
     * -> if a < b, we swap them
     * -> if there is nu such number ( < a/2 )
     * returns -> 1 if a and b are rp
     *         -> 0 otherwise*/

    int i;
    // we check if a < b, if so, we swap them (so a will be the greatest number)
    if (a < b){
        a = a - b;
        b = a + b; // b = a-b+b = a
        a = b - a; // a = a-a+b = b
    }

    for (i = 2; i <= a/2; i++){
        if (a % i == 0  && b % i == 0){
            return 0;
        }
    }
    return 1;

}

int* consecutive_relatively_prime(int arr[], int n){
    /* returns the address of a vector which contains the long seq
     *  max = 100 */
    int i, max_len = 0, current_len = 0, first_index;
    static int result[100];
    for(i=0; i < n; i++){
        if (relative_prime(arr[i], arr[i+1]) == 1){
            current_len ++ ;
        }
        else {
            if (current_len > max_len){
                max_len = current_len;
                first_index = i - max_len;
            }
            current_len = 0;
        }
    }
    result[0] = max_len + 1; // the first elem from the array will represent the len
    for(i=1; i <= max_len + 1; i++){
        result[i] = arr[i-1 + first_index];
    }

    return result;
}


void exercise_2() {
    int i,n,arr[100];
    int* p;
    printf("How many numbers do you want to add:");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("-> number %d:",i+1);
        scanf("%d",&arr[i]);
    }

    p = consecutive_relatively_prime(arr, n);
    n = p[0]; // n = max len
    printf("The long seq has %d numbers: ", n);
    for(i = 1; i < n; i++){
        printf("%d, ", p[i]);
    }
    printf("%d.",p[n]);

}


int main() {
    int n=0;
    printf(" 1 -> Ex 1 :Generate the first n prime numbers (n is a given natural number)"
           "\n 2 -> Ex 2 -> Ex 2 :Given a vector of numbers, find the longest contiguous subsequence such that any two consecutive elements are relatively prime.)\n"
           " 3 -> exit\n");
    while( n != 3) {

        printf("\nMy option: ");
        scanf("%d", &n);

        if (n == 1) {
            exercise_1();
        }
        if (n == 2) {
            exercise_2();
        }
    }

}
