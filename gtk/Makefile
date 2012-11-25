PACKAGE = helloworld
OBJECTS = helloworld.o
CFLAGS  = `pkg-config --cflags gtk+-3.0`
LDADD   = `pkg-config --libs gtk+-3.0`

helloworld: $(OBJECTS)
	${CC} -o ${PACKAGE} ${OBJECTS} ${LDADD}

.c.o:
	${CC} ${CFLAGS} -c $<


clean:
	rm -f helloworld *.o
