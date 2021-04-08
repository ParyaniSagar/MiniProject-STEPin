#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"../inc/program.h"

error_t file_read(qna_t *question_array,char *filename)
{
     
    FILE* fp = fopen(filename, "r");
    if (!fp)
    {
        return NO_FILE;
    } 
    if(question_array == NULL)
    {
        return NULL_PTR;
    } 
    else 
    {
        printf("entered in file\n");
        char buffer[200];
        int index=0;
        char *token;
        while(index <= 4)
        {
            fgets(buffer,200, fp);
            strcpy((question_array+index)->question,buffer);

            fgets(buffer,200, fp);

            token = strtok(buffer, ",");
            strcpy((question_array+index)->option_1,token);

            token = strtok(NULL, ",");
            strcpy((question_array+index)->option_2, token);

            token = strtok(NULL, ",");
            strcpy((question_array+index)->option_3,token);

            token = strtok(NULL, ",");
            strcpy((question_array+index)->option_4, token);

            fgets(buffer,200, fp);
            strcpy((question_array+index)->answer, buffer);
            
            index++;
        }    
    }
    fclose(fp);
    printf("Closed file\n");
    return SUCCESS;
}