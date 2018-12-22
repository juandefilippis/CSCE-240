#ifndef DESKTOP_CSCE240_HW2_COMP_GEO_H_  //NOLINT
#define DESKTOP_CSCE240_HW2_COMP_GEO_H_  //NOLINT
/* Copyright Juan De Filippis
 
 * Precondition: "What must be true before function called"
 * Postcondition:"What must be true after function called"
 * Parameters:
 * First double is x_c
 * Second double is y_c
 */

#include <cmath>

// declarition of the functions
double GetCircumference(double x_c, double y_c, double x_e, double y_e);
double GetVolume(double x_c, double y_c, double x_e, double y_e);
double GetPerimeter(double x_u, double y_u, double Xur, double Yur);
double GetDistanceSquared(double x_1, double y_1, double x_2, double y_2);
double GetDistance(double x_1, double y_1, double x_2, double y_2);

#endif  // NOLINT
