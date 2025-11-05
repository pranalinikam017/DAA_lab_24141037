#include <stdio.h>

int BinSearch(int arr[], int key, int low, int high)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (key == arr[mid])
        return mid;
    else if (key < arr[mid])
        return BinSearch(arr, key, low, mid - 1);
    else
        return BinSearch(arr, key, mid + 1, high);
}

int IterBinSearch(int arr[], int size, int key)
{
    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    int i, size, key, res;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d sorted numbers: ", size);
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Enter the number to be found: ");
    scanf("%d", &key);

    res = BinSearch(arr, key, 0, size - 1);
    if (res == -1)
        printf("Using recursion: Element not found.\n");
    else
        printf("Using recursion: Element found at index %d\n", res);

    res = IterBinSearch(arr, size, key);
    if (res == -1)
        printf("Using iteration: Element not found.\n");
    else
        printf("Using iteration: Element found at index %d\n", res);

    return 0;
}