//#define debug
#define DPRINTF(debug_level,...) if(debug_level>0){ printf("@ Func : %s, File : %s, Line : %d >>",__func__,__FILE__,__LINE__); printf("\t"); printf(__VA_ARGS__); }


