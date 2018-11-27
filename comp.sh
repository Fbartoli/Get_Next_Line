make -C libft/ fclean && make -C libft/
gcc -I libft/includes get_next_line.c get_next_line.h libft/libft.a
./a.out test.txt
