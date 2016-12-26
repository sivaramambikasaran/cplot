#include <fstream>
#include <vector>

class plot {
friend class cplot;
private:
	std::vector<double> xdata_var, ydata_var;
	std::string marks_var, marks_color;
	std::string curve_var, curve_color, curve_thick;
	bool curve_smooth;
	void addplot(std::ofstream& myfile);
public:
	plot();
	~plot();
	void xdata(std::vector<double> xdata_var);
	void ydata(std::vector<double> ydata_var);
	void curve(std::string curve_var, std::string curve_color, std::string curve_thick, bool curve_smooth);
	void marks(std::string marks_var, std::string marks_color);
};

void plot::xdata(std::vector<double> xdata_var) {
	this->xdata_var	=	xdata_var;
}

void plot::ydata(std::vector<double> ydata_var) {
	this->ydata_var	=	ydata_var;
}

void plot::marks(std::string marks_var, std::string marks_color) {
	this->marks_var		=	marks_var;
	this->marks_color	=	marks_color;
}

void plot::curve(std::string curve_var, std::string curve_color, std::string curve_thick, bool curve_smooth) {
	this->curve_var		=	curve_var;
	this->curve_color	=	curve_color;
	this->curve_thick	=	curve_thick;
	this->curve_smooth	=	curve_smooth;
}

void plot::addplot(std::ofstream& myfile) {
	myfile << "\\addplot[\n";
	myfile << curve_color << ",\n";
	myfile << curve_thick << ",\n";
	myfile << curve_var << ",\n";
	if (curve_smooth) {
		myfile << "smooth,\n";
	}
	if (marks_var == "no marks") {
		myfile << "no marks,\n";
	}
	else if (marks_var == "only marks") {
		myfile << "only marks, mark = *,\n";
	}
	else {
		myfile << "mark = " << marks_var << ",\n";
	}
	myfile << "mark options = {" << marks_color << ", solid,";
	myfile << "},\n";
	myfile << "] coordinates {\n";
	for (unsigned int k=0; k<xdata_var.size(); ++k) {
		myfile << "\t(" << xdata_var[k] << "," << ydata_var[k] << ")\n";
	}
	myfile << "};\n";
}

plot::plot() {
	//	Default values for marks
	this->marks_var		=	"o";
	this->marks_color	=	"red";
	//	Default values for curve
	this->curve_var		=	"";
	this->curve_color	=	"black";
	this->curve_smooth	=	true;
	this->curve_thick	=	"thin";
}

plot::~plot() {	
}
