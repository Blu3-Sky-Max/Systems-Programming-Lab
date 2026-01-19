#=============================================This is the real Makefile for c++ compling =======================================================================================================================================================================================================================================================

CXX :=g++

# Compiler for warning,debugging and c standard 
 CXXFLAGS=-Wall -g -std=c++17

# The name of the final excutable can be any name tho in front of the T'

TARGET:= House-Renovation

#auto find all the .c in the current dir

 SRCS:= $(wildcard *.cpp)
#create library for math caculations
LIBS:= -lm
# create a list of obj file .c to .o from the src 

 OBJ:=$(patsubst %.cpp,%.o, $(SRCS))

.PHONY:all
 all: $(TARGET)

#rule to link all the object files into the final executable
#This rules run only if the Target doesn't exit or if any 
#of the object files (OBJ) are newer than the target 

$(TARGET): $(OBJ)
	@echo "==> Linking..." 
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(LIBS)
	@echo "==> Build finished: $(TARGET)" 

#to create a file with %.o you need a file with %.cpp
%.o:%.cpp
	@echo "==> compiling $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

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
