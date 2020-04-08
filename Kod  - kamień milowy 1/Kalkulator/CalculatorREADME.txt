//Working with Calculator

//Calculating pair of coordinates
//Need:
//   functions witch are used to calculate coordinate x
//   functions witch are used to calculate coordinate y
//   value of t witch we want to formula on

pair<double, double> calculateValue(vector<Function*> x_function, vector<Function*> y_function, double t);

//Calculating serie of coordinates
//Need:
//   functions witch are used to calculate coordinate x
//   functions witch are used to calculate coordinate y
//   left margin of range
//   right margin of range
//   number of points

vector<pair<double, double> > calculateSerie(vector<Function*> x_function, vector<Function*> y_function, double left, double right, double points_number);
