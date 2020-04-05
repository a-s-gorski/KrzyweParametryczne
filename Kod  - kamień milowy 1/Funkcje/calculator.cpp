#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include "functions.hpp"
#include "calculator.hpp"

using namespace std;

Calculator::Calculator(){
}

Calculator::~Calculator(){
}

pair<double, double> Calculator::calculate_value(vector<Function*> x_function, vector<Function*> y_function, double t){

    pair<double, double> point;

    double x = 0;
    double y = 0;

    for(int i=0; i<x_function.size(); i++){
        x += (*(x_function[i])).calculate_value(t);
    }

    for(int i=0; i<y_function.size(); i++){
        y += (*(y_function[i])).calculate_value(t);
    }

    point = make_pair(x,y);

    return point;
}

vector<pair<double, double> > Calculator::calculate_serie(vector<Function*> x_function, vector<Function*> y_function, double left, double right, double points_number){

    vector< pair <double, double> > points;

    double step = (right-left)/(points_number-1);

    for(double i =left; i<=right; i+=step){
        pair<double, double> point = calculate_value(x_function, y_function, i);
        points.push_back(point);
    }

    sort(points.begin(), points.end());

    return points;

}
