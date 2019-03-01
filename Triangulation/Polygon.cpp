#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polygon_2.h>
#include <CGAL/Triangulation_2.h>
#include <CGAL/draw_triangulation_2.h>
#include <vector>
#include <iostream>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>



typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point;
typedef CGAL::Triangle_2<K> Triangle_2;
typedef CGAL::Triangulation_2<K> Triangulation;
using std::cout; using std::endl;


int main()
{
  Point points[] = { Point(0,0), Point(0,10), Point(10,10),Point(10,0)};
  Point P1(0, 0), P2(0, 12), P3(6, 6);
  Triangulation tr;
  tr.insert(points, points + 4);
  cout << tr;
 // CGAL::draw(tr);
  return 0;
}
