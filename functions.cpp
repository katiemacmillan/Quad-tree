/*
	***** BMPload.cpp *****

C++ code to read in a 24-bit BMP image file.

Author: John M. Weiss, Ph.D.
Class: CSC300 Data Structures, Fall 2015 (sample code for PA#2)

Ref: Based on code from RgbImage.cc (Buss, 3-D Computer Graphics, 2003).
*/


/* ********************************************************************
 *  LoadBmpFile
 *  Read into memory an RGB image from an uncompressed BMP file.
 *  Return true for success, false for failure.
 *  Author: Sam Buss December 2001.
 **********************************************************************/
#include "functions.h"
 
bool LoadBmpFile( const char* filename, int &NumRows, int &NumCols, unsigned char** &ImagePtr )
{
    FILE* infile = fopen( filename, "rb" );		// open binary BMP file for reading
    if ( !infile )
    {
        fprintf( stderr, "Unable to open file: %s\n", filename );
        return false;
    }

    // process BMP file header
    bool fileFormatOK = false;
    int bChar = fgetc( infile );
    int mChar = fgetc( infile );
    if ( bChar == 'B' && mChar == 'M' )			// should start with "BM" for "BitMap"
    {
        skipChars( infile, 4 + 2 + 2 + 4 + 4 );		// Skip 4 fields we don't care about
        NumCols = readLong( infile );
        NumRows = readLong( infile );
        skipChars( infile, 2 );				// Skip one field
        int bitsPerPixel = readShort( infile );
        skipChars( infile, 4 + 4 + 4 + 4 + 4 + 4 );	// Skip 6 more fields

        // check for valid image metadata
        if ( NumCols > 0 && NumCols <= 100000 && NumRows > 0 && NumRows <= 100000
                && bitsPerPixel == 24 && !feof( infile ) )
        {
            fileFormatOK = true;
        }
    }

    if ( !fileFormatOK )
    {
        fclose ( infile );
        fprintf( stderr, "Not a valid 24-bit bitmap file: %s.\n", filename );
        return false;
    }

    // allocate memory
    ImagePtr = new unsigned char*[ NumRows ];

    if ( !ImagePtr )
    {
        fclose ( infile );
        fprintf( stderr, "Unable to allocate memory for %i x %i bitmap: %s.\n",
                 NumRows, NumCols, filename );
        return false;
    }
    for (int i = 0; i < NumRows; i++)
    {
        ImagePtr[i] = new unsigned char [NumCols];
        if ( !ImagePtr[i] )
        {
            fclose ( infile );
            fprintf( stderr, "Unable to allocate memory for %i x %i bitmap: %s.\n",
                     NumRows, NumCols, filename );
            return false;
        }
    }

//    unsigned char** cPtr = ImagePtr;

    // read image RGB data
    for ( int i = 0; i < NumRows; i++ )
    {
        cout << "\nrow-" << i << "  " << endl;
        for ( int j = 0; j < NumCols; j++ )
        {
            ImagePtr[i][j] = fgetc( infile );		// Grayscale Image
//            cout << "pixel-" << j << "  ";
        }
        cout << endl;
        //skipChars( infile, GetNumBytesPerRow(NumCols) - NumCols ); // Skip 6 more fields

        // for ( int k =NumCols ; k < GetNumBytesPerRow( NumCols ); k++ )
        // {
        //     cout << "skip-" << k << "  ";
        //     fgetc( infile );			// ignore padding
        // }
    }

    // and... we should be done
    if ( feof( infile ) )
    {
        fclose ( infile );
        fprintf( stderr, "Premature end of file: %s.\n", filename );
        return false;
    }

    // for ( int i = 0; i < NumRows; i++ )
    // {
    //     int j;
    //     for ( j = 0; j < NumCols; j++ )
    //     {
    //         cout << *( cPtr + 2 ) << " ";   // Blue color value
    //         cout << *( cPtr + 1 ) << " ";    // Green color value
    //         cout << *cPtr << endl;       // Red color value
    //         cPtr += 3;
    //     }
    // }

    fclose( infile );	// Close the file

    return true;
}

// rows are word aligned
static inline int GetNumBytesPerRow( int NumCols )
{
    return ( ( 3 * NumCols + 3 ) >> 2 ) << 2;
}


// read a 16-bit integer from the input file
short readShort( FILE* infile )
{
    unsigned char lowByte, hiByte;
    lowByte = fgetc( infile );			// Read the low order byte (little endian form)
    hiByte = fgetc( infile );			// Read the high order byte

    // Pack together
    short ret = hiByte;
    ret <<= 8;
    ret |= lowByte;
    return ret;
}

// read a 32-bit integer from the input file
int readLong( FILE* infile )
{
    unsigned char byte0, byte1, byte2, byte3;
    byte0 = fgetc( infile );			// Read bytes, low order to high order
    byte1 = fgetc( infile );
    byte2 = fgetc( infile );
    byte3 = fgetc( infile );

    // Pack together
    int ret = byte3;
    ret <<= 8;
    ret |= byte2;
    ret <<= 8;
    ret |= byte1;
    ret <<= 8;
    ret |= byte0;
    return ret;
}

// skip over given number of bytes in input file
void skipChars( FILE* infile, int numChars )
{
    for ( int i = 0; i < numChars; i++ )
    {
        fgetc( infile );
    }
}