/**
 * This is the header file for the stupid project I thought of on the way home today
 * 
 * It will include the definitions of some well known math functions and values to save me time 
 * in the long run. 
 * 
 * Developed by Scott Holley for some reason
 */

/* Choose standard or metric */
#define NOT_FREEDOM_UNITS

#define RADII 180

#define FPAERROR 93.860937 
/* Prototypes for main function */

/* Convert Degree passed in to radian value */
long double toRadians(const long double degree);

/* get the distance between two points*/
long double getDistance(double lat1,double long1,
                double lat2,double long2);

std::vector<long double> storeDistances(void);