

OBJ     = main.o parsing.o
LDADD   =

test: $(OBJ)
	${CC} ${OBJ} -o test ${LDADD}


.c.o:
	${CC} ${CFLAGS} -c $<

clean:
	rm -f test *.o

