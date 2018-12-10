make -C libft/ fclean && make -C libft/
gcc -g -I libft/includes get_next_line.c main.c get_next_line.h libft/libft.a
./a.out test.txt
