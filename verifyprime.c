#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int primes[100]; // since the array can't be dynamic, we declare it statically
    int n = 67; //amount of primes to check
    for(int i = 0; i <= n; i++)
        primes[i] = 1;
    primes[0] = 0;
    primes[1] = 0;
    //sqrt because if more than sqrt, then it repeats itself
    //n = 12
    //{2, 6} = {6, 2}
    //so we can search no further than sqrt(12), which is ~3.4
    for(int i = 2; i <= sqrt(n); i++) {
        if (primes[i] == 1){
            for(int j = 2; i * j <= n; j++){
                primes[i*j]=0;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if (primes[i]) {
            printf("Primes: %d \n", i);
        } else{
        printf("%d \n", i);
        }
    }
    return 0;
}
// Time complexity - O ( n * log log n)