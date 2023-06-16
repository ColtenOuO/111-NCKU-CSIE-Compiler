CC := gcc
CFLAGS := -Wall -O0 -ggdb
YFLAG := -d -v
LEX_SRC := compiler.l
YAC_SRC := compiler.y
HEADER := compiler_common.h
COMPILER := myscanner
EXEC := Main
v := 0

all: ${COMPILER}

${COMPILER}: lex.yy.c y.tab.c
	${CC} ${CFLAGS} -o $@ $^

lex.yy.c: ${LEX_SRC} ${HEADER}
	lex $<

y.tab.c: ${YAC_SRC} ${HEADER}
	yacc ${YFLAG} $<

clean:
	rm -f ${COMPILER} y.tab.* y.output lex.* *.S

judge: all
	@judge -v ${VERBOSE}