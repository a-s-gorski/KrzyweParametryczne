# Working with Functions
## Same for every base and derived class


## Check if given operation is proper
### Need
- operation in char
```cpp
bool checkOperation(char operation);
```

## Set given operation
### Need
- operation in char
```cpp
void setOperation(char new_operation);
```

## Get setted operation
```cpp
char getOperation();
```

## Check if given set of parrameters is correct for function.
### Need
- vector of parameters in numerical format
```cpp
virtual bool checkParameters(std::vector<V> parameters) = 0;
```

## Replace old vector of parameters with new one
### Need
- vector of parameters in numerical format
```cpp
virtual void setParameters(std::vector<V> parameters);
```

## Calculat value 
### Need
- numerical value
```cpp
virtual double calculateValue(V t) = 0;
```

## Print whole function 
```cpp
virtual void showFunction(bool not_first) = 0;
```

## Check if functions are same
### Need
- two functions of same template type
```cpp
friend bool operator==(Function<V>& lhs, Function<V>& rhs)
```

## Print on stream abreviation of Function
### Need
- stream
```cpp
friend std::ostream& operator<<(std::ostream& os, const Function& func)
```
