PACKAGE = echo_server
OBJECTS = echo_server.o
CFLAGS 	= -I/usr/local/include/uv
LDADD	= -luv

hello: $(OBJECTS)
	${CC} -o ${PACKAGE} ${OBJECTS} ${LDADD}

.c.o:
	${CC} ${CFLAGS} -c $<

clean:
	rm -f hello *.o
