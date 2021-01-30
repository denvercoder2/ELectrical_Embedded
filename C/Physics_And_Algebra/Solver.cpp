#include <math.h>
#include <vector>
#include <stdio.h>
#include <tuple> 

/**
 * 
 * Physics Formulas
 * 
 */ 
inline double getPressure(double Force, double Area){
    return Force/Area;
}

inline double getDensity(double Mass, double Volume) {
    return Mass/Volume;
}

inline double CentripicalForce(double Mass, double Radius, double Velocity) {
    double mv_squared = pow((Mass * Velocity), 2);
    return mv_squared/Radius;
}

inline double CentripicalAcceleration(double Radius, double Velocity) {
    double v_squared = pow(Velocity, 2);
    return v_squared/Radius;
}

inline double getPower(double Force, double Displacement) {
    return Force * Displacement;
}

inline double getFriction(double FrictionalForce, double NormalForce) {
    return FrictionalForce/NormalForce;
}
 
inline double getDisplacement(double InitialVelocity, double Time, double Acceleration) {
    return (InitialVelocity * Time) + (.500 * (Acceleration * pow(Time, 2)));
}

inline double getVelocity(double Displacement, double Time_taken){
    return Displacement/Time_taken;
}

inline double getAcceleration(double ChangeInVelocity, double ChangeInTime) {
    return ChangeInVelocity/ChangeInTime;
}



/**
 * 
 * Algebra Formulas
 * 
 */
inline double getPerimeter(double Length, double Width){
    return 2*(Length * Width);
}

inline double getCircumference(double Radius = 0, double Diameter = 0){
    
    if (Diameter) {
        return M_PI * Radius;
    } else {
        return 2*(M_PI * Radius);
    }
}

inline double getPythagTheorm(double a, double b) {
    double PTheorm_c = pow(a, 2) + pow(b, 2);
    return PTheorm_c;
}

inline double getDistance(double x1, double x2, double y1, double y2){
    double distance = sqrt((pow(x2 - x1, 2) + pow(y2 - y1, 2)));
    return distance;
}

inline double SlopeIntercept(double m, double x, double b){
    return m*(x + b);
}

inline double PointSlopeForm(double m, double x, double x1) {
    double Y = m * (x - x1);
    return Y;
}

std::tuple<double, double> getMidpoint(double x1, double x2, double y1, double y2){
    double M1 = (x1+x2)/2;
    double M2 = (y1+y2)/2;

    std::tuple<double, double> Midpoint;
    Midpoint = std::make_tuple(M1, M2);
    return Midpoint;
}

