CC			=	g++-6
CFLAGS		=	-c -Wall -Ofast -I ./CPLOT/
LDFLAGS		=	
SOURCES		=	./examples/example.cpp
OBJECTS		=	$(SOURCES:.cpp=.o)
EXECUTABLE	=	./exec/example

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.out ./examples/*.o ./CPLOT/*.o ./exec/*

tar:
	tar -zcvf cplot.tar.gz ./makefile.mk ./exec ./CPLOT ./examples ./README.md ./LICENSE.md