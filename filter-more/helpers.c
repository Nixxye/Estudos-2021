#include "helpers.h"
#include <math.h>

int count (int n, int a[9]);

typedef struct
{
    int red;
    int green;
    int blue;
}
colors;
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            double average = (image[h][w].rgbtBlue + image[h][w].rgbtRed + image[h][w].rgbtGreen) * 10/ 3;
            int ave = round(average / 10);
            image[h][w].rgbtBlue = ave;
            image[h][w].rgbtRed = ave;
            image[h][w].rgbtGreen = ave;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int red;
    int blue;
    int green;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0, n = width / 2; w < n; w++)
        {
            blue = image[h][w].rgbtBlue;
            red = image[h][w].rgbtRed;
            green = image[h][w].rgbtGreen;

            image[h][w].rgbtBlue = image[h][width - w - 1].rgbtBlue;
            image[h][w].rgbtRed = image[h][width - w - 1].rgbtRed;
            image[h][w].rgbtGreen = image[h][width - w - 1].rgbtGreen;

            image[h][width - w - 1].rgbtBlue = blue;
            image[h][width - w - 1].rgbtRed = red;
            image[h][width - w - 1].rgbtGreen = green;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    colors rgb[height][width];
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
                                rgb[a][b].red = (image[a][b].rgbtRed + image[a][b+1].rgbtRed + image[a-1][b].rgbtRed + image[a-1][b+1].rgbtRed)/4;
                                rgb[a][b].blue = (image[a][b].rgbtBlue + image[a][b+1].rgbtBlue + image[a-1][b].rgbtBlue + image[a-1][b+1].rgbtBlue)/4;
                                rgb[a][b].green = (image[a][b].rgbtGreen + image[a][b+1].rgbtGreen + image[a-1][b].rgbtGreen + image[a-1][b+1].rgbtGreen)/4;
                            }
                            if(b==width)//canto superior direito
                            {
                                rgb[a][b].red = (image[a][b-1].rgbtRed + image[a][b].rgbtRed + image[a-1][b-1].rgbtRed + image[a-1][b].rgbtRed)/4;
                                rgb[a][b].blue = (image[a][b-1].rgbtBlue + image[a][b].rgbtBlue + image[a-1][b-1].rgbtBlue + image[a-1][b].rgbtBlue)/4;
                                rgb[a][b].green = (image[a][b-1].rgbtGreen + image[a][b].rgbtGreen + image[a-1][b-1].rgbtGreen + image[a-1][b].rgbtGreen)/4;
                            }
                        }
                        else//primeira linha
                        {
                                rgb[a][b].red = (image[a][b-1].rgbtRed + image[a][b].rgbtRed + image[a+1][b+1].rgbtRed + image[a-1][b-1].rgbtRed + image[a-1][b].rgbtRed + image[a-1][b+1].rgbtRed)/6;
                                rgb[a][b].blue = (image[a][b-1].rgbtBlue + image[a][b].rgbtBlue + image[a][b+1].rgbtBlue + image[a-1][b-1].rgbtBlue + image[a-1][b].rgbtBlue + image[a-1][b+1].rgbtBlue)/6;
                                rgb[a][b].green = (image[a][b-1].rgbtGreen + image[a][b].rgbtGreen + image[a][b+1].rgbtGreen + image[a-1][b-1].rgbtGreen + image[a-1][b].rgbtGreen + image[a-1][b+1].rgbtGreen)/6;
                        }
                    }
                    if(a==height)//última linha
                    {
                        if(b==0||b==width)
                        {
                            if(b==0)//canto inferior esquerdo
                            {
                                rgb[a][b].red = (image[a][b].rgbtRed + image[a][b+1].rgbtRed + image[a+1][b].rgbtRed + image[a+1][b+1].rgbtRed)/4;
                                rgb[a][b].blue = (image[a][b].rgbtBlue + image[a][b+1].rgbtBlue + image[a+1][b].rgbtBlue + image[a+1][b+1].rgbtBlue)/4;
                                rgb[a][b].green = (image[a][b].rgbtGreen + image[a][b+1].rgbtGreen + image[a+1][b].rgbtGreen + image[a+1][b+1].rgbtGreen)/4;
                            }
                            if(b==width)//canto inferior direito
                            {
                                rgb[a][b].red = (image[a][b-1].rgbtRed + image[a][b].rgbtRed + image[a+1][b-1].rgbtRed + image[a+1][b].rgbtRed)/4;
                                rgb[a][b].blue = (image[a][b-1].rgbtBlue + image[a][b].rgbtBlue + image[a+1][b-1].rgbtBlue + image[a+1][b].rgbtBlue)/4;
                                rgb[a][b].green = (image[a][b-1].rgbtGreen + image[a][b].rgbtGreen + image[a+1][b-1].rgbtGreen + image[a+1][b].rgbtGreen)/4;
                            }
                        }
                        else//última linha linha
                        {
                            rgb[a][b].red = (image[a][b-1].rgbtRed + image[a][b].rgbtRed + image[a][b+1].rgbtRed + image[a+1][b-1].rgbtRed + image[a+1][b].rgbtRed + image[a+1][b+1].rgbtRed)/6;
                            rgb[a][b].blue = (image[a][b-1].rgbtBlue + image[a][b].rgbtBlue + image[a][b+1].rgbtBlue + image[a+1][b-1].rgbtBlue + image[a+1][b].rgbtBlue + image[a+1][b+1].rgbtBlue)/6;
                            rgb[a][b].green = (image[a][b-1].rgbtGreen + image[a][b].rgbtGreen + image[a][b+1].rgbtGreen + image[a+1][b-1].rgbtGreen + image[a+1][b].rgbtGreen + image[a+1][b+1].rgbtGreen)/6;
                        }
                    }
                }
                if((b==0||b==width)&&(a!=1)&&(a!=height))//lados sem os cantos
                {
                    if(b==0)//lado esquerdo
                    {
                        rgb[a][b].red = (image[a][b].rgbtRed + image[a][b+1].rgbtRed + image[a+1][b].rgbtRed + image[a+1][b+1].rgbtRed + image[a-1][b].rgbtRed + image[a-1][b+1].rgbtRed)/6;
                        rgb[a][b].blue = (image[a][b].rgbtBlue + image[a][b+1].rgbtBlue + image[a+1][b].rgbtBlue + image[a+1][b+1].rgbtBlue + image[a-1][b].rgbtBlue + image[a-1][b+1].rgbtBlue)/6;
                        rgb[a][b].green = (+ image[a][b].rgbtGreen + image[a][b+1].rgbtGreen + image[a+1][b].rgbtGreen + image[a+1][b+1].rgbtGreen + image[a-1][b].rgbtGreen + image[a-1][b+1].rgbtGreen)/6;
                    }
                    else//lado direito
                    {
                        rgb[a][b].red = (image[a][b-1].rgbtRed + image[a][b].rgbtRed + image[a+1][b-1].rgbtRed + image[a+1][b].rgbtRed + image[a-1][b-1].rgbtRed + image[a-1][b].rgbtRed)/6;
                        rgb[a][b].blue = (image[a][b-1].rgbtBlue + image[a][b].rgbtBlue + image[a+1][b-1].rgbtBlue + image[a+1][b].rgbtBlue + image[a-1][b-1].rgbtBlue + image[a-1][b].rgbtBlue)/6;
                        rgb[a][b].green = (image[a][b-1].rgbtGreen + image[a][b].rgbtGreen + image[a+1][b-1].rgbtGreen + image[a+1][b].rgbtGreen + image[a-1][b-1].rgbtGreen + image[a-1][b].rgbtGreen)/6;
                    }
                }
            }
            else//meio
            {
                rgb[a][b].red = (image[a][b-1].rgbtRed + image[a][b].rgbtRed + image[a][b+1].rgbtRed + image[a+1][b-1].rgbtRed + image[a+1][b].rgbtRed + image[a+1][b+1].rgbtRed + image[a-1][b-1].rgbtRed + image[a-1][b].rgbtRed + image[a-1][b+1].rgbtRed)/9;
                rgb[a][b].blue = (image[a][b-1].rgbtBlue + image[a][b].rgbtBlue + image[a][b+1].rgbtBlue + image[a+1][b-1].rgbtBlue + image[a+1][b].rgbtBlue + image[a+1][b+1].rgbtBlue + image[a-1][b-1].rgbtBlue + image[a-1][b].rgbtBlue + image[a-1][b+1].rgbtBlue)/9;
                rgb[a][b].green = (image[a][b-1].rgbtGreen + image[a][b].rgbtGreen + image[a][b+1].rgbtGreen + image[a+1][b-1].rgbtGreen + image[a+1][b].rgbtGreen + image[a+1][b+1].rgbtGreen + image[a-1][b-1].rgbtGreen + image[a-1][b].rgbtGreen + image[a-1][b+1].rgbtGreen)/9;
            }

        }
        for (int h = 0; h < height; h++)
        {
            for (int w = 0; w < width; w++)
            {
                image[h][w].rgbtRed = rgb[h][w].red;
                image[h][w].rgbtBlue = rgb[h][w].blue;
                image[h][w].rgbtGreen = rgb[h][w].green;
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

int count (int n, int a[9])
{
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        r += a[i];
    }
    return r/n;
}