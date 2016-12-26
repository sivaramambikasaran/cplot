# CPLOT
===

Enables easy plotting from C++. This creates plots using tikz/pgfplots. Currently, it can only handle 2D plots of the form `y` versus `x` (more features to be added latter). The library provides methods to write the plot to a .tex file, which can be compiled with a latex compiler such as pdflatex, for instance, to generate the plot.

This is a pure header only library and hence using this is pretty straight forward. There is no binary library to link to, no configured header file and all that annoying s$!t.

To use cplot, download the repository and copy the folder `CPLOT` to the desired directory you want.

	g++-6 -I /path/to/cplot myprogram.cpp -o myprogram

On Linux or Mac OS X, another option is to cymlink or copy the folder `CPLOT` into `/usr/local/include/`. This way you can compile the program as:

	g++-6 myprogram.cpp -o myprogram

An example file can be found inside the folder named `examples`.

Broadly speaking there are two classes; one for the canvas on which the plots are drawn and another one for the individual curves themselves.

The class `cplot` is the canvas and the class `plot` is the individual plot.

More documentation to follow soon. In the meantime, you can browse through the header files in the `CPLOT` directory to decipher the features.

The plot generated from the individual file is shown below:

![Trignometric plots](https://github.com/sivaramambikasaran/cplot/blob/master/trig.png)
