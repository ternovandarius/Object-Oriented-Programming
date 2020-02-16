#include <stdio.h>

int check_prime(int x) {
    /*
     * This function checks whether an integer x is prime.
     * Input: x
     * Preconditions: x - integer
     * Output: 1 or 0
     * Postconditions: 1 if x is prime, 0 otherwise
     */
    int d=0;
    if (x <= 1)
        return 0;
    if (x % 2 == 0 && x != 2)
        return 0;
    for (d = 3; d * d <= x; d = d + 2)
        if (x % d == 0)
            return 0;
    return 1;
}

void test_check_prime()
{
    int x=1;
    if (check_prime(x)!=0)
        printf("Error!");
    int y=2;
    if (check_prime(y)!=1)
        printf("Error!");
}

int generate_primes(int x, int lst[]){
    /*
     * This function generates all the prime numbers smaller than x, and also returns j-1, which is the length of the array.
     * Input: x, lst[]
     * Preconditions: x - integer, lst[] - empty array
     * Output: j-1
     * Postconditions: lst[] - array containing the prime numbers smaller than x; j-1 - the length of the array
     */
    int i, j=1;
    for (i=1; i<x; i++)
        if (check_prime(i)==1)
            lst[j++]=i;
    return j-1;
}

void test_generate_primes()
{
    int lst[10];
    if (generate_primes(13, lst)!=5)
        printf("Error!");
}

void point_a(int l[])
{
    /*
     * This function solves the following problem:
     * Generate all the prime numbers smaller than a given natural number n.
     *
     * Input: l[]
     * Preconditions: l[] - empty array
     * Output: -
     * Postconditions: l[] will contain all the prime numbers smaller than n, and l is printed in the console.
     */
    int n, size, ok=1;
    while (ok==1) {
        printf("Please enter a number. \n");
        scanf_s("%d", &n);
        if (n>=0)
            ok=0;
        else
            printf("Invalid input! Please enter a positive integer.\n");
    }
    size=generate_primes(n, l);
    for (int i=1; i<=size; i++)
        printf("%d \n", l[i]);
}

int read_array(int b[]) {
    /*
     * This function reads an array of numbers, up to n numbers.
     * Input: b[], n
     * Preconditions: b - (preferably) empty array; n - number of elements in array
     * Output: -
     * Postconditions: array b now contains n numbers read from keyboard
     */
    int i, n, ok=1;
    while(ok==1) {
        printf("Please enter the length of the array. \n");
        scanf("%d", &n);
        if (n>0)
            ok=0;
        else
            printf("Invalid input! Please enter a positive number.\n");
    }
    printf("Please enter %d numbers. \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    return n;
}

void point_b(int b[])
{
    /*
     * This function solves the following problem:
     * Given a vector of numbers, find the longest increasing contiguous subsequence,
     * such the sum of that any 2 consecutive elements is a prime number.
     *
     * Input: b[]
     * Preconditions: b - empty array
     * Output: -
     * Postconditions: prints the list of answers to the problem
     */
    int c_len, max_len, c_st_p, c_end_p, max_st_p, max_end_p, i, j, n;
    n=read_array(b);
    max_len=0;
    max_st_p=0;
    max_end_p=0;
    for (i=0; i<n-1; i++) {
        c_st_p = i;
        c_end_p=i;
        c_len=0;
        for (j = i + 1; j <= n-1; j++) {
            if (b[j]>b[j-1] && check_prime(b[j-1]+b[j])==1){
                c_len++;
                c_end_p=j;
            }
            else
                break;
        }
        if (c_len>max_len)
        {
            max_len=c_len;
            max_st_p=c_st_p;
            max_end_p=c_end_p;
        }
    }
    for (i=max_st_p; i<=max_end_p; i++)
        printf("%d ", b[i]);
    printf("\n");
}

void tests()
{
    test_check_prime();
    test_generate_primes();
}

void point_c() {
    /*
     * This function solves the following problem:
     * Determine the first n pairs of twin numbers, where n is a given natural and non-nullnumber.
     * Two prime numbers p and q are called twin if q –p = 2.
     *
     * Input:n - from keyboard
     * Preconditions:n - natural number, non-null
     * Output: on screen
     * Postconditions: the first n pairs of "twin" numbers
     */
    int n, first = 2, last = 2, i = 2, counter = 0;
    int ok = 1;
    while (ok == 1)
    {
        printf("Please insert a number.");
        scanf("%d", &n);
        if (n>0)
            ok=0;
        else
            printf("Invalid input! Try entering a natural, non-null number.\n");
    }
    while(counter!=n)
    {
        if (check_prime(i)==1)
        {
            first=last;
            last=i;
            if (last-first==2)
            {
                printf("(%d, %d) ", first, last);
                counter++;
            }
        }
        i++;
    }
    printf("\n");
}
int main() {
    tests();
    int l[20], b[20], choice=0, ok=0;
    while (ok==0) {
        printf("Press 1 to solve the first point of the problem. \nPress 2 to solve the second point of the problem. \nPress 3 to solve the third point of the problem. \nPress 4 to exit. \n");
        scanf("%d", &choice);
        if (choice == 1) {
            point_a(l);
        }
        else if (choice == 2) {
            point_b(b);
        }
        else if (choice == 4){
            ok=1;
        }
        else if (choice == 3){
            point_c();
        }
        else
            printf("Invalid input!\n");
    }
    return 0;
}