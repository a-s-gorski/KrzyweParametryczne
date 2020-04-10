## How to enter an input to a program
#### In sequence:
1. Number of points, that you want to draw, which is a natural number
2. field of a curve <**x**, **y**>  which are 
decimal numbers, separated by space, in order 
**x** then **y**
3. next begins typing of X or Y parametric equations
   - an the begining it is needed to enter number of components for **X** equations, which is a natural number
   - then our program asks if we want our component to be trygonometric function Sine or Cosine, type accordingly **sin** or **cos**
   - after that give 3 decimal numbers, separated by space **a**, **b**, **c**, which are linear coefficients of our trygonometric function **asin(b\*t)^c** or **acos(b\*t)^c**, depending on our previous choice
   - afterwards do the same for other components of **X** equation 
   - after finishing with our **X** eparametric quation, do the same fot **Y** parametric equation

## Imlementation
### class Equation
- Holds X and Y parametric equations as a vector of pointers to derived classes from **Function** [**FCos** or **FSin**]
```cpp
   vector<Function*> equation;
```
- destructor also deletes objects which pointers are stored in a vector
- rest of a functions are self-explenatory

## class InputController
- Is responsible for getting all inputs from a user
- consists of:
   - numbers of points that will be drown on a graph
   - field of a curve represented by two numbers
   - X and Y parameteric equations
   - acordingly in a code:
```cpp
      int number_of_points;
      double left_border;
      double right_border;
      Equation X;
      Equation Y;
```

- first function to call is *getInput()* which is responible for getting all user's input
```cpp
   void getInput();
```
   - all *cin* elements are in a loop *do {...} while*, which will repeat until user enters correct values
   - tasks of the rest of functions in this class are self-explenatory by theirs names
