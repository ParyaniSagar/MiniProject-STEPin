
/**
 * @file program.h
 * @author Sagar Paryani
 * @brief Header file for Quiz progra,
 * @version 0.1
 * @date 2021-04-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __PROGRAM_H__
#define __PROGRAM_H__

/**
 * @brief Structure for addressing every question read from file.
 * 
 */
typedef struct qna_t
{
   char question[100];
   char option_1[100];
   char option_2[100];
   char option_3[100];
   char option_4[100];
   char answer[10];
} qna_t;


/**
 * @brief enumeration of return for functions
 * depicts the type of returns for functions depending on different cases
 */
typedef enum error_t
{  
    SUCCESS = 1,    //if all operations were completed successfully
    NO_FILE = 0,    //if the given file wasn found
    NULL_PTR = -1,   //if pointer to array was not allocated.
    PLAYER_OUT = -6
}error_t;

extern qna_t *question_array;

/**
 * @brief reads csv file and stores data into array of structure
 * 
 * @param pointer to array of structure where questions are to be stored.
 * @param name of file to be read 
 * @return error_t 
 */
error_t file_read(qna_t* question_array, char *file_name);

/**
 * @brief dynamically allocate memory for array.
 * 
 */
qna_t *create_array_of_questions(const int no_of_questions);

/**
 * @brief function to start playing the game and counting score
 * 
 * @param question_array 
 * @param score 
 * @return error_t 
 */
error_t play_the_game(qna_t *question_array, char *name_of_participant);

/**
 * @brief introduction of the quiz.
 * 
 */
void introduction(void);
/**
 * @brief help function for contestants
 * 
 */
void help(void);

#endif