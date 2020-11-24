#include <stdio.h>
#include <stdlib.h>


void PrintNums(int *nums, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void MySwap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void SubPermutation(int* nums, int curIndex, int size)
{
    if (curIndex == size - 1) {
        PrintNums(nums, size);
        return;
    }

    SubPermutation(nums, curIndex + 1, size);

    for (int i = curIndex+1; i < size; i++) {
        if (nums[curIndex] == nums[i]) {
            continue;
        }
        MySwap(&nums[curIndex], &nums[i]);
        SubPermutation(nums, curIndex + 1, size);
        MySwap(&nums[curIndex], &nums[i]);
    }
}

int* Permutation(int* nums, int size)
{
    SubPermutation(nums, 0, size);
}

int main()
{
    int nums[5] = {1,1,3};
    Permutation(nums, 3);
    return 0;
}