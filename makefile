IDIR = linalg
CC=gcc
CFLAGS=-I $(IDIR)

ODIR=obj
LIBS=-lm

SOURCES = $(wildcard *.c) $(wildcard **/*.c)
OBJ = $(patsubst %.c,$(ODIR)/%.out,$(SOURCES))

$(ODIR)/%.out: %.c	
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $< $(CFLAGS)

proj.out: $(OBJ)
	@$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	@rm -rf $(ODIR)/*