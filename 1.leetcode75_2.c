#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

char* gcdOfStrings(char* str1, char* str2) {
    //tim uoc chung lon nhat cua strlen(str1) va strlen(str2)
    int result=(strlen(str1)<strlen(str2))?strlen(str1):strlen(str2);
    while(result>0){
        if(strlen(str1)%result==0  &&  strlen(str2)%result==0){
            break;
        }
        result--;
    }
    char *temp1= (char*)malloc((strlen(str1)+strlen(str2)+1)*sizeof(char));
    char *temp2= (char*)malloc((strlen(str1)+strlen(str2)+1)*sizeof(char));
    char *gcdString= (char*)malloc((result+1)*sizeof(char));
    
    // so sanh str1+str2 == str2+str1??
    strcpy(temp1, str1);
    strcat(temp1, str2);

    strcpy(temp2, str2);
    strcat(temp2, str1);

    if(!strcmp(temp1, temp2)){
        strncpy(gcdString, temp1, result);
        gcdString[result]='\0';
        return gcdString;

    }
    else{
        gcdString="\"\"";
        return gcdString;
    }
}
int main(){
	int t;
	char s1[20], s2[20];
	scanf("%d", &t);
	fflush(stdin);
	while(t--){
		printf("s1: "); fgets(s1, sizeof(s1), stdin);
		s1[strcspn(s1, "\n")]='\0';
		printf("s2: "); fgets(s2, sizeof(s2), stdin);
		s2[strcspn(s2, "\n")]='\0';
		printf("%s ", gcdOfStrings(s1,s2));
	}




    return 0;
    
}

