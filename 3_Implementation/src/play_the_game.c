#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#include"../inc/program.h"

error_t play_the_game(qna_t *question_array, char *name_of_participant)
{
    char choice;
    int life = 2; 
    char ans[2];
    for (int index = 0;index < 5; index++)
    { 
        strcpy(ans,(question_array+index)->answer);
        system("cls");
        printf("Name : %s\n",name_of_participant);
        printf("Lives : %d",life);
        

        printf("\n\n");

        printf("%s\n",(question_array+index)->question);    
        
        printf("%s    ",(question_array+index)->option_1);
        printf("    %s\n",(question_array+index)->option_2);
        printf("%s    ",(question_array+index)->option_3);
        printf("    %s\n",(question_array+index)->option_4);

        printf("\n Please enter option : ");
        choice = toupper(getch());

        if(choice == ans[0])
        {
            printf("\nCongratulations!, The correct answer is option %s\n",(question_array+index)->answer);
            printf("Press Enter to continue\n");
            choice = toupper(getch());
            
        }
        else
        {
            printf("\nOh Sorry!, The correct answer is option %s\n",(question_array+index)->answer);
            life--;  
            printf("Press Enter to continue\n");
            choice = toupper(getch());
        }

        if(life == 0)
        {
            system("cls");
            printf("\nSorry no more lives left, please try again next time\n");
            return PLAYER_OUT;
        }
        
    }
    return SUCCESS;
    }