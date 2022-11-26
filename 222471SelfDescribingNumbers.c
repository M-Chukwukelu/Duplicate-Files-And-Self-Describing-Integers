#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*PROGRAM TO CHECK FOR SELF DESCRIBING NUMBERS*/

int main()
{
    char numberoftests[100];

    FILE * fpointer = fopen("Self.in", "r");

    fgets(numberoftests, 100, fpointer);

    int T = atoi(numberoftests);
    int i=0;
    char selfdescribing='y';//'y' stands for yes here
    while(i<T){
        char numtobecheckedstring[100];
        int numtobechecked[100];
        fgets(numtobecheckedstring, 100, fpointer);
        int numlength;
        if(i==(T-1)){//in a list like this, there is always an extra space '/0' which strlen is susceptible to
        //that '/0' appears if there is another line after the line it is reading.
        //hence it won't affect the last line of the input but affect all others
        //if your program has another line after the last integer, please kindly remove it even if it is empty
        //alternatively, you can change the if statemenr to if(i<T){}
            numlength = strlen(numtobecheckedstring);
        }
        else{
            numlength = strlen(numtobecheckedstring)-1;
        }


        for(int m=0; m<numlength; m++){
            numtobechecked[m]=numtobecheckedstring[m]-'0';
            //here, we convert it to an integer which is easier to work with and eliminates that'/0'
        }
        int j;
        int k;

        for(k=0; k<numlength; k++){
            int counter =0;
            for(j=0; j<numlength; j++){

                if(numtobechecked[j]== k){
                    counter++;
                }
            }

            if(counter == numtobechecked[k]){
                selfdescribing='y';
            }
            else{
                selfdescribing='f';
                printf("Not Self Describing\n");
                break;
            }
            counter=0;

        }
        if(selfdescribing=='y'){
            printf("Self Describing\n");
        }
    i++;
    }

    fclose(fpointer);

    return 0;
}

