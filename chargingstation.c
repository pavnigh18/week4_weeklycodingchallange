#include <stdio.h>

int chargingStation(int charge[], int cost[], int n)

{
    
int start = 0;
    int tank = 0;
    int total = 0;

    for (int i = 0; i < n; i++) {
        int diff = charge[i] - cost[i];
        tank += diff;
        total += diff;

        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }

    if (total < 0)
        return -1;

    return start;

}

void printArray(int arr[], int n)

{
    printf("[");
    for (int i = 0; i < n; i++)
    
{
        printf("%d", arr[i]);
        if (i != n - 1)
            printf(", ");
    }
    printf("]");
}

int isValidInput(int charge[], int cost[], int n)
{
    if (n <= 0)
        return 0;

    for (int i = 0; i < n; i++)
    {
        if (charge[i] < 0 || cost[i] < 0)
            return 0;
    }

    return 1;
}

void runTestCase(int charge[], int cost[], int n, int testNum)
{
    printf("Test %d:\n", testNum);
    printf("  charge = ");
    printArray(charge, n);
    printf("\n  cost   = ");
    printArray(cost, n);
    printf("\n");

    if (!isValidInput(charge, cost, n))
    {
        printf("  Result: invalid input, skipping\n\n");
        return;
    }

    int result = chargingStation(charge, cost, n);

    if (result == -1)
        printf("  Result: not possible to complete the circuit\n\n");
    else
        printf("  Result: start from station %d\n\n", result);
}

int main()
{
    int charge1[] = {1, 2, 3, 4, 5};
    int cost1[]   = {3, 4, 5, 1, 2};
    runTestCase(charge1, cost1, 5, 1);

    int charge2[] = {2, 3, 4};
    int cost2[]   = {3, 4, 3};
    runTestCase(charge2, cost2, 3, 2);

    int charge3[] = {5, 1, 2, 3, 4};
    int cost3[]   = {4, 4, 1, 5, 1};
    runTestCase(charge3, cost3, 5, 3);

    int charge4[] = {5};
    int cost4[]   = {5};
    runTestCase(charge4, cost4, 1, 4);

    return 0;
}
