#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long int DnCLongMulti(long int num1, long int num2)
{
    if (num1 < 10 || num2 < 10)
    {
        return num1 * num2;  // Base case: directly multiply small numbers
    }
    int digits1 = log10(num1) + 1;
    int digits2 = log10(num2) + 1;
    int n = fmax(digits1, digits2);
    int m = (n + 1) / 2;  // Divide the number of digits into two halves
    long int power = pow(10, m);

    long int high1 = num1 / power;
    long int low1 = num1 % power;

    long int high2 = num2 / power;
    long int low2 = num2 % power;

    long int ac = DnCLongMulti(high1, high2);  // Recursive call for high parts
    long int bd = DnCLongMulti(low1, low2);    // Recursive call for low parts
    
    long int ad_plus_bc = DnCLongMulti(high1 + low1, high2 + low2);  // Recursive call for cross products
    
    return ac * pow(10, n) + ((ad_plus_bc - ac - bd )* pow(10, n / 2)) + bd;  // Combine the results
}

int main()
{
    long int num1, num2;
    printf("Multiplication of Long Integers using Divide and Conquer approach\n");
    printf("\nEnter the 1st integer: ");
    scanf("%ld", &num1);
    printf("\nEnter the 2nd integer: ");
    scanf("%ld", &num2);
    long int product = DnCLongMulti(num1, num2);
    printf("\nProduct = %ld\n", product);
    return 0;
}
