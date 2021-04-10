#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

#include "./inc/program.h"

const int no_of_questions = 5; // Number of questions per topic.

qna_t *question_array = NULL;  // pointer to array of questions in each questionnaire.


int main()
{
    
    error_t status; //status of reading the file of questionnaire
    question_array = create_array_of_questions(no_of_questions);

    char round_1_questionanaire[200],round_2_questionnaire[200];
    char name_of_participant[50];
    char choice,genre_1,genre_2;
    printf("starting program\n");
mainhome:    introduction();
    choice=toupper(getch());
    switch(choice)
    {
        case 'S':
            system("cls");
            break;
        case 'H':
            system("cls");
            help();
            choice=toupper(getch());
            if (choice == 'Y')
            {
                goto mainhome;
            }
            else
            {
                system("cls");
                delay(2);
                return 0;
            }
            
        case 'Q':
            system("cls");
            delay(2);
            return 0;
        default:
            goto mainhome;
    }
    printf("Please enter your Name: ");
    gets(name_of_participant);
    select_again:    system("cls");
    printf("please Enter your two choices\n");
    printf("1. Fundamentals of C      |     (C)     \n");
    printf("2. LTTS history           |     (L)     \n");
    printf("3. General Knowledge      |     (G)     \n");
    printf("First Genre :");
    genre_1 = toupper(getch());
    printf("%c\n",genre_1);
    printf("Second Genre :");
    genre_2 = toupper(getch());
    printf("%c\n",genre_2);

    if (genre_1 == genre_2)
    {
        printf("HAHA, we know you're too smart\n");
        printf("Please select two DIFFERENT options.\n");
        printf("Press enter to select genre : %c\n",getch());
        goto select_again;
    }
    else
    {
        switch (genre_1)
        {
            case'C':
                strcpy(round_1_questionanaire,"questionnaire/Fundamentals_C.csv");
                break;
            case 'L':
                strcpy(round_1_questionanaire,"questionnaire/LTTS_History.csv");
                break;
            case 'G':
                strcpy(round_1_questionanaire,"questionnaire/General_Knowledge.csv") ;
                break; 
            default: 
                printf("please enter the value of genre 1 correctly :\n");
                printf("%c",getch());
                goto select_again;
        }
        switch (genre_2)
        {
            case'C':
                strcpy(round_2_questionnaire,"questionnaire/Fundamentals_C.csv");
                break;
            case 'L':
                strcpy(round_2_questionnaire,"questionnaire/LTTS_History.csv");
                break;
            case 'G':
                strcpy(round_2_questionnaire,"questionnaire/General_Knowledge.csv") ;
                break; 
            default: 
                printf("please enter the value of genre 2 correctly :\n");
                printf("%c",getch());
                delay(2);
                goto select_again;
        }
    }
    
    //round 1 starts from here
    status = file_read(question_array,round_1_questionanaire);
    if(status == NO_FILE)
    {
        printf("Cant open file\n");
        delay(2);
        return 0;
    }
    else if(status == NULL_PTR)
    {
        printf("Memory allocation error\n");
        delay(2);
        return 0;
    }
    else
    {
        status = play_the_game(question_array,name_of_participant,no_of_questions);
        if(status == PLAYER_OUT)
        {
            delay(2);
            return 0;
        }
    }
    free(question_array);
    question_array = create_array_of_questions(no_of_questions);
    system("cls");
    printf("-----------------------------------------------------\n");
    printf("Congratulations, you have made it to the second round\n");
    printf("-----------------------------------------------------\n\n");
    printf("Press Enter to continue : %c",getch());

    //Round 2 starts from here
    status = file_read(question_array,round_2_questionnaire);
    if(status == NO_FILE)
    {
        printf("Cant open file\n");
        return 0;
    }
    else if(status == NULL_PTR)
    {
        printf("Memory allocation error\n");
        return 0;
    }
    else
    {
        status = play_the_game(question_array,name_of_participant,no_of_questions);
        if(status == PLAYER_OUT)
        {
            printf("\n\n Sorry to see you go when you were so close, kya kijiyega ab aap? xD");
            delay(2);
            return 0;
        }
        system("cls");
        printf("---------------------------------------------------------------------------------------------\n");
        printf("| CONGRATULATIONS, YOU HAVE PASSED ALL ROUNDS AND ARE WELCONE TO STEPin the GENESIS PORGRAM |\n");
        printf("---------------------------------------------------------------------------------------------\n\n\n");
        printf("Press Enter to exit : %c",getch());
        
    }
    free(question_array);
    delay(2);
    return 0;

}