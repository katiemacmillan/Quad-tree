#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

// prototypes
bool LoadBmpFile( const char* filename, int &NumRows, int &NumCols, unsigned char** &ImagePtr );
static short readShort( FILE* infile );
static int readLong( FILE* infile );
static void skipChars( FILE* infile, int numChars );
static inline int GetNumBytesPerRow( int NumCols );
