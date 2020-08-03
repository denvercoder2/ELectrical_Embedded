#include "Everywhere.h"
#include <stdio.h>
#include <math.h>

double DegreestoRadians(double degree){
    long double tmp_deg = (M_PI) / 180;

    return (tmp_deg * degree);
}


double getDistance(double lat1,double long1,
                double lat2, double long2){

    lat1 = DegreestoRadians(lat1); 
    long1 = DegreestoRadians(long1); 
    lat2 = DegreestoRadians(lat2); 
    long2 = DegreestoRadians(long2); 
      
    // Haversine Formula 
    double dlong = long2 - long1; 
    double dlat = lat2 - lat1; 
  
    long double ans = pow(sin(dlat / 2), 2) +  
                          cos(lat1) * cos(lat2) *  
                          pow(sin(dlong / 2), 2); 
  
    ans = 2 * asin(sqrt(ans)); 
  
    // Radius of Earth in  
    // Kilometers, R = 6371 
    // Use R = 3956 for miles 
    long double R = 6371; 
      
    // Calculate the result 
    ans = ans * R; 
  
    return ans; 

}

int main(void){
    double degree = 1.00;
    double rad = DegreestoRadians(degree);

    double lat1 = 53.32055555555556; 
    double long1 = -1.7297222222222221; 
    double lat2 = 53.31861111111111;
    double long2 = -1.6997222222222223;

    printf("Degree %5f to Radian %.7f", degree, rad);
    double Distance = getDistance(lat1, lat2, long1, long2);

    printf("\nDistance between two points: %f KM", Distance);
}