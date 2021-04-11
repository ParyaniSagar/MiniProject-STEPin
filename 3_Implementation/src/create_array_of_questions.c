#include<stdlib.h>

#include"../inc/program.h"

qna_t *create_array_of_questions(const int no_of_questions)
{
    return calloc(no_of_questions,sizeof(qna_t));
}
