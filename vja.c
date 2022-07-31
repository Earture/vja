#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>


#define LineBuffSize 300*sizeof(char)


char** getCharProcess(int maxRow);
void jaPrint(char *lineVec[],int maxRow);

int main(int argc, char *argv[]) 
{

    int maxRow = 7;
    int aflag = 0;
    int bflag = 0;
    char *cvalue = NULL;
    int index;
    int c;
    opterr = 0;

    while ((c = getopt (argc, argv, "hv:")) != -1)
        switch (c)
        {
        case 'v':
            maxRow = atoi(optarg);
            if(maxRow <= 2 || maxRow > 10000) maxRow = 7;
            break;
        case 'h':
            fprintf (stderr, "vja Version 1.0\n");
            fprintf (stderr, "Usage: vja [-v num] text\n");
            return 0;
        default:
            fprintf (stderr, "mistake!\n");
            return 0;
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
    char ch[] = {0, 0, 0};

    char *str = malloc(600*sizeof(char));
    memset(str,0,600*sizeof(char));
    char **lineVec = malloc(maxRow*sizeof(char *));
    for (int i = 0; i < maxRow; i++) {
        lineVec[i] = malloc(LineBuffSize);
        memset(lineVec[i],'\0',LineBuffSize);
    }

    while(count <= 5000) {
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
            memcpy(str,"  ",3);
        }
        else {
            memcpy(str,ch,4);
        } 
        strncat(str," ",2);
        strncat(str,lineVec[row],strlen(lineVec[row]));
        memcpy(lineVec[row],str,strlen(str));
        memset(str,'\0',600*sizeof(char));
        
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
