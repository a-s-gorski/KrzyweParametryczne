//Working with Functions

//Check if given set of parrameters is correct for function. Return true if yes.
virtual bool check_parameters(vector<double> parameters)=0;

//Same for every function, replace old vector of parameters with new one
virtual void set_parameters(vector<double> parameters); 

//Calculat value using specific function formula
virtual double calculate_value(double t)=0;
