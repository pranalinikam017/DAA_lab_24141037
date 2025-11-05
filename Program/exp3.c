#include <stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity)
{
    float ratio[20], totalProfit = 0, x[20];
    int i, j;
    float temp;

    for (i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
        x[i] = 0.0;

    float remaining = capacity;

    for (i = 0; i < n; i++)
    {
        if (weight[i] > remaining)
            break;
        else
        {
            x[i] = 1.0;
            totalProfit += profit[i];
            remaining -= weight[i];
        }
    }

    if (i < n)
    {
        x[i] = remaining / weight[i];
        totalProfit += x[i] * profit[i];
    }

    printf("The result vector is: ");
    for (i = 0; i < n; i++)
        printf("%.2f ", x[i]);

    printf("\nMaximum profit is: %.2f\n", totalProfit);
}

int main()
{
    float weight[20], profit[20], capacity;
    int n, i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of items: ");
    for (i = 0; i < n; i++)
        scanf("%f", &weight[i]);

    printf("Enter profits of items: ");
    for (i = 0; i < n; i++)
        scanf("%f", &profit[i]);

    printf("Enter capacity of knapsack: ");
    scanf("%f", &capacity);

    knapsack(n, weight, profit, capacity);
    return 0;
}