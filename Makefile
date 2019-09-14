CC := gcc
WARNINGS := -Wall
CFLAGS := -g -std=c99 $(WARNINGS)
LFLAGS := -lpthread
SOURCES := $(wildcard *.c)
EXECUTABLES := $(SOURCES:.c=.exe)


all: $(EXECUTABLES)


$(EXECUTABLES): %.exe: %.c
	@echo '$$< = ' $<
	@echo 'EXES = ' $(EXECUTABLES)
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)


clean:
	-rm -f *.o
	-rm -f *.exe
	
	
