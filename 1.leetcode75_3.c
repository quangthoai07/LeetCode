#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    *returnSize = candiesSize;  // Gán dúng kích thu?c cho returnSize
    bool* returnArray = (bool*)malloc((*returnSize) * sizeof(bool));  // Cap phat returnArray

    // Tìm giá tri lop nhat trong mang candies
    int max = candies[0], i=0;
    for (i = 1; i < candiesSize; i++) {  
        if (candies[i] > max) {
            max = candies[i];
        }
    }

    // kiem tra dieu kien bai toan
    
    for (i = 0; i < candiesSize; i++) {
        if (candies[i] + extraCandies >= max) {
            returnArray[i] = true;
        } else {
            returnArray[i] = false;
        }
    }

    return returnArray;  // return mang returnArray
}

int main() {
    int t, i;
    printf("t:" );scanf("%d", &t);  // So luong testcase

    while (t--) {
        int candiesSize, extraCandies, returnSize;
        printf("candiesSize: "); scanf("%d", &candiesSize);  // nhap so luong mang candies
        printf("extraCandies:"); scanf("%d", &extraCandies);  // nhap so luon keo extra

        int candies[candiesSize];  // mang candies
        for (i = 0; i < candiesSize; i++) {
            printf("candies[%d]: ", i);scanf("%d", &candies[i]);
        }

        bool* result = kidsWithCandies(candies, candiesSize, extraCandies, &returnSize);

        // in ket qua
        for (i = 0; i < returnSize; i++) {
            printf("%s ", result[i] ? "true" : "false");
        }
        printf("\n");

        free(result);  // giai phong bo nho
    }

    return 0;
}
