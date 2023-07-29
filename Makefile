CC := gcc
CFLAGS := -g -Wall
LIBS := -lm

SRCDIR := src
TESTDIR := tests
OBJDIR := obj
BINDIR := bin
TESTBINDIR := $(BINDIR)/tests

SRCFILES := $(wildcard $(SRCDIR)/*.c)
TESTFILES := $(wildcard $(TESTDIR)/*.c)
OBJFILES := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCFILES))
TESTEXECS := $(patsubst $(TESTDIR)/%.c, $(TESTBINDIR)/%, $(TESTFILES))

MAINFILE := main.c
MAINEXEC := $(BINDIR)/a.out

.PHONY: all clean test run

all: $(MAINEXEC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(MAINEXEC): $(OBJFILES)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)

$(TESTBINDIR)/%: $(TESTDIR)/%.c $(OBJFILES)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS) -lcriterion

test: $(TESTEXECS)
	@for testexec in $(TESTEXECS); do \
		echo "Running test: $$testexec"; \
		$$testexec; \
	done

run:
	@mkdir -p $(BINDIR)
	$(CC) -o $(MAINEXEC) $(MAINFILE) $(SRCFILES) $(LIBS)
	./$(MAINEXEC)
