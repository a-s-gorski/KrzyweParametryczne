# Working with Functions
## Same for every base and derived class


### Check if given operation is proper
## Need
- operation in char
```cpp
bool checkOperation(char operation);
```

### Check if given operation is proper
## Need
- operation in char
```cpp
bool checkOperation(char operation);
```

### Check if given set of parrameters is correct for function.
- Return true if yes.
- Used by InputController 
```cpp
virtual bool checkParameters(vector<double> parameters)=0
```

### Replace old vector of parameters with new one
- Used by InputController
```cpp
virtual void setParameters(vector<double> parameters); 
```

### Calculat value 
- Use specific function formula
- Used by Calculator
```cpp
virtual double calculateValue(double t)=0;
```