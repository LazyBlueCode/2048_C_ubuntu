CC=gcc
OBJS=game.o main.o board.o menu.o functions.o
EXEC=2048
DEBUG= -g
CFLAGS=-std=c99 -Wall -Werror $(DEBUG)
	
$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@
 
game.o: game.h game.c menu.h board.h
main.o: main.c game.h
board.o: board.h board.c 
menu.o: menu.h menu.c functions.h board.h
functions.o: functions.c functions.h
 clean: 
	rm -f $(OBJS) $(EXEC)
