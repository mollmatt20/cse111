# $Id: Makefile,v 1.3 2022-03-22 11:53:15-07 - - $


GWARN   = -Wall -Wextra -Wpedantic -Wshadow -Wold-style-cast
GOPTS   = -std=gnu++2a -fdiagnostics-color=never
GPP     = g++ -g -O0 ${GOPTS} ${GWARN}
GRIND   = valgrind --leak-check=full --show-reachable=yes
NODEPS  = ${filter ci clean spotless tar, ${MAKECMDGOALS}}
MKTAR   = gtar --create --verbose --gzip

H_FILES =
C_FILES = countwords.cpp
OBJECTS = ${C_FILES:.cpp=.o}
EXECBIN = countwords
SOURCES = ${H_FILES} ${C_FILES} Makefile data


all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${GPP} -o $@ $^

%.o : %.cpp
	- cpplint.py.perl $<
	- checksource $<
	${GPP} -c $<

ci : ${SOURCES}
	- checksource $^
	cid -is $^

clean :
	- rm ${OBJECTS} test.log test.out test.err

spotless : clean
	- rm ${EXECBIN} Makefile.deps

tar : ${SOURCES}
	${MAKE} --no-print-directory spotless
	( DIRNAME=$$(basename $$(pwd)) \
	; cd .. \
	; ${MKTAR} --exclude=RCS --file=countwords.tar.gz $$DIRNAME \
	)

test : ${EXECBIN}
	${GRIND} --log-file=test.log \
	         ${EXECBIN} ${SOURCES} 1>test.out 2>test.err

Makefile.deps :
	${GPP} -MM ${C_FILES} >Makefile.deps

ifeq (${NODEPS}, )
include Makefile.deps
endif

