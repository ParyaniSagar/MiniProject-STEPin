PROJ_NAME = KKGMS
TEST_PROJ_NAME = Test_$(PROJ_NAME)


COVERAGE_TEST_NAME = coverage_$(PROJ_NAME)

SRC = src/introduction.c src/create_array_of_questions.c src/file_read.c   src/play_the_game.c src/help.c src/delay.c

TEST_SRC = ./test/test.c unity/unity.c 

INC = -Iinc -Iunity

#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

# Makefile will not run target command if the name with file already exists. To override, use .PHONY
.PHONY : all test coverage run clean doc

all:  
	gcc main.c $(SRC) $(INC) -o $(call FixPath,$(PROJ_NAME).$(EXEC))

run : all
	./$(PROJ_NAME).$(EXEC)

test: $(SRC) $(TEST_SRC)
	gcc $(TEST_SRC) $(SRC) $(INC) -o $(TEST_PROJ_NAME).$(EXEC)
	./$(TEST_PROJ_NAME).$(EXEC)

coverage:$(SRC)
	gcc -fprofile-arcs -ftest-coverage main.c -I -c $(SRC)  -o $(COVERAGE_TEST_NAME).$(EXEC)
	./$(COVERAGE_TEST_NAME).$(EXEC)
	gcov -a main.c
	cat main.c.gcov

clean:

	$(RM) *.exe
	$(RM) *.gcn
	$(RM) *.gcov
	$(RM) *.gcda
