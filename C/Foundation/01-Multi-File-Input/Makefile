

CC = gcc

CFLAGS=-Wall -g -fPIC
 
TARGET =usman 
LIBS=-lm
all:$(TARGET)

$(TARGET): main.o message.o tit.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o message.o tit.o $(LIBS)

tit.o:tit.c
	$(CC) $(CFLAGS) -c tit.c

main.o:main.c
	 $(CC) $(CFLAGS) -c main.c

message.o: message.c
	  $(CC) $(CFLAGS) -c message.c

clean:
	rm -f *.o $(TARGET)

install: all 
	cp $(TARGET) /usr/local/bin/

uninstall: 
	rm -f /usr/local/bin/$(TARGET)
