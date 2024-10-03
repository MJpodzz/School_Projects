//Mahmoud Hafez
//primes.c
//Lab 4: Part 2: prime numbers
//finds all the prime numbers between 1 and 1,000
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool isPrime[1000];
    int i, j;

    // Initialize all elements to true
    for (i = 0; i < 1000; i++) {
        isPrime[i] = true;
    }

    // Implementing Sieve of Eratosthenes
    for (i = 2; i * i < 1000; i++) {
        if (isPrime[i]) {
            for (j = i * i; j < 1000; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Printing prime numbers
    int count = 0;
    for (i = 2; i < 1000; i++) {
        if (isPrime[i]) {
            printf("%4d", i);
            count++;
            if (count % 10 == 0) {
                printf("\n");
            }
        }
    }
    printf("\n");
    return 0;
}
