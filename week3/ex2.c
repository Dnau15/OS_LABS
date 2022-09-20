#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Point{
	double x;
	double y;
} Point;
double distance(Point p1, Point p2);

double area(Point p1, Point p2, Point p3);

int main(){
	Point A = {1, 2};
	Point B = {1, 5};
	Point C = {3,3};
	printf("%f\n", distance(A, B));
	printf("%f\n", area(A,B,C));
}

double distance(Point p1, Point p2){
	return sqrt( pow(p1.x-p2.x, 2) + pow(p1.y-p2.y,2) );

}

double area(Point p1, Point p2, Point p3){
	double ar1 = p1.x * p2.y - p2.x * p1.y;
	double ar2 = p2.x*p3.y - p3.x*p2.y;
	double ar3 = p3.x*p1.y - p1.x*p3.y;
	double ar = abs(ar1 + ar2 + ar3)/2;
	return ar;
}
