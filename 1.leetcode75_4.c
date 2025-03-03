#include <stdio.h>
#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int i, count=0;
    if(flowerbedSize==1){
        return (flowerbed[0]==0)?(n<=1):(n==0);
    }
    if(flowerbedSize>=2 && flowerbed[0]==0 && flowerbed[1]==0){
        flowerbed[0]=1;
        ++count;
    }
    if(flowerbedSize>=2 && flowerbed[flowerbedSize-1]==0 && flowerbed[flowerbedSize-2]==0){
        flowerbed[flowerbedSize-1]=1;
        ++count;
    }
    for(i=1; i<(flowerbedSize-1); i++){
        if(!flowerbed[i]){
            if(flowerbed[i-1]==0 && flowerbed[i+1]==0){
                flowerbed[i]=1;
                ++count;
            }
        }
    }
    if(count>=n){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int i, t, flowerbedSize, n, flowerbed[50];
    printf("Testcase: "); scanf("%d", &t);
    while(t--){
        printf("flowerbedSize: "); scanf("%d", &flowerbedSize);
        printf("n: "); scanf("%d", &n);
        for(i=0; i<flowerbedSize; i++){
            printf("flowerbed[%d]: ", i); scanf("%d", &flowerbed[i]);

        }
        printf("%s ", canPlaceFlowers(flowerbed, flowerbedSize, n)?"true":"false");
        printf("\n------------------\n");
        
    }

    return 0;
}