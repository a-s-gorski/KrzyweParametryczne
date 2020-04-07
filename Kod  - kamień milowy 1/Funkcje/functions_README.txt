//Working with Functions

//Check if given set of parrameters is correct for function. Return true if yes.
//Used by InputController
virtual bool check_parameters(vector<double> parameters)=0;

//Same for every function, replace old vector of parameters with new one
//Used by InputController
virtual void set_parameters(vector<double> parameters); 

//Calculat value using specific function formula
//Used by Calculator
virtual double calculate_value(double t)=0;
