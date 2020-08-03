#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include "Everywhere.h"



inline long double toRadians(const long double degree) 
{ 
    long double one_deg = (M_PI) / 180; 
    return ((M_PI) / RADII * degree); 
} 
  


long double getDistance(long double lat1, long double long1,  
                     long double lat2, long double long2){


    lat1 = toRadians(lat1); 
    long1 = toRadians(long1); 
    lat2 = toRadians(lat2); 
    long2 = toRadians(long2); 
      
    // Haversine Formula 
    long double dlong = long2 - long1; 
    long double dlat = lat2 - lat1; 
  
    long double ans = pow(sin(dlat / 2), 2) +  
                          cos(lat1) * cos(lat2) *  
                          pow(sin(dlong / 2), 2); 
  
    ans = 2 * asin(sqrt(ans)); 
  

    #if defined(__FREEDOM_UNITS__)
        long double R = 3956; 
    #else
        long double R = 6371;
    #endif
 
    ans = ans * R; 
  
    return ans; 
} 

#if 0
/**
 * Function should return a vector containing
 * the KM value from center to the place described.
 * Center should be set to 0.0
 */ 
std::vector<long double> storeDistances(void){
    long double center = 0.0; /* starting point */

    printf("\nDistance: %Lf:  K.M\n", getDistance(lat1, long1,  
                     lat2, long2)); 
}
#endif

int main() 
{ 
    long double lat1 = 53.32055555555556; 
    long double long1 = -1.7297222222222221; 
    long double lat2 = 53.31861111111111; 
    long double long2 = -1.6997222222222223; 
      
    // call the distance function 
    // cout << setprecision(15) << fixed; 
    printf("\nDistance: %Lf:  K.M\n", getDistance(lat1, long1,  
                     lat2, long2)); 
  
    return 0; 
} 