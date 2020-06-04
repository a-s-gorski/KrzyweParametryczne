## Working with Calculator


### Calculating singiel coordinate
### Need:
- punctor to functions witch are used to calculate coordinate
- value of t witch we want to formula on

```cpp
double calculateSingiel (std::vector<Function<double>*>* function, double t);
```


### Calculating pair of coordinates
### Need:
- punctor to functions witch are used to calculate coordinate x
- punctor to functions witch are used to calculate coordinate y
- value of t witch we want to formula on

```cpp
pair<double, double> calculateValue(vector<Function*> *x_function, vector<Function*> *y_function, double t);
```

### Calculating serie of coordinates
### Need:
- punctor to functions witch are used to calculate coordinate x
- punctor to functions witch are used to calculate coordinate y
- left margin of range
- right margin of range
- number of points

```cpp
vector<pair<double, double> > calculateSerie(vector<Function*> *x_function, vector<Function*> *y_function, double left, double right, double points_number);
```

### Getting number of operations

```cpp
int getOperations();
```

### Clearing number of operations

```cpp
void clearOperations();
```

