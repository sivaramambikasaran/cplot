# CPLOT
===

Enables easy plotting from C++. This creates plots using tikz/pgfplots. The library provides methods to write the plot to a .tex file, which can be compiled with a latex compiler such as pdflatex, for instance, to generate the plot.

This is a pure header only library and hence using this is pretty straight forward. There is no binary library to link to, no configured header file and all that annoying s$!t.

To use cplot, download the repository and copy the folder header to the desired directory you want.

	g++-6 -I /path/to/cplot myprogram.cpp -o myprogram

On Linux or Mac OS X, another option is to cymlink or copy the folder `CPLOT` into `/usr/local/include/`. This way you can compile the program as:

	g++-6 myprogram.cpp -o myprogram