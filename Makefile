CC = gcc
CFLAGS = -g -Wall -I. 
# SRCS = HelloWorld.cpp
# PROG = HelloWorld
appname = main
objs = brute_force_top_k.o max_top_k.o min_top_k.o linear_top_k.o utils.o heap.o maintest.o

# OPENCV_FLAGS = `pkg-config opencv4 --cflags`
# OPENCV_LD_FLAGS = `pkg-config opencv4 --cflags --libs`

# LIBS = $(OPENCV)


all:$(objs)
	$(CC) -o $(appname) $(objs)

%.o:%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm *.o
	rm $(appname)
