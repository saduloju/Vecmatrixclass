#
#         Make file for Project 1
#         Project: Steady State Pressurized Pipe flow Analysis
#         Author: Sunday Aduloju
#         Last modified : 3/25/2018
C++  = g++
C++FLAGS =  -c -w
#
OBJECTS = main.o get_size.o create.o free.o set_value.o get_value.o          \
          vector_const.o vector_dest.o operator.o

#
projectfinal : ${OBJECTS}
	 ${C++} $(OBJECTS) -o projectfinal.go
#
#          source files and dependencies
#
main.o             : main.cc vector.h
get_size.o         : get_size.cc vector.h
create.o           : create.cc vector.h
free.o             : free.cc vector.h
set_value.o        : set_value.cc vector.h
get_value.o        : get_value.cc vector.h
vector_const.o     : vector_const.cc vector.h
vector_dest.o      : vector_dest.cc vector.h
operator.o         : operator.cc vector.h
#trace.o            : trace.cc prototypes.h header.h arrays.h scanlib.h

#
#
.SUFFIXES : .o .cc
.cc.o:
	/bin/rm -f $@
	$(C++) $(C++FLAGS) $<
