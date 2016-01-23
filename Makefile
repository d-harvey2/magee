#
#  questions?:  donald.cory.harvey@gmail.com
#
# P     = program
# CC    = compiler
# CFLAGS= -g to debug, -Wall to include compiler warnings
# OBJS  = any object files to be linked in
# LIBS  = any library files to be linked in
#
#
#
P       = magee
S       = main.c treewalk.c
CC      = gcc
CFLAGS  = -g -Wall 
OBJS    =
LIBS    = 

magee:main.c treewalk.c
	rm $(P) 2>/dev/null; $(CC) $(S) $(CFLAGS) -o $(P)

clean:
	if [ -e $(P) ]; then rm $(P); fi
# 
#
#
# Note the two difference ways of removing the target.
# if you have multiple lines a new shell is pooped out
# for each line.  Backslashes are ok for line continuation.
# Makefiles require tabs to begin execution lines.
#
#
