#include <iostream>
#include <boost/format.hpp>
// Qt headers
#include <QtGui>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <QLineF>
#include <QRectF>
#include <QApplication> 
#include <QGraphicsScene>
#include <QGraphicsView> 
// CGAL headers
#include <CGAL/Qt/PointsGraphicsItem.h>
#include <CGAL/Qt/GraphicsViewPolylineInput.h>
#include <CGAL/Qt/utility.h>
// GraphicsView items and event filters (input classes)
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/point_generators_2.h>
#include <CGAL/Largest_empty_iso_rectangle_2.h>
// the two base classes
#include <QString>
#include <QFileDialog>
#include <QInputDialog>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef K::Vector_2 Vector_2;
typedef K::Segment_2 Segment_2;
//#include<bits/stdc++.h>
#include<string.h>
#include <fstream> //for file read and write
//#include<cartesian.h>
using namespace std;
int main(int argc, char **argv)
{
	CGAL::Qt::PointsGraphicsItem<std::vector<Point_2> > * pgi;
	std::vector<Point_2> points;
	ifstream fin;
	string line;
	ofstream fout;

	
	int j = 1;
		
	
	fin.open("input.txt");
	
	//char* str;
	QApplication app(argc, argv);
	QGraphicsScene scene;
	while (fin) {
		//cout << "moulutty";
		// Read a Line from File 
		int ar[2];
		int i = 0;
		while (i != 2)
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
		Point_2 Q(ar[0], ar[1]);
		points.push_back(Q);

		
	}

	  
	fin.close();
	 Point_2 P1(50, 50), P2(0, 12), P3(6, 6);
	 points.push_back(P1);
	 points.push_back(P2);
	 points.push_back(P3);
	 pgi = new CGAL::Qt::PointsGraphicsItem<std::vector<Point_2> >(&points);
	//getline(fin, line);
	pgi->setVerticesPen(QPen(Qt::red,2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    scene.setSceneRect(0,0, 100, 100);
	scene.addItem(pgi);
	//mouseCoordinates(QPointF (23,44));

    QGraphicsView* view = new QGraphicsView(&scene);
    CGAL::Qt::GraphicsViewNavigation navigation;
    view->installEventFilter(&navigation);
    view->viewport()->installEventFilter(&navigation);
    view->setRenderHint(QPainter::Antialiasing);

    view->show();
	
    return app.exec();
}

//لَا يُكَلِّفُ اللّٰهُ نَفۡسًا اِلَّا وُسۡعَهَا