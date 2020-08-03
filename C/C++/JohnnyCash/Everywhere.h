/**
 * This is the header file for the stupid project I thought of on the way home today
 * 
 * It will include the definitions of some well known math functions and values to save me time 
 * in the long run. 
 * 
 * Developed by Scott Holley for some reason
 */



/* Prototypes for main function */

/* Convert Degree passed in to radian value */
inline long double toRadians(const long double degree);

/* get the distance between two points*/
long double getDistance(double lat1,double long1,
                double lat2,double long2);

std::vector<long double> storeDistances(void);

inline long double chooseBestRoute(long double total_distance, long double route1, long double route2);

/* Choose standard or metric */
#define __FREEDOM_UNITS__
#define RADII 180

/* Cities lat and long */
#define WinnemuccaNV_LAT    40.9730
#define WinnemuccaNV_LONG   117.7357

#define RenoNV_LAT          39.5296
#define RenoNV_LONG         119.8138

#define ChicagoIL_LAT       41.8781
#define ChicagoIL_LONG      87.6298

#define FargoND_LAT         46.8772
#define FargoND_LONG        96.7898

