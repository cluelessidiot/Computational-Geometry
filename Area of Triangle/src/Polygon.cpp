#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polygon_2.h>
#include <iostream>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point;
typedef CGAL::Triangle_2<K> Triangle_2;
using std::cout; using std::endl;


int main()
{
  Point points[] = { Point(0,0), Point(0,10), Point(10,10)};
  Point P1(0, 0), P2(0, 12), P3(6, 6);
  Triangle_2 pgn(P1,P2,P3);
  double Area = pgn.area();
  cout << Area;
  
  // check if the polygon is simple.


  return 0;
}
