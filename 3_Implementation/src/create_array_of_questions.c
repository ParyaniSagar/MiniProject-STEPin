#include<stdlib.h>

#include"../inc/program.h"

/**
 * @brief Create a array of questions object
 * 
 * @param no_of_questions 
 * @return qna_t* 
 */
qna_t *create_array_of_questions(const int no_of_questions)
{
    return calloc(no_of_questions,sizeof(qna_t));
}
