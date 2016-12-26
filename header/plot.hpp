#include <fstream>
#include <vector>

class plot {
private:
	std::vector<double> xdata_var, ydata_var;
	std::string marks_var, color_var;
	bool smooth_var;
public:
	void xdata(std::vector<double> xdata_var);
	void ydata(std::vector<double> ydata_var);
	void marks(std::string marks_var);
	void color(std::string color_var);
	void smooth(bool smooth_var);
	void addplot();
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