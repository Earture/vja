#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>

char** getCharProcess(int maxRow,int LineBuffSize,int count);
void jaPrint(char *lineVec[],int maxRow);

int main(int argc, char *argv[]) 
{

    int maxRow = 7;
    int LineBuffSize = 300;
    int count = 400;
    int c;
    opterr = 0;

    while ((c = getopt (argc, argv, "hv:l:c:")) != -1) {
        switch (c)
        {
        case 'v':
            maxRow = atoi(optarg);
            if(maxRow <= 2 || maxRow > 10000) maxRow = 7;
         
            break;
        case 'l':
            LineBuffSize = atoi(optarg);
            
            break;
        case 'c':
            count = atoi(optarg);
           
            break;
        case 'h':
            fprintf (stderr, "vja Version 0.3\n");
            fprintf (stderr, "Usage: vja [-v CharactersPerColumn][-l MaxCharactersPerLine][-c MaxInputCharacters] text\n");
            return 0;
        default:
            fprintf (stderr, "mistake!\n");
            return 0;
        }
    }
    jaPrint(getCharProcess(maxRow,LineBuffSize,count),maxRow);
    return 0;
}

char** getCharProcess(int maxRow,int LineBuffSize,int settedCount) 
{
    int row = 0;
    int addSpaceSum = 0;
    int count = 0;
    int beginFill = 0;
    char ch[] = {0, 0, 0};
    int tempChar = 0;

    char *str = malloc(LineBuffSize);
    memset(str,0,LineBuffSize);
    char **lineVec = malloc(maxRow*sizeof(char *));
    for (int i = 0; i < maxRow; i++) {
        lineVec[i] = malloc(LineBuffSize);
        memset(lineVec[i],'\0',LineBuffSize);
    }

    while(settedCount) {
        for (int i = 0; i < 3; i++) {
	    tempChar = getchar();
            if (beginFill == 0 && tempChar != EOF) {
                ch[i] = tempChar;
               // while(ch[i] == '\n') ch[i] = getchar();
            } 
            if (tempChar == EOF && beginFill != 1) {
                if (addSpaceSum == 0) {
                    free(str);
                    return lineVec;
                }
                else {
                    beginFill = 1;
                    }
            }
            if (beginFill == 1 && !(addSpaceSum)) {
                free(str);
                return lineVec;
                }
        }  
    
        if (beginFill) {
            memcpy(str,"  ",strlen("  "));
           
        }
        else {
            memcpy(str,ch,strlen(ch));
        } 
        strncat(str," ",strlen(" ")+1);
        strncat(str,lineVec[row],strlen(lineVec[row]));
        memcpy(lineVec[row],str,strlen(str));
        memset(str,'\0',LineBuffSize);
        
        row++;
        if (row > maxRow-1) row = 0;
        
        count++;
        settedCount--;
        //printf("OK:%d",count);
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
