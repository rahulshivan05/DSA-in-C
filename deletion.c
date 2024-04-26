#include <stdio.h>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int index = 2;
    int size = 4;

    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }

    size--;

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
