#include <iostream>
#include <boost/format.hpp>
#include <QtGui>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <QLineF>
#include <QRectF>
#include <QApplication> 
#include <QGraphicsScene>
#include <QGraphicsView> 
//#include<bits/stdc++.h>
#include<string.h>
#include <fstream> //for file read and write
//#include<cartesian.h>
using namespace std;
int main(int argc, char **argv)
{
	ifstream fin;

	string line;
	ofstream fout;

	
	int j = 1;
		
	
	fin.open("input.txt");
	//char* str;
	QApplication app(argc, argv);
	QGraphicsScene scene;
	while (fin) {
		//cout << "sdkjdsk";
		// Read a Line from File 
		int ar[4];
		int i = 0;
		while (i != 4)
		{
			getline(fin, line);
			if (fin.eof())
				break;
			int k = line.length();
			k++;
			char str[100];
			strcpy(str, line.c_str());
			ar[i] = atoi(str);
			i++;
		}
		cout <<"("<<ar[0] << "," << ar[1]<<")"<< "(" << ar[2] << "," << ar[3]<<")\n";
		scene.addLine(QLineF(ar[0],ar[1],ar[2],ar[3]));
		// Print line in Console 
		//cout << line << endl;
		
		//break;
	}
	fin.close();
	
	//getline(fin, line);
	
    scene.setSceneRect(0,0, 100, 100);

	//mouseCoordinates(QPointF (23,44));

    QGraphicsView* view = new QGraphicsView(&scene);
    CGAL::Qt::GraphicsViewNavigation navigation;
    view->installEventFilter(&navigation);
    view->viewport()->installEventFilter(&navigation);
    view->setRenderHint(QPainter::Antialiasing);

    view->show();
    return app.exec();
}

