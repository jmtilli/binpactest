#ifndef BRO_DUMMY
#define BRO_DUMMY
#define DEBUG_MSG(x...)  fprintf(stderr, x)
/*Dummy to link, this function suppose to be in Zeek*/
double network_time();
#endif
