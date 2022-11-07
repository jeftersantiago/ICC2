UTIL=util.c student.c tournament.c
MAIN=main.c
BINARY=main

all:
	gcc -Wall -g -lm $(UTIL) $(MAIN) -o $(BINARY)

run:
	./$(BINARY)

debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) -o $(BINARY)

zip:
	zip project.zip

valgrind:
	valgrind -s --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	@rm *.o
