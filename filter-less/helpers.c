#include "helpers.h"
#include <stdio.h>
#include <math.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int a = 0; a<height; a++)//height loop
    {
        for(int b = 0; b<width; b++)//width loop
        {
            int m = (image[a][b].rgbtRed + image[a][b].rgbtBlue + image[a][b].rgbtGreen)/3;//média das cores
            image[a][b].rgbtRed = m;
            image[a][b].rgbtBlue = m;
            image[a][b].rgbtGreen = m;
        }
    }
    return;
}

// Convert image to sepia
//troquei por edges
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int r[3];
    for(int a = 0; a<height; a++)//height loop
    {
        int b;
        if (width%2==0)
        {
            b = width/2;
        }
        else
        {
            b=(width-1)/2;
        }
        for(int q = 0; q<b; q++)//width loop
        {
            r[0] = image[a][q].rgbtRed;//trocando os pixels opostos de lugar
            r[1] = image[a][q].rgbtBlue;
            r[2] = image[a][q].rgbtGreen;
            image[a][q].rgbtRed = image[a][width-q].rgbtRed;
            image[a][q].rgbtBlue = image[a][width-q].rgbtBlue;
            image[a][q].rgbtGreen = image[a][width-q].rgbtGreen;
            image[a][width-q].rgbtRed = r[0];
            image[a][width-q].rgbtBlue = r[1];
            image[a][width-q].rgbtGreen = r[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int o[3];
    for(int a = 0; a<height; a++)//height loop
    {
        for(int b = 0; b<width; b++)//width loop
        {
            if((a==0||a==height)||(b==0||b==width))//lados
            {
                if(a==0||a==height)//bases
                {
                    if(a==0)//primeira linha
                    {
                        if(b==0||b==width)
                        {
                            if(b==0)//canto superior esquerdo
                            {
                                image[a][b].rgbtRed = (image[a][b].rgbtRed + image[a][b+1].rgbtRed + image[a-1][b].rgbtRed + image[a-1][b+1].rgbtRed)/4;
                                image[a][b].rgbtBlue = (image[a][b].rgbtBlue + image[a][b+1].rgbtBlue + image[a-1][b].rgbtBlue + image[a-1][b+1].rgbtBlue)/4;
                                image[a][b].rgbtGreen = (image[a][b].rgbtGreen + image[a][b+1].rgbtGreen + image[a-1][b].rgbtGreen + image[a-1][b+1].rgbtGreen)/4;
                            }
                            if(b==width)//canto superior direito
                            {
                                image[a][b].rgbtRed = (image[a][b-1].rgbtRed + image[a][b].rgbtRed + image[a-1][b-1].rgbtRed + image[a-1][b].rgbtRed)/4;
                                image[a][b].rgbtBlue = (image[a][b-1].rgbtBlue + image[a][b].rgbtBlue + image[a-1][b-1].rgbtBlue + image[a-1][b].rgbtBlue)/4;
                                image[a][b].rgbtGreen = (image[a][b-1].rgbtGreen + image[a][b].rgbtGreen + image[a-1][b-1].rgbtGreen + image[a-1][b].rgbtGreen)/4;
                            }
                        }
                        else//primeira linha
                        {
                                image[a][b].rgbtRed = (image[a][b-1].rgbtRed + image[a][b].rgbtRed + image[a+1][b+1].rgbtRed + image[a-1][b-1].rgbtRed + image[a-1][b].rgbtRed + image[a-1][b+1].rgbtRed)/6;
                                image[a][b].rgbtBlue = (image[a][b-1].rgbtBlue + image[a][b].rgbtBlue + image[a][b+1].rgbtBlue + image[a-1][b-1].rgbtBlue + image[a-1][b].rgbtBlue + image[a-1][b+1].rgbtBlue)/6;
                                image[a][b].rgbtGreen = (image[a][b-1].rgbtGreen + image[a][b].rgbtGreen + image[a][b+1].rgbtGreen + image[a-1][b-1].rgbtGreen + image[a-1][b].rgbtGreen + image[a-1][b+1].rgbtGreen)/6;
                        }
                    }
                    if(a==height)//última linha
                    {
                        if(b==0||b==width)
                        {
                            if(b==0)//canto inferior esquerdo
                            {
                                image[a][b].rgbtRed = (image[a][b].rgbtRed + image[a][b+1].rgbtRed + image[a+1][b].rgbtRed + image[a+1][b+1].rgbtRed)/4;
                                image[a][b].rgbtBlue = (image[a][b].rgbtBlue + image[a][b+1].rgbtBlue + image[a+1][b].rgbtBlue + image[a+1][b+1].rgbtBlue)/4;
                                image[a][b].rgbtGreen = (image[a][b].rgbtGreen + image[a][b+1].rgbtGreen + image[a+1][b].rgbtGreen + image[a+1][b+1].rgbtGreen)/4;
                            }
                            if(b==width)//canto inferior direito
                            {
                                image[a][b].rgbtRed = (image[a][b-1].rgbtRed + image[a][b].rgbtRed + image[a+1][b-1].rgbtRed + image[a+1][b].rgbtRed)/4;
                                image[a][b].rgbtBlue = (image[a][b-1].rgbtBlue + image[a][b].rgbtBlue + image[a+1][b-1].rgbtBlue + image[a+1][b].rgbtBlue)/4;
                                image[a][b].rgbtGreen = (image[a][b-1].rgbtGreen + image[a][b].rgbtGreen + image[a+1][b-1].rgbtGreen + image[a+1][b].rgbtGreen)/4;
                            }
                        }
                        else//última linha linha
                        {
                            image[a][b].rgbtRed = (image[a][b-1].rgbtRed + image[a][b].rgbtRed + image[a][b+1].rgbtRed + image[a+1][b-1].rgbtRed + image[a+1][b].rgbtRed + image[a+1][b+1].rgbtRed)/6;
                            image[a][b].rgbtBlue = (image[a][b-1].rgbtBlue + image[a][b].rgbtBlue + image[a][b+1].rgbtBlue + image[a+1][b-1].rgbtBlue + image[a+1][b].rgbtBlue + image[a+1][b+1].rgbtBlue)/6;
                            image[a][b].rgbtGreen = (image[a][b-1].rgbtGreen + image[a][b].rgbtGreen + image[a][b+1].rgbtGreen + image[a+1][b-1].rgbtGreen + image[a+1][b].rgbtGreen + image[a+1][b+1].rgbtGreen)/6;
                        }
                    }
                }
                if((b==0||b==width)&&(a!=1)&&(a!=height))//lados sem os cantos
                {
                    if(b==0)//lado esquerdo
                    {
                        image[a][b].rgbtRed = (image[a][b].rgbtRed + image[a][b+1].rgbtRed + image[a+1][b].rgbtRed + image[a+1][b+1].rgbtRed + image[a-1][b].rgbtRed + image[a-1][b+1].rgbtRed)/6;
                        image[a][b].rgbtBlue = (image[a][b].rgbtBlue + image[a][b+1].rgbtBlue + image[a+1][b].rgbtBlue + image[a+1][b+1].rgbtBlue + image[a-1][b].rgbtBlue + image[a-1][b+1].rgbtBlue)/6;
                        image[a][b].rgbtGreen = (+ image[a][b].rgbtGreen + image[a][b+1].rgbtGreen + image[a+1][b].rgbtGreen + image[a+1][b+1].rgbtGreen + image[a-1][b].rgbtGreen + image[a-1][b+1].rgbtGreen)/6;
                    }
                    else//lado direito
                    {
                        image[a][b].rgbtRed = (image[a][b-1].rgbtRed + image[a][b].rgbtRed + image[a+1][b-1].rgbtRed + image[a+1][b].rgbtRed + image[a-1][b-1].rgbtRed + image[a-1][b].rgbtRed)/6;
                        image[a][b].rgbtBlue = (image[a][b-1].rgbtBlue + image[a][b].rgbtBlue + image[a+1][b-1].rgbtBlue + image[a+1][b].rgbtBlue + image[a-1][b-1].rgbtBlue + image[a-1][b].rgbtBlue)/6;
                        image[a][b].rgbtGreen = (image[a][b-1].rgbtGreen + image[a][b].rgbtGreen + image[a+1][b-1].rgbtGreen + image[a+1][b].rgbtGreen + image[a-1][b-1].rgbtGreen + image[a-1][b].rgbtGreen)/6;
                    }
                }
            }
            else//meio
            {
                image[a][b].rgbtRed = (image[a][b-1].rgbtRed + image[a][b].rgbtRed + image[a][b+1].rgbtRed + image[a+1][b-1].rgbtRed + image[a+1][b].rgbtRed + image[a+1][b+1].rgbtRed + image[a-1][b-1].rgbtRed + image[a-1][b].rgbtRed + image[a-1][b+1].rgbtRed)/9;
                image[a][b].rgbtBlue = (image[a][b-1].rgbtBlue + image[a][b].rgbtBlue + image[a][b+1].rgbtBlue + image[a+1][b-1].rgbtBlue + image[a+1][b].rgbtBlue + image[a+1][b+1].rgbtBlue + image[a-1][b-1].rgbtBlue + image[a-1][b].rgbtBlue + image[a-1][b+1].rgbtBlue)/9;
                image[a][b].rgbtGreen = (image[a][b-1].rgbtGreen + image[a][b].rgbtGreen + image[a][b+1].rgbtGreen + image[a+1][b-1].rgbtGreen + image[a+1][b].rgbtGreen + image[a+1][b+1].rgbtGreen + image[a-1][b-1].rgbtGreen + image[a-1][b].rgbtGreen + image[a-1][b+1].rgbtGreen)/9;
            }

        }
    }
    return;
}
