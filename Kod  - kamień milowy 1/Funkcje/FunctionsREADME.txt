//Working with Functions

//Check if given set of parrameters is correct for function. Return true if yes.
//Used by InputController
virtual bool checkParameters(vector<double> parameters)=0;

//Same for every function, replace old vector of parameters with new one
//Used by InputController
virtual void setParameters(vector<double> parameters); 

//Calculat value using specific function formula
//Used by Calculator
virtual double calculateValue(double t)=0;
