#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "CPLOT/cplot.hpp"

int main() {
	srand(time(NULL));
	std::string filename	=	"trig.tex";
	/*******************************/	
	//	Setting the canvas
	/*******************************/
	cplot A(filename);		//	Filename something.tex
	A.xlabel("x");			//	Label of the X axis
	A.ylabel("y");			//	Label of the Y axis
	A.title("Curves");		//	Title of the plot
	A.axes(-1,1,-1,1);		//	Axes

	/********************************/
	//	The first plot;
	/********************************/
	//	The data to be plotted
	std::vector<double> xdata, ydata;
	double pi	=	3.141592653589793238;
	int N		=	10;
	for (int j=0; j<N; ++j) {
		xdata.push_back(-1+(2*double(j)+1)/N);
		ydata.push_back(sin(0.5*pi*xdata[j]));
	}

	//	Setting the first plot
	plot myplot;				//	Curve to be plotted

	myplot.xdata(xdata);		//	Data points along the X-axis
	myplot.ydata(ydata);		//	Data points along the Y-axis

	//	Adding the plot to the canvas
	A.plots.push_back(myplot);	//	Add this curve to the canvas

	/********************************/
	//	The second plot;
	/********************************/
	//	The data to be plotted
	std::vector<double> x, y;
	N	=	20;
	for (int j=0; j<N; ++j) {
		x.push_back(cos(pi*(j+0.5)/N));
		y.push_back(exp(-x[j]*x[j]));
	}

	//	Setting the second plot
	myplot.xdata(x);			//	Data points along the X-axis
	myplot.ydata(y);			//	Data points along the Y-axis
	myplot.marks("square*", "blue");	//	Marks the data point in addition to drawing the curve;
	myplot.curve("thick", "red", "dashed", true);	//	Plots the curve; The curve is thick in red, and is dashed and is smooth

	/*******************************/
	//	Getting back to the canvas
	/*******************************/
	//	Adding the plots to the canvas
	A.plots.push_back(myplot);

	//	Adding legend to the canvas
	A.legend("$\\sin(x)$, $\\exp(-x^2)$", 1, 0, "south east");

	//	Making the plot
	A.makeplot();
}