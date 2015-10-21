#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

// prototypes
bool LoadBmpFile( const char* filename, int &NumRows, int &NumCols, unsigned char** &ImagePtr );
short readShort( FILE* infile );
int readLong( FILE* infile );
void skipChars( FILE* infile, int numChars );
inline int GetNumBytesPerRow( int NumCols );
