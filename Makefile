CC = gcc

OBJS = cpmRun

SRCS = 	./fsysdriver.c \
				./cpmfsys.c \
				./diskSimulator.c

REBUILDABLES = $(OBJS)

all: $(SRCS)
	@clear
	$(CC) -o $(OBJS) $(SRCS)
	@echo build complete

# cpmRun: diskSimulator.o  cpmfsys.o fsysdriver.o 
# 	gcc -o cpmRun diskSimulator.o cpmfsys.o fsysdriver.o 

# diskSimulator.o: diskSimulator.c diskSimulator.h
# 	gcc -c diskSimulator.c

# cpmfsys.o: cpmfsys.h cpmfsys.c 
# 	gcc -c cpmfsys.c  

# fsysdriver.o: fsysdriver.c
# 	gcc -c fsysdriver.c 

# all: 
# 	cpmRun

clean: 
	rm *.o 
	@echo clean complete

