PROJNAME := WriteWaveFile
BINDIR := bin
BUILDDIR := build
SRCDIR := src
INCDIR := include

INCPATH := $(INCDIR)

CC := clang++
CFLAGS := -Wall -std=c++17 -I$(INCPATH)
LDFLAGS := -lm

BIN := $(BINDIR)/$(PROJNAME)

OBJ := $(BUILDDIR)/main.o
OBJ += $(BUILDDIR)/Oscillator.o


all: $(BIN)

$(BIN): $(OBJ)
	@mkdir -p $(BINDIR)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Oscillator.o: $(SRCDIR)/Oscillator.cpp $(INCDIR)/Oscillator.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<


.PHONY: clean
clean:
	rm -rf $(BIN)
	rm -rf $(OBJ)
	@if [ -e $(BINDIR) ]; then rmdir $(BINDIR); fi
	@if [ -e $(BUILDDIR) ]; then rmdir $(BUILDDIR); fi

.PHONY: run
run:
	@./$(BIN)

.PHONY: clean-build
clean-build: clean all
