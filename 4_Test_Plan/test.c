#include<stdlib.h>
#include <string.h>

#include "../unity/unity.h"
#include "../unity/unity_internals.h"

#include "../inc/program.h"

/* Required by the unity test framework */
void setUp()
{
}
/* Required by the unity test framework */
void tearDown()
{
}



/**
 * @brief to test whether the file is reading correctly or not
 * and other error messages for wrong inputs.
 */
qna_t *question_array = NULL;
error_t STATUS;

void test_read_file_null_ptr(void)
{
    question_array = NULL;
    STATUS = file_read(question_array,"questionnaire/Fundamentals_C.csv");
    TEST_ASSERT_EQUAL(NULL_PTR,STATUS);

}
void test_read_file_success(void)
{
    question_array = create_array_of_questions(5);
    STATUS = file_read(question_array,"questionnaire/Fundamentals_C.csv");
    TEST_ASSERT_EQUAL(SUCCESS,STATUS);
    free(question_array);
}

void test_read_file_no_file(void)
{
    question_array = create_array_of_questions(5);
    STATUS = file_read(question_array,"wrongfilename.csv");
    TEST_ASSERT_EQUAL(NO_FILE,STATUS);
    free(question_array);
}

 /**
 * @brief to test whether the quiz scoring works perfectly or not.
 * also whether all parameters are set.
 */
 void test_play_the_game(void)
{
    int no_of_questions = 5;
    question_array = NULL;
    error_t STATUS = play_the_game(question_array,"Sagar Paryani",no_of_questions );
    TEST_ASSERT_EQUAL(NULL_PTR,STATUS);
    

}


int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();
    /* Run Test functions */
    RUN_TEST(test_read_file_no_file);
    RUN_TEST(test_read_file_null_ptr);
    RUN_TEST(test_read_file_success);
    RUN_TEST(test_play_the_game);
    /* Close the Unity Test Framework */
    return UNITY_END();
}