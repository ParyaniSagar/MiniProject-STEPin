#include<stdio.h>
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
    

    char round_1_questionanaire[200],round_2_questionnaire[200];
    char name_of_participant[50];
    char choice,genre_1,genre_2;
    printf("starting program\n");
mainhome:    introduction();
	scanf("%c",&choice);
    getchar();
    choice = toupper(choice);
    switch(choice)      //introuction to porgram choice given to user, includes default case if user types another value than given.
    {
        case 'S':
            system("cls || clear");
            break;
        case 'H':
            system("cls || clear");
            help();
            scanf("%c",&choice);
            getchar();
			choice = toupper(choice);
            if (choice == 'Y')
            {
                delay(2);
                goto mainhome;
            }
            else
            {
                system("cls || clear");
                return 0;
            }
            
        case 'Q':
            system("cls || clear");
            return 0;
        default:
            goto mainhome;
    }
    printf("Please enter your Name: ");
    fgets(name_of_participant,50,stdin);
    select_again:    system("cls || clear");
    printf("please Enter your two choices\n");
    printf("1. Fundamentals of C      |     (C)     \n");
    printf("2. LTTS history           |     (L)     \n");
    printf("3. General Knowledge      |     (G)     \n");
    printf("First Genre :");
    scanf("%c",&genre_1);
    getchar();
	genre_1 = toupper(genre_1);
    printf("Second Genre :");
    scanf("%c",&genre_2);
    getchar();
	genre_2 = toupper(genre_2);
    //this code selects the two genres for the two rounds.
    if (genre_1 == genre_2)
    {
        printf("HAHA, we know you're too smart\n");
        printf("Please select two DIFFERENT options.\n");
        printf("Press enter to select genre : %c\n",getchar());
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
                printf("%c",getchar());
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
                printf("%c",getchar());
                delay(2);
                goto select_again;
        }
    }
    
    //round 1 starts from here
    question_array = create_array_of_questions(no_of_questions);
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
    system("cls || clear");
    printf("-----------------------------------------------------\n");
    printf("Congratulations, you have made it to the second round\n");
    printf("-----------------------------------------------------\n\n");
    printf("Press Enter to continue ");
    getchar();

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
        system("cls || clear");
        printf("---------------------------------------------------------------------------------------------\n");
        printf("| CONGRATULATIONS, YOU HAVE PASSED ALL ROUNDS AND ARE WELCONE TO STEPin the GENESIS PORGRAM |\n");
        printf("---------------------------------------------------------------------------------------------\n\n\n");
        printf("You may quit the program by hitting any key");
		getchar();    
    }
    free(question_array);
    delay(2);
    return 0;

}