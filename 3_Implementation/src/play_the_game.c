#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#include"../inc/program.h"

/**
 * @brief start playing the game program that keeps track of life and corrct answers
 * 
 * @param question_array 
 * @param name_of_participant 
 * @param no_of_questions 
 * @return error_t 
 */
error_t play_the_game(qna_t *question_array, char *name_of_participant, const int no_of_questions)
{
    char choice;
    int life = 2;   //beginning life per round
    char ans[2];
    if(question_array == NULL)
    {
        return NULL_PTR;
    } 
    for (int index = 0;index < no_of_questions; index++)    //starting a single round
    { 
        strcpy(ans,(question_array+index)->answer);
        system("cls || clear");
        printf("Name : %s\n",name_of_participant);
        printf("Lives : %d",life);
        

        printf("\n\n");

        printf("%s\n",(question_array+index)->question);    
        
        printf("%s    ",(question_array+index)->option_1);
        printf("    %s\n",(question_array+index)->option_2);
        printf("%s    ",(question_array+index)->option_3);
        printf("    %s\n",(question_array+index)->option_4);

        printf("\n Please enter option : ");
        scanf("%c",&choice);
        getchar();
        choice = toupper(choice);

        if(choice == ans[0])    //if the given and correct answer match.
        {
            printf("\n Congratulations!, The correct answer is option %s\n",(question_array+index)->answer);
            printf("Press Enter to continue ");
            getchar();    
        }
        else    // if they dont match, decrease the life!
        {
            printf("\nOh Sorry!, The correct answer is option %s\n",(question_array+index)->answer);
            life--;  
            printf("Press Enter to continue ");
            getchar();
            
        }

        if(life == 0)   //check for life, to still be in the porgram.
        {
            system("cls || clear");
            printf("\nSorry no more lives left, please try again next time\n");
            delay(2);
            return PLAYER_OUT;
        }
        
    }
    return SUCCESS;
    }