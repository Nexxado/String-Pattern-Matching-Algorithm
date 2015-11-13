CC = gcc
CFLAGS = -c
OBJECTS = slist.o main.o pattern_matching.o

DEBUG_FLAGS = -g
DEBUG_OBJECTS = slist.c slist.h main.c pattern_matching.c pattern_matching.h

app: $(OBJECTS)
	$(CC) $(OBJECTS) -Wall -o app

debug: $(DEBUG_OBJECTS)
	$(CC) $(DEBUG_FLAGS) $(DEBUG_OBJECTS) -Wall -o app
	
clean:
	rm $(OBJECTS)

slist.o: slist.c slist.h
	$(CC) $(CFLAGS) slist.c slist.h

main.o: main.c
	$(CC) $(CFLAGS) main.c

pattern_matching.o: pattern_matching.c pattern_matching.h
	$(CC) $(CFLAGS) pattern_matching.c pattern_matching.h
