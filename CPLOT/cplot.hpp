#ifndef _CPLOT__HPP_
#define _CPLOT__HPP_

#include <fstream>
#include <vector>
#include "CPLOT/plot.hpp"

class cplot{
private:
	std::ofstream myfile_var;
	std::string title_var, xlabel_var, ylabel_var, legend_var;
	double xmin, xmax, ymin, ymax;
	double legend_loc_x, legend_loc_y;
	std::string legend_anchor;
	int nPlots;
public:
	cplot(std::string filename);
	~cplot();
	void title(std::string title_var);
	void xlabel(std::string xlabel_var);
	void ylabel(std::string xlabel_var);
	void axes(double xmin, double xmax, double ymin, double ymax);
	void makeplot();
	void legend(std::string legend_var, double legend_loc_x, double legend_loc_y, std::string legend_anchor);
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

void cplot::legend(std::string legend_var, double legend_loc_x, double legend_loc_y, std::string legend_anchor) {
	this->legend_var	=	legend_var;
	this->legend_loc_x	=	legend_loc_x;
	this->legend_loc_y	=	legend_loc_y;
	this->legend_anchor	=	legend_anchor;
}

void cplot::makeplot() {
	myfile_var << "title = " << title_var << ",\n";
	myfile_var << "xlabel = {" << xlabel_var << "},\n";
	myfile_var << "ylabel = {" << ylabel_var << "},\n";
	myfile_var << "xmin	= " << xmin << ", " << "xmax = " << xmax << ",\n";
	myfile_var << "ymin	= " << ymin << ", " << "ymax = " << ymax << ",\n";
	myfile_var << "legend style ={\n";
	myfile_var << "at={(" << legend_loc_x << ", " << legend_loc_y << ")},\n";
	myfile_var << "anchor = " << legend_anchor << "\n";
	myfile_var << "}\n";
	myfile_var << "]\n";
	this->nPlots	=	plots.size();
	for (int j=0; j<nPlots; ++j) {
		plots[j].addplot(myfile_var);
	}
	myfile_var << "\\legend{" << legend_var << "};\n";
}

cplot::~cplot() {
	myfile_var << "\\end{axis}\n";
	myfile_var << "\\end{tikzpicture}\n";
	myfile_var << "\\end{document}\n";
	myfile_var.close();
}

#endif /*_CPLOT__HPP_*/