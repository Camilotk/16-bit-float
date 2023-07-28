CC := gcc
CFLAGS := -g -Wall
LIBS := -lcriterion

SRCDIR := src
TESTDIR := tests
OBJDIR := obj
BINDIR := bin
TESTBINDIR := $(BINDIR)/tests

SRCFILES := $(wildcard $(SRCDIR)/*.c)
TESTFILES := $(wildcard $(TESTDIR)/*.c)
OBJFILES := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCFILES))
TESTEXECS := $(patsubst $(TESTDIR)/%.c, $(TESTBINDIR)/%, $(TESTFILES))

MAINEXEC := $(BINDIR)/main

.PHONY: all clean test run

all: $(MAINEXEC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(MAINEXEC): $(OBJFILES)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)

$(TESTBINDIR)/%: $(TESTDIR)/%.c $(OBJFILES)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

test: $(TESTEXECS)
	@for testexec in $(TESTEXECS); do \
		echo "Running test: $$testexec"; \
		$$testexec; \
	done

run: 
	@mkdir bin
	gcc -o bin/a.out main.c src/problem.c && ./bin/a.out


