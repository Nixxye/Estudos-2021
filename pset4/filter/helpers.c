#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float gx;
    float gy;
    int xm[9] = {-1,0,1,-2,0,2,-1,0,1};
    int ym[9] = {-1,-2,-1,0,0,0,1,2,1};
    int c;
    int temparrayRed[height][width];
    int temparrayBlue[height][width];
    int temparrayGreen[height][width];
    for(int a=0;a<height;a++)//height loop
    {
        for(int b=0;b<width;b++)//width loop
        {
            if(a!=0 && a!=height && b!=0 && b!=width)
            {
                //teste sem as condições de canto
                //red
                gx = image[a+1][b-1].rgbtRed*xm[0]+image[a+1][b].rgbtRed*xm[1]+image[a+1][b+1].rgbtRed*xm[2]+image[a][b-1].rgbtRed*xm[3]+image[a][b].rgbtRed*xm[4]+image[a][b+1].rgbtRed*xm[5]+image[a-1][b-1].rgbtRed*xm[6]+image[a-1][b].rgbtRed*xm[7]+image[a-1][b+1].rgbtRed*xm[8];
                gy = image[a+1][b-1].rgbtRed*ym[0]+image[a+1][b].rgbtRed*ym[1]+image[a+1][b+1].rgbtRed*ym[2]+image[a][b-1].rgbtRed*ym[3]+image[a][b].rgbtRed*ym[4]+image[a][b+1].rgbtRed*ym[5]+image[a-1][b-1].rgbtRed*ym[6]+image[a-1][b].rgbtRed*ym[7]+image[a-1][b+1].rgbtRed*ym[8];
                c = sqrt(gx*gx + gy*gy);
                if (c>255)
                {
                    c = 255;
                }
                temparrayRed[a][b] = c;
                //blue
                gx = image[a+1][b-1].rgbtBlue*xm[0]+image[a+1][b].rgbtBlue*xm[1]+image[a+1][b+1].rgbtBlue*xm[2]+image[a][b-1].rgbtBlue*xm[3]+image[a][b].rgbtBlue*xm[4]+image[a][b+1].rgbtBlue*xm[5]+image[a-1][b-1].rgbtBlue*xm[6]+image[a-1][b].rgbtBlue*xm[7]+image[a-1][b+1].rgbtBlue*xm[8];
                gy = image[a+1][b-1].rgbtBlue*ym[0]+image[a+1][b].rgbtBlue*ym[1]+image[a+1][b+1].rgbtBlue*ym[2]+image[a][b-1].rgbtBlue*ym[3]+image[a][b].rgbtBlue*ym[4]+image[a][b+1].rgbtBlue*ym[5]+image[a-1][b-1].rgbtBlue*ym[6]+image[a-1][b].rgbtBlue*ym[7]+image[a-1][b+1].rgbtBlue*ym[8];
                c = sqrt(gx*gx + gy*gy);
                if (c>255)
                {
                    c = 255;
                }
                temparrayBlue[a][b] = c;
                gx = image[a+1][b-1].rgbtGreen*xm[0]+image[a+1][b].rgbtGreen*xm[1]+image[a+1][b+1].rgbtGreen*xm[2]+image[a][b-1].rgbtGreen*xm[3]+image[a][b].rgbtGreen*xm[4]+image[a][b+1].rgbtGreen*xm[5]+image[a-1][b-1].rgbtGreen*xm[6]+image[a-1][b].rgbtGreen*xm[7]+image[a-1][b+1].rgbtGreen*xm[8];
                gy = image[a+1][b-1].rgbtGreen*ym[0]+image[a+1][b].rgbtGreen*ym[1]+image[a+1][b+1].rgbtGreen*ym[2]+image[a][b-1].rgbtGreen*ym[3]+image[a][b].rgbtGreen*ym[4]+image[a][b+1].rgbtGreen*ym[5]+image[a-1][b-1].rgbtGreen*ym[6]+image[a-1][b].rgbtGreen*ym[7]+image[a-1][b+1].rgbtGreen*ym[8];
                c = sqrt(gx*gx + gy*gy);
                if (c>255)
                {
                    c = 255;
                }
                temparrayGreen[a][b] = c;
            }
        }
    }
    for(int a=0;a<height;a++)//height loop
        {
            for(int b=0;b<width;b++)//width loop
        {
            image[a][b].rgbtRed = temparrayRed[a][b];
            image[a][b].rgbtBlue = temparrayBlue[a][b];
            image[a][b].rgbtGreen = temparrayGreen[a][b];
        }
        }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
