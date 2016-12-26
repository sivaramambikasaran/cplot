#ifndef _CPLOT__HPP_
#define _CPLOT__HPP_

#include <fstream>
#include <vector>
// #include "plot.hpp"

class plot {
friend class cplot;
public:
	std::vector<double> xdata_var, ydata_var;
	std::string marks_var, color_var;
	bool smooth_var;
// public:
	void xdata(std::vector<double> xdata_var);
	void ydata(std::vector<double> ydata_var);
	void marks(std::string marks_var);
	void color(std::string color_var);
	void smooth(bool smooth_var);
	plot();
	~plot();
};

void plot::xdata(std::vector<double> xdata_var) {
	this->xdata_var	=	xdata_var;
}

void plot::ydata(std::vector<double> ydata_var) {
	this->ydata_var	=	ydata_var;
}

void plot::marks(std::string marks_var) {
	this->marks_var	=	marks_var;
}

void plot::color(std::string color_var) {
	this->color_var	=	color_var;
}

void plot::smooth(bool smooth_var) {
	this->smooth_var=	smooth_var;
}

plot::plot() {	
}

plot::~plot() {	
}

class cplot{
public:
	std::ofstream myfile_var;
	std::string title_var, xlabel_var, ylabel_var;
	double xmin, xmax, ymin, ymax;
	int nPlots;
// public:
	cplot(std::string filename);
	~cplot();
	void title(std::string title_var);
	void xlabel(std::string xlabel_var);
	void ylabel(std::string xlabel_var);
	void axes(double xmin, double xmax, double ymin, double ymax);
	void addplot(int j);
	void makeplot();
	std::vector<plot> plots;
};

cplot::cplot(std::string filename_var) {
	myfile_var.open(filename_var.c_str(),std::ios::out);
	myfile_var << "\\documentclass{standalone}\n";
	myfile_var << "\\usepackage{tikz}\n";
	myfile_var << "\\usepackage{pgfplots}\n";
	myfile_var << "\\begin{document}\n";
	myfile_var << "\\begin{tikzpicture}\n";
	myfile_var << "\\begin{axis}[\n";
}

void cplot::title(std::string title_var) {
	this->title_var		=	title_var;
}

void cplot::xlabel(std::string xlabel_var) {
	this->xlabel_var	=	xlabel_var;
}

void cplot::ylabel(std::string ylabel_var) {
	this->ylabel_var	=	ylabel_var;
}

void cplot::axes(double xmin, double xmax, double ymin, double ymax) {
	this->xmin			=	xmin;
	this->xmax			=	xmax;
	this->ymin			=	ymin;
	this->ymax			=	ymax;
}

void cplot::makeplot() {
	myfile_var << "title = " << title_var << ",\n";
	myfile_var << "xlabel = {" << xlabel_var << "},\n";
	myfile_var << "ylabel = {" << ylabel_var << "},\n";
	myfile_var << "xmin	= " << xmin << ", " << "xmax = " << xmax << ",\n";
	myfile_var << "ymin	= " << ymin << ", " << "ymax = " << ymax << ",\n";
	myfile_var << "]\n";
	this->nPlots	=	plots.size();
	for (int j=0; j<nPlots; ++j) {
		addplot(j);
	}
}

cplot::~cplot() {
	myfile_var << "\\end{axis}\n";
	myfile_var << "\\end{tikzpicture}\n";
	myfile_var << "\\end{document}\n";
	myfile_var.close();
}


void cplot::addplot(int j) {
	myfile_var << "\\addplot[\n";
	myfile_var << plots[j].color_var << ", mark = " << plots[j].marks_var << ", ";
	if (plots[j].smooth_var) {
		myfile_var << "smooth, \n";
	}
	myfile_var << "] coordinates {\n";
	for (int k=0; k<plots[j].xdata_var.size(); ++k) {
		myfile_var << "\t(" << plots[j].xdata_var[k] << "," << plots[j].ydata_var[k] << ")\n";
	}
	myfile_var << "};\n";
}

#endif /*_CPLOT__HPP_*/