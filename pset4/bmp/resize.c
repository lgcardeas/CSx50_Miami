
/**
 * resize.c is a copy of copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, and resize the new file by n times. It's n times width and n times height
 
   */    
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

//PROTOTYPES 
void printCol(RGBTRIPLE, FILE*, int);
void printRow(RGBTRIPLE arr_rgb[], FILE* outptr, int n,int size, int padding_resize);

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv[1]);
    if (n > 100 || n < 0){
        printf("n must be between 0 and 100\n");
        return 1;
    }
    
    char* infile = argv[2];
    char* outfile = argv[3];
    

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, bf_resize;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bf_resize = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, bi_resize;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    bi_resize = bi;
    

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

   
    /*Changing BTIMAPINFOHEADER... multiplying by n the width and the heaight*/
    
        
        bi_resize.biWidth = bi.biWidth * n;
        bi_resize.biHeight = bi.biHeight * n;
        
    // determine padding for scanlines
    
    int padding_resize =  (4 - (bi_resize.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    bi_resize.biSizeImage = (bi_resize.biWidth * sizeof(RGBTRIPLE) + padding_resize) * abs(bi_resize.biHeight);
    bf_resize.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi_resize.biSizeImage;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_resize, sizeof(BITMAPFILEHEADER), 1, outptr);
    
     // write outfile's BITMAPINFOHEADER
    fwrite(&bi_resize, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        //I'll need an array of RGBTRIPLE which will contain each line.
        RGBTRIPLE arr_rgb[bi.biWidth];
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // read RGB triple from infile
            fread(&arr_rgb[j], sizeof(RGBTRIPLE), 1, inptr);
        }
        //Print the row n times
        printRow(arr_rgb, outptr, n, bi.biWidth, padding_resize);
        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}

void printCol(RGBTRIPLE triple, FILE* outptr, int n){
    for (int i = 0; i < n; i++){
        // write RGB triple to outfile
        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
    }
}

void printRow(RGBTRIPLE arr_rgb[], FILE* outptr, int n, int size, int padding_resize){
    for (int i = 0; i < n ; i++){
        // write RGB triple to outfile
        for (int j = 0 ; j < size; j++){
            printCol(arr_rgb[j], outptr, n);
        }
        // then add it back (to demonstrate how)
    for (int k = 0; k < padding_resize; k++)
        {
            fputc(0x00, outptr);
        }
    }
}
