#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define LineBuffSize 6000*sizeof(char)
#define maxJaSize 20000

char** getCharProcess(int maxRow);
void jaPrint(char *lineVec[],int maxRow);

int main(int argc, char *argv[]) 
{
    int maxRow = 7;
    if(argc == 2) {
        maxRow = atoi(argv[1]);
        if(maxRow <= 2 || maxRow > 10000) maxRow = 7;
    }
   
    jaPrint(getCharProcess(maxRow),maxRow);

    return 0;
}

char** getCharProcess(int maxRow) 
{
    int count = 0;
    int row = 0;
    int addSpaceSum = 0;
    int beginFill = 0;
    char ch[] = {0, 0, 0, '\0'};

    char *str = malloc(600*sizeof(char));
    memset(str,0,600*sizeof(char));
    char **lineVec = malloc(maxRow*sizeof(char *));
    for (int i = 0; i < maxRow; i++) {
        lineVec[i] = malloc(LineBuffSize);
        memset(lineVec[i],0,LineBuffSize);
    }

    while(count < maxJaSize) {
        for (int i = 0; i < 3; i++) {
            if (beginFill == 0) {
                ch[i] = getchar();
                while(ch[i] == '\n') ch[i] = getchar();
            } 
            if (ch[i] == EOF) {
                if (addSpaceSum == 0) {
                    free(str);
                    return lineVec;
                }
                else beginFill = 1;
            }
            if (beginFill == 1 && !(addSpaceSum)) {
                free(str);
                return lineVec;}
        }  
    
        if (beginFill) {
            memcpy(str,"  ",4);
        }
        else {
            memcpy(str,ch,4);
        } 
        strncat(str," ",3);
        strncat(str,lineVec[row],strlen(lineVec[row]));
        memcpy(lineVec[row],str,strlen(str));
        
        row++;
        if (row > maxRow-1) row = 0;
        
        count++;
        addSpaceSum = count % maxRow;
    }
    free(str);
    return lineVec;
}

void jaPrint(char *lineVec[],int maxRow) 
{
    for (int j = 0; j < maxRow; j++) {
        printf("%s",lineVec[j]);
        printf("\n");
    }

    for (int i = 0; i < maxRow; i++) {
        free(lineVec[i]);
    }
    free(lineVec);
}
