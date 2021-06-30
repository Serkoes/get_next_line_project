NAME = programm
FOLDER = get_next_line/
FILES = $(FOLDER)get_next_line.h $(FOLDER)get_next_line.c $(FOLDER)get_next_line_utils.c
TEST = main.c
LIB = libft/libft.a
FLAGS = -g -Wall -Wextra -Werror
CC = gcc


run : $(NAME)
	./programm

debug : $(NAME)
	gdb ./programm

$(NAME) : $(FILES) $(TEST)
	$(CC)  $(FLAGS) $(FILES)  $(TEST) $(LIB) -o $(NAME)
	