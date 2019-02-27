#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polygon_2.h>
#include <iostream>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point;
typedef CGAL::Triangle_2<K> Triangle_2;
typedef  CGAL::Segment_2 <K> Segment_2;
using std::cout; using std::endl;


int main()
{  
  //Point points[] = { Point(0,0), Point(0,10), Point(10,10)};
  Point P1(0, 0), P2(0, 12), P3(20, 20),P4(20,45);
  Segment_2  s1(P1, P2), s2(P3, P4);
  
  //Triangle_2 pgn(P1,P2,P3);
  CGAL::Object result = CGAL::intersection(s1, s2);
  Point  poin1;
  Segment_2 segment;
  if (CGAL::assign(poin1, result)) 
  { cout << "point." << endl;  } 
  else
if(CGAL::assign(segment, result)) 
  { cout << "segment." << endl;  }

  //double Area = pgn.area();
  //cout << Area;
  // check if the polygon is simple.


  return 0;
}
