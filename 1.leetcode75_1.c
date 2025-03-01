#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* mergeAlternately(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int totalLen = len1 + len2 + 1;  
    char* mergeWord = (char*)malloc(totalLen * sizeof(char));

    if (mergeWord == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    int i = 0, j = 0, k = 0;

    while (i < len1 && j < len2) {
        mergeWord[k++] = word1[i++];
        mergeWord[k++] = word2[j++];
    }

    while (i < len1) {
        mergeWord[k++] = word1[i++];
    }

    while (j < len2) {
        mergeWord[k++] = word2[j++];
    }

    mergeWord[k] = '\0';  

    return mergeWord;
}

int main() {
    char s1[100], s2[100];
    int t;
    scanf("%d", &t);
    fflush(stdin);
    while(t--){
    	printf("Enter first string: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0';  
    //fflush(stdin);

    printf("Enter second string: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0';
    //fflush(stdin);

    char* mergedString = mergeAlternately(s1, s2);
    
    if (mergedString != NULL) {
        printf("Merged string: %s\n", mergedString);
        free(mergedString);  
    }
	}

    

    return 0;
}

