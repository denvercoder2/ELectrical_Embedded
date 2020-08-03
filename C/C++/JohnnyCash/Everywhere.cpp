#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <vector>
#include <algorithm>
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
      
    /* Haversine Formula for distance */
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

/* this is a greedy choice algorithm, I only care about the best right now */
inline long double chooseBestRoute(long double total_distance, long double route1, long double route2){
    total_distance += std::min(route1, route2);

    return total_distance;
}

#if 0
/**
 * Function should return a vector containing
 * the value of it's distance from a given point
 */ 
std::vector<long double> storeDistances(void){
    long double center = 0.0; /* starting point */

    #if defined (__FREEDOM_UNITS__)
        char format[10] = "Miles";
    #else
        char format[10] = "KM";
    #endif


    printf("\nDistance: %Lf:  %s\n", getDistance(lat1, long1,  
                     lat2, long2), format); 
  
    return 0; 
}  
}
#endif

int main() 
{ 
    long double total_distance = 0.0;
    long double total_distance_new;
    long double lat1 = WinnemuccaNV_LAT; 
    long double long1 = WinnemuccaNV_LONG; 
    long double lat2 = 0; 
    long double long2 = 0; 
      
    #if defined (__FREEDOM_UNITS__)
        char format[10] = "Miles";
    #else
        char format[10] = "KM";
    #endif


    printf("\nDistance: %Lf:  %s\n", getDistance(lat1, long1,  
                     lat2, long2), format); 
    


    /**
     * In order for this to be done efficiently, it needs to be loaded into memory at the next
     * point of execution, instead of all at once.
     */
    total_distance_new = chooseBestRoute(total_distance, 1000, getDistance(lat1, long1,  
                     lat2, long2));
    
    printf("\nNew total distance: %Lf", total_distance_new);
  
    return 0; 
} 