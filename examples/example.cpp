#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "cplot.hpp"

int main() {
	srand(time(NULL));
	std::string filename	=	"trig.tex";

	//	Setting the canvas
	cplot A(filename);
	A.xlabel("x");
	A.ylabel("y");
	A.title("Curves");
	A.axes(-1,1,-1,1);

	/********************************/
	/*	The first plot;				*/
	/********************************/
	//	The data to be plotted
	std::vector<double> xdata, ydata;
	double pi	=	3.141592653589793238;
	int N		=	10;
	for (int j=0; j<N; ++j) {
		xdata.push_back(-1+(2*double(j)+1)/N);
		ydata.push_back(sin(0.5*pi*xdata[j]));
	}

	//	Setting the plot
	plot myplot;
	myplot.xdata(xdata);
	myplot.ydata(ydata);

	//	Adding the plot to the canvas
	A.plots.push_back(myplot);

	/********************************/
	/*	The second plot;			*/
	/********************************/
	//	The data to be plotted
	std::vector<double> x, y;
	N	=	20;
	for (int j=0; j<N; ++j) {
		x.push_back(cos(pi*(j+0.5)/N));
		y.push_back(exp(-x[j]*x[j]));
	}

	//	Setting the plot
	myplot.xdata(x);
	myplot.ydata(y);
	myplot.marks("square*", "blue");
	myplot.curve("thick", "red", "dashed", true);

	//	Adding the plot to the canvas
	A.plots.push_back(myplot);

	//	Adding legend to the canvas
	A.legend("$\\sin(x)$, $\\exp(-x^2)$", 1, 0, "south east");
	//	Making the plot
	A.makeplot();
}