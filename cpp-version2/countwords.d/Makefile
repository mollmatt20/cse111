# $Id: Makefile,v 1.8 2022-03-27 16:22:58-07 - - $

DEPSFILE    = Makefile.deps
NOINCL      = ci clean spotless
NEEDINCL    = ${filter ${NOINCL}, ${MAKECMDGOALS}}

GPPOPTS     = -std=gnu++2a -fdiagnostics-color=never
GPPWARN     = -Wall -Wextra -Wpedantic -Wshadow -Wold-style-cast
GPP         = g++ ${GPPOPTS} ${GPPWARN}

COMPILE     = ${GPP} -g -O0 ${GPPOPTS}
MAKEDEPS    = ${GPP} -MM ${GPPOPTS}

CPPHEADER   = word_map.h
CPPSOURCE   = word_map.cpp main.cpp
EXECBIN     = countwords
OBJECTS     = ${CPPSOURCE:.cpp=.o}
ALLSOURCE   = ${CPPHEADER} ${CPPSOURCE} Makefile
TARFILE     = countwords.tar.gz

export PATH := ${PATH}:/afs/cats.ucsc.edu/courses/cse110a-wm/bin

all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${COMPILE} -o $@ ${OBJECTS}

%.o : %.cpp
	- checksource $<
	- cpplint.py.perl $<
	${COMPILE} -c $<

ci : check
	- cid -is ${ALLSOURCE}

check : ${ALLSOURCE}
	- checksource $^

clean :
	- rm ${OBJECTS} ${DEPSFILE}

spotless : clean
	- rm ${EXECBIN}

tar : ${ALLSOURCE}
	tar cvfz ${TARFILE} $^

deps : ${CPPSOURCE} ${CPPHEADER}
	@ echo "# ${DEPSFILE} created $$(LC_TIME=C date)" >${DEPSFILE}
	${MAKEDEPS} ${CPPSOURCE} >>${DEPSFILE}

${DEPSFILE} :
	@ touch ${DEPSFILE}
	gmake --no-print-directory deps

again :
	gmake --no-print-directory spotless deps ci all

ifeq (${NEEDINCL}, )
include ${DEPSFILE}
endif

