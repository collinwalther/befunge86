CC          = g++
SRCDIR      = src
TSTDIR      = tst
BUILDDIR    = build
TARGET      = bin/befunge
MAIN        = $(SRCDIR)/main.$(SRCEXT)

SRCEXT      = cpp
SOURCES     = $(subst $(MAIN), , $(shell find $(SRCDIR) -type f -name *.$(SRCEXT)))
OBJECTS     = $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.$(SRCEXT)=.o))
TESTS       = $(shell find $(TSTDIR) -type f -name *.$(SRCEXT))
TSTOBJS     = $(patsubst $(TSTDIR)/%, $(BUILDDIR)/%, $(TESTS:.$(SRCEXT)=.out))
CFLAGS      = -Wall
INC         = -I include/

.PHONY:             clean test all

all:                test $(TARGET)

$(TARGET):          $(OBJECTS)
	$(CC) $(CFLAGS) $(INC) $^ $(MAIN) -o $@

$(BUILDDIR)/%.o:    $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $^

test:               $(OBJECTS) $(TSTOBJS)
	
$(BUILDDIR)/%.out:      $(TSTDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) $(INC) -o $@ $^ $(OBJECTS)
	./$@

clean:
	$(RM) -r $(BUILDDIR) $(TARGET)

