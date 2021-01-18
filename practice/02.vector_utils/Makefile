NAME = minirt

all : $(NAME)

$(NAME) :
	gcc *.c -o $(NAME) -I./include

clean :
	rm -rf $(NAME) result.ppm

re :
	clean all

run : $(NAME)
	./$(NAME)

ppm : $(NAME)
	./$(NAME) > result.ppm

.PHONY : all clean re
