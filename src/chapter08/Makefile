BIN = ../../bin
ODIR = obj
SUBDIRS = 
CC = cc
CFLAGS = -std=c99 -Wall -g -I.
LINT = splint
LINTFLAGS = -compdef +quiet +skip-sys-headers +charintliteral +charint -shadow -preproc -mustfreeonly -temptrans -nullret -nullpass -nullstate +posixlib
DEPS =
_OBJ = bfree.o calloc.o calloc2.o mincat.o mincat2.o minstdio.o minstdiotest.o stdiobits minstdio0.o
_BIN = bfree calloc calloc2 mincat mincat2 minstdiotest stdiobits

OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

.PHONY: all clean

all: $(_BIN)
	@for i in $(SUBDIRS); do \
		cd $$i; \
		make all; \
		cd ..; \
	done

clean:
	@for i in $(SUBDIRS); do \
		cd $$i; \
		make clean; \
		cd ..; \
	done
	rm -rv $(ODIR) $(_BIN)

bfree: $(ODIR)/bfree.o
	$(CC) $(CFLAGS) $^ -o $@
	cp -v $@ $(BIN)/$@

calloc: $(ODIR)/calloc.o
	$(CC) $(CFLAGS) $^ -o $@
	cp -v $@ $(BIN)/$@

calloc2: $(ODIR)/calloc2.o
	$(CC) $(CFLAGS) $^ -o $@
	cp -v $@ $(BIN)/$@

mincat: $(ODIR)/mincat.o
	$(CC) $(CFLAGS) $^ -o $@
	cp -v $@ $(BIN)/$@

mincat2: $(ODIR)/mincat2.o
	$(CC) $(CFLAGS) $^ -o $@
	cp -v $@ $(BIN)/$@

minstdiotest: $(ODIR)/minstdiotest.o minstdio.o
	$(CC) $(CFLAGS) $^ -o $@
	cp -v $@ $(BIN)/$@

stdiobits: $(ODIR)/stdiobits.o minstdio0.o
	$(CC) $(CFLAGS) $^ -o $@
	cp -v $@ $(BIN)/$@

$(ODIR)/%.o: %.c $(DEPS)
	mkdir -pv $(ODIR)
	$(CC) $(CFLAGS) -c -o $@ $<
	$(LINT) $(LINTFLAGS) $<