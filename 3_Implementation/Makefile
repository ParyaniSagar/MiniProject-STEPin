PROJ_NAME = KKGMS.exe

SRC = src/introduction.c src/create_array_of_questions.c src/file_read.c   src/play_the_game.c src/help.c


all : 
	gcc main.c -I -c $(SRC) -o $(PROJ_NAME)

run : all
	$(PROJ_NAME)

clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*.exe)