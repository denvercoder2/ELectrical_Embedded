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
// #define __FREEDOM_UNITS__
#define func                main

/* Constant Radius */
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

#define _MinnesotaLAT       46.7296
#define _MinnesotaLONG      94.6859

#define BuffaloLAT          42.8864
#define BuffaloLONG         78.8784

#define _TorontoLAT         43.6532
#define _TorontoLONG        79.3832

#define _WinslowLAT         35.0242
#define _WinslowLONG        110.6974

#define _SarasotaLAT        27.3364
#define _SarasotaLONG       82.5307

#define WichitaLAT          37.6872
#define WichitaLONG         97.3301

#define _TulsaLAT           36.1540
#define _TulsaLONG          95.9928

#define _OttawaLAT          45.4215
#define _OttawaLONG         75.6972

#define _OklahomaLAT        35.0078
#define _OklahomaLONG       97.0929

#define TampaLAT            27.9506
#define TampaLONG           82.4572

#define _PanamaLAT          8.9824
#define _PanamaLONG         79.5199

#define _MattawaLAT         46.7379 
#define _MattawaLONG        119.9028

#define _La_PalomaLAT       49.1682
#define _La_PalomaLONG      20.8278

#define BangorLAT           44.8016
#define BangorLONG          68.7712

#define _BaltimoreLAT
#define _BaltimoreLONG

#define _SalvadorLAT
#define _SalvadorLONG

#define _AmarilloLAT
#define _AmarilloLONG

#define TocopillaLAT
#define TocopillaLONG

#define _BarranquillaLAT
#define _BarranquillaLONG

#define _PadillaLAT
#define _PadillaLONG

#define BostonLAT
#define BostonLONG

#define _CharlestonLAT
#define _CharlestonLONG

#define _DaytonLAT
#define _DaytonLONG

#define _LouisianaLAT
#define _LouisianaLONG

#define WashingtonLAT
#define WashingtonLONG

#define _HoustonLAT
#define _HoustonLONG

#define _KingstonLAT
#define _KingstonLONG

#define _TexarkanaLAT
#define _TexarkanaLONG

#define MontereyLAT
#define MontereyLONG

#define _FaradayLAT
#define _FaradayLONG

#define _Santa_FeLAT
#define _Santa_FeLONG

#define _TallapoosaLAT
#define _TallapoosaLONG

#define Glen_RockLAT
#define Glen_RockLONG

#define _Black_RockLAT
#define _Black_RockLONG

#define _Little_RockLAT
#define _Little_RockLONG

#define _OskaloosaLAT
#define _OskaloosaLONG

#define TennesseeLAT
#define TennesseeLONG

#define _ChicopeeLAT
#define _ChicopeeLONG

#define _Spirit_LakeLAT
#define _Spirit_LakeLONG

#define Grand_LakeLAT
#define Grand_LakeLONG

#define _Devils_LakeLAT
#define _Devils_LakeLONG

#define _Crater_LakeLAT
#define _Crater_LakeLONG

#define LouisvilleLAT
#define LouisvilleLONG

#define _NashvilleLAT
#define _NashvilleLONG

#define _KnoxvilleLAT
#define _KnoxvilleLONG

#define _OmbabikaLAT
#define _OmbabikaLONG

#define ScheffervilleLAT
#define ScheffervilleLONG

#define _JacksonvilleLAT
#define _JacksonvilleLONG

#define _WatervilleLAT
#define _WatervilleLONG

#define _Costa_RicaLAT
#define _Costa_RicaLONG

#define PittsfieldLAT
#define PittsfieldLONG

#define _SpringfieldLAT
#define _SpringfieldLONG

#define _BakersfieldLAT
#define _BakersfieldLONG

#define _ShreveportLAT
#define _ShreveportLONG

#define HackensackLAT
#define HackensackLONG

#define _CadillacLAT
#define _CadillacLONG

#define _Fond_du_LacLAT
#define _Fond_du_LacLONG

#define _DavenportLAT
#define _DavenportLONG

#define IdahoLAT
#define IdahoLONG

#define _JellicoLAT
#define _JellicoLONG

#define _ArgentinaLAT
#define _ArgentinaLONG

#define _DiamantinaLAT
#define _DiamantinaLONG

#define PasadenaLAT
#define PasadenaLONG

#define _CatalinaLAT
#define _CatalinaLONG

#define _PittsburghLAT
#define _PittsburghLONG

#define _ParkersburgLAT
#define _ParkersburgLONG

#define _GravelbourgLAT
#define _GravelbourgLONG

#define _ColoradoLAT
#define _ColoradoLONG

#define EllensburgLAT
#define EllensburgLONG

#define _RexburgLAT
#define _RexburgLONG

#define _VicksburgLAT
#define _VicksburgLONG

#define _El_DoradoLAT
#define _El_DoradoLONG

#define LarimoreLAT
#define LarimoreLONG

#define _AdmoreLAT
#define _AdmoreLONG

#define _HaverstrawLAT
#define _HaverstrawLONG

#define _ChatanikaLAT
#define _ChatanikaLONG

#define ChaskaLAT
#define ChaskaLONG

#define _NebraskaLAT
#define _NebraskaLONG

#define _AlaskaLAT
#define _AlaskaLONG

#define _OpelakaLAT
#define _OpelakaLONG

#define BarabooLAT
#define BarabooLONG

#define _WaterlooLAT
#define _WaterlooLONG

#define _KalamazooLAT
#define _KalamazooLONG

#define _Kansas_CityLAT
#define _Kansas_CityLONG

#define Sioux_CityLAT
#define Sioux_CityLONG

#define _Cedar_CityLAT
#define _Cedar_CityLONG

#define _Dodge_CityLAT
#define _Dodge_CityLONG

