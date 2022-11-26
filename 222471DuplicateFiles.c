#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()

{

    FILE * fpointer = fopen("files.in", "r");

    char strNumOfTestCases[10];
    fgets(strNumOfTestCases, 10, fpointer);
    int numOfTestCases = atoi(strNumOfTestCases);

    int i;

    for (i=0; i<numOfTestCases; i++)
    {

        char strNumOfFilesInCase[10];
        fgets(strNumOfFilesInCase, 10, fpointer);
        int numOfFilesInCase = atoi(strNumOfFilesInCase);
        int correctfileids[numOfFilesInCase];

        int j=0;
        while(j<numOfFilesInCase){
            char firstcase[20];
            char firstcasefilename[10];

            if(j == 0){
                fgets(firstcase, 20, fpointer);
                int length=strlen(firstcase)-1;

                char fileid = firstcase[length-1];
                correctfileids[0]=fileid-'0';

                int k =0;
                while(firstcase[k] != ' '){
                    firstcasefilename[k] = firstcase[k];
                    k++;
                }
            }
            else{
                char othercases[20];
                char othercasesfilename[20];
                fgets(othercases, 20, fpointer);
                int length;
                if(i==(numOfTestCases-1) && j==(numOfFilesInCase-1)){//in a list like this, there is always an extra space '/0' which strlen is susceptible to
        //that '/0' appears if there is another line after the line it is reading.
        //hence it won't affect the last line of the input but affect all others
        //if your program has another line after the last integer, please kindly remove it even if it is empty
        //alternatively, you can change the if statemenr to if(i<T){}
                    length = strlen(othercases);
                }
                else{
                    length = strlen(othercases)-1;
                }

                int k =0;
                while(othercases[k] != ' '){
                    othercasesfilename[k] = othercases[k];
                    k++;
                }
                int value=1;
                char result='y';
                int d;
                for(d=0; d<(strlen(firstcase)-1); d++){
                    if(othercasesfilename[d]==firstcasefilename[d]){
                        result='y';
                    }
                    else{
                        result='n';
                        break;
                    }
                }
                if(result != 'n'){
                    if((othercases[length-1]-'0') < correctfileids[0]){
                        correctfileids[0] = othercases[length-1]-'0';
        
                    }
                }
                else{
                char fileid = othercases[length-1]-'0';
                correctfileids[value]=fileid;
                value++;
                }
            }

        j++;
        }
        int arraysize = sizeof(correctfileids)/sizeof(correctfileids[0]);
        int loop;
        for(loop = 0; loop < arraysize; loop++){
            printf("%d ", correctfileids[loop]);
        }
        printf("\n");
    }
    fclose(fpointer);
    return 0;
}
