

OBJ     = main.o
LDADD   = -lcheck

test: $(OBJ)
	${CC} ${OBJ} -o test ${LDADD}


.c.o:
	${CC} ${CFLAGS} -c $<

clean:
	rm -f test

