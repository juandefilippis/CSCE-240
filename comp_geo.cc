// Copyright Juan De Filippis
#include "comp_geo.h"// NOLINT
#include <cmath>
/* function that performs with double as parameters for each point
 and returns floating point value representing the circumference of a circle centered at (Xc,Yc) with a second point on the edge (Xe, Ye)
 */
double GetCircumference(double x_c, double y_c, double x_e, double y_e) {
    double x_b = (x_e -x_c);  // Equation to calculate the X base
    double y_b = (y_e - y_c);  // Equation to calculate the Y base
    double radius = sqrt(pow(x_b, 2) + pow(y_b, 2));
    double circum =(2* 3.14159) * radius;
    return circum;
}
/* function that performs with double as parameters for each point
 and returns floating point value representing the volume of the circle centered at (Xc,Yc) with a second point on the edge (Xe, Ye)
 */

double GetVolume(double x_c, double y_c, double x_e, double y_e) {
    double x_b = (x_e -x_c);
    double y_b = (y_e -y_c);
    double radius = sqrt(pow(x_b, 2) + pow(y_b, 2));
    double cir_area = 3.14159 * pow(radius, 2);
    return cir_area;
}
/* function that performs with double as parameters for each point
 and returns floating point value representing the distance between points 1 and 2
 */
double GetDistance(double x_1, double y_1, double x_2, double y_2) {
    double dis =((x_2-x_1)*(x_2-x_1)) + ((y_2-y_1) * (y_2-y_1));
    return sqrt(dis);
}
/* function that performs with double as parameters for each point
 and returns floating point value representing the perimeter of the rectangle
 */
double GetPerimeter(double x_u, double y_u, double x_ur, double y_ur) {
    double width = (x_ur - x_u);
    double length = (y_ur - y_u);
    double rect_peri = 2 * (length+width);
    return rect_peri;
}
/* function that performs with double as parameters for each point
 and returns floating point value representing the squared distance between points 1 and 2
 */
double GetDistanceSquared(double x_1, double y_1, double x_2, double y_2) {
    double x_b = (x_2 -x_1);
    double y_b = (y_2 - y_1);
    double sqrt_dis = pow(x_b, 2) + pow(y_b, 2);
    return sqrt_dis;
}


