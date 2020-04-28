#pragma once

template <class X1, class X2, class Y1, class Y2>

class DrawGrid
{
protected:
    X1 min_x;
    X2 max_x;
    Y1 min_y;
    Y2 max_y;
public:
    DrawGrid(X1 a, X2 b, Y1 c, Y2 d) {
        DrawGrid::min_x = a;
        DrawGrid::max_x = b;
        DrawGrid::min_y = c;
        DrawGrid::max_y = d;

    }

};


