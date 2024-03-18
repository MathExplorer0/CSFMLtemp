all:
	@gcc source/main.c -o output/main -Wall -lm -lcsfml-graphics -lcsfml-window -lcsfml-system
	@./output/main