#
# == Paths ==
#
BIN_DIR := bin
LIB_DIR := lib
SRC_DIR := src
SRC     := $(wildcard $(SRC_DIR)/*.c)
CFLAGS  := -O2 -xHost -qopenmp
CC      := mpicc
PROGS = $(patsubst %.c,%,$(SRC))

#
# == Targets ==
#

all: $(PROGS)

clean:
	$(RM) $(BUILD_DIR)/*.o $(BIN_DIR)/*

%: %.c
	$(CC) $(CFLAGS) -o bin/$(basename $(notdir $@)) $<

#experiments: $(SRC)
	#mpicc -o $(BIN_DIR)/$@ -O2 -xHost -qopenmp $^
