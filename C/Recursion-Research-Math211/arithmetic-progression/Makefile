#This is the real Makefile for c compling ===============================================================================================================================

CC :=gcc

# Compiler for warning,debugging and c standard 
 CFLAGS=-Wall -g -std=c11

# The name of the final excutable can be any name tho in front of the T'

TARGET:= Recursive  

#auto find all the .c in the current dir

 SRCS:= $(wildcard *.c)
#create library for math caculations
LIBS:= -lm
# create a list of obj file .c to .o from the src 

 OBJ:=$(patsubst %.c,%.o, $(SRCS))

.PHONY:all
 all: $(TARGET)

#rule to link all the object files into the final executable
#This rules run only if the Target doesn't exit or if any 
#of the object files (OBJ) are newer than the target 

$(TARGET): $(OBJ)
	@echo "==> Linking..." 
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBS)
	@echo "==> Build finished: $(TARGET)" 

#to create a file with %.o you need a file with %.c
%.o:%.c
	@echo "==> compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

# TO CLEAN UP 
.PHONY: clean
clean:
	@echo "==> cleaning up...." 
	rm -f $(TARGET) $(OBJ)
#TO install 
.PHONY: install
install:
	@echo "==> installing...."
	cp $(TARGET) /usr/local/bin/
 
# to uninstall/remove 
.PHONY: uninstall
uninstall: 
	 @echo "==> removing ...."
	rm -f /usr/local/bin/$(TARGET)
