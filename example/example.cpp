#include <iostream>
#include <vector>
#include <cstdlib>
#include "./../header/cplot.hpp"

int main() {
	srand(time(NULL));
	std::string filename	=	"test.tex";
	double RMAX	=	RAND_MAX;

	//	The data to be plotted
	std::vector<double> xdata, ydata;
	int N	=	10;
	for (int j=0; j<N; ++j) {
		xdata.push_back(rand()/RMAX);
		ydata.push_back(rand()/RMAX);
	}

	//	Setting the canvas
	cplot A(filename);
	A.xlabel("x");
	A.ylabel("y");
	A.title("Test");
	A.axes(0,1,0,1);

	//	Setting the plot
	plot myplot;
	myplot.xdata(xdata);
	myplot.ydata(ydata);
	myplot.marks("square");
	myplot.color("red");
	myplot.smooth("smooth");

	//	Adding the plot to the canvas
	A.plots.push_back(myplot);

	//	Making the plot
	A.makeplot();
}