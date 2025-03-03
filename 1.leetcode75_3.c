#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    *returnSize = candiesSize;
    bool *returnArray=(bool*)malloc(*returnSize*sizeof(bool));
    //tim so max trong mang candies
    int max= candies[0], i;
    for(i=0; i<candiesSize; i++){
        if(max< candies[i]){
            max= candies[i];
        }
    }

    for(i=0; i<*returnSize; i++){
        if(candies[i]+extraCandies >= max) {
            returnArray[i]= true;
        }
        else returnArray[i]=false;
    }
    return returnArray;
}   
int main(){
    int t, i;
    int candies[100];
    printf("Testkey: "); scanf("%d", &t);
    while(t--){
        int candiesSize, extraCandies, returnSize;
        printf("candiesSize: "); scanf("%d", &candiesSize);
        printf("extraCandies: "); scanf("%d", &extraCandies);
        for(i=0; i<candiesSize; i++){
            printf("candies[%d]: ", i); scanf("%d", &candies[i]);
        }
        bool* result=(bool*)malloc(candiesSize*sizeof(bool));
        result= kidsWithCandies(candies, candiesSize, extraCandies, &returnSize);
        for(i=0; i<returnSize; i++){
            printf("%s  ", result[i]?"true":"false");
        }
        printf("\n");
        free(result);

    }


    return 0;
}