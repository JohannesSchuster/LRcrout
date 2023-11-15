IDIR = linalg
CC=gcc
CFLAGS=-I $(IDIR)

ODIR=obj
LIBS=-lm

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SOURCES = $(call rwildcard,.,*.c)
OBJ = $(patsubst %.c,$(ODIR)/%.out,$(SOURCES))

$(ODIR)/%.out: %.c	
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

proj.out: $(OBJ)
	@$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	@rm -rf $(ODIR)/*