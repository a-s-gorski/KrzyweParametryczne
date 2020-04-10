#include <QtWidgets>
#include <iostream>
#include <vector>
#include <utility>


using namespace std;

class graph_Picture{
public:
    graph_Picture(QPicture picture_base, vector <pair <double, double>> coordinates){
        vector <pair <double, double>> coordinates_new = coordinates;
        QPicture picture_temp = picture_base;
        QPainter painting_canvas(&picture_temp);
        painting_canvas.setRenderHint(QPainter::Antialiasing);
//        painting_canvas.setPen(QPen(Qt::black, 12, Qt::RoundCap));
        for(int i = 1; i < coordinates_new.size(); i++){
            int x1 = (int)coordinates_new[i-1].first;
            int y1 = (int)coordinates_new[i-1].second;
            int x2 = (int)coordinates_new[i].first;
            int y2 = (int)coordinates_new[i].second;
            painting_canvas.drawLine(x1, y1, x2, y2);
        }


        painting_canvas.end();

    }


};





int main(int argc, char *argv[])
{
   QApplication a(argc, argv);

   QPicture pi;


   QLabel l;
   l.setPicture(pi);
   l.show();
   return a.exec();
}
