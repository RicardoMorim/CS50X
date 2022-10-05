#include "helpers.h"
#include <math.h>
#include <string.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //calculate the average vallue of each pixel
            float total, average;
            total = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            average = total/3;

            //apply the values
            image[i][j].rgbtBlue = round(average);
            image[i][j].rgbtGreen = round(average);
            image[i][j].rgbtRed = round(average);

        }
    }
    return;
}




// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Red
            float aR, bR, cR, red;
            aR = 0.393 * image[i][j].rgbtRed;
            bR = 0.769 * image[i][j].rgbtGreen;
            cR = 0.189 * image[i][j].rgbtBlue;
            red = aR + bR + cR;
            if (red>255)
            {
                red = 255;
            }

            //Green
            float aG, bG, cG, green;
            aG = 0.349 * image[i][j].rgbtRed;
            bG = 0.686 * image[i][j].rgbtGreen;
            cG = 0.168 * image[i][j].rgbtBlue;
            green = aG + bG + cG;

            if (green > 255)
            {
                green = 255;
            }

            //Blue
            float aB, bB, cB, blue;
            aB = 0.272 * image[i][j].rgbtRed;
            bB = 0.534 * image[i][j].rgbtGreen;
            cB = 0.131 * image[i][j].rgbtBlue;
            blue = aB + bB + cB;
            if (blue > 255)
            {
                blue = 255;
            }


            //apply the vallues
            image[i][j].rgbtBlue = round(blue);
            image[i][j].rgbtRed = round(red);
            image[i][j].rgbtGreen = round(green);

        }
    }
    return;
}





// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //loop through image rows
    for (int i = 0; i < height; i++)
    {
        //loop through image pixels
        for (int j = 0; j < width / 2; j++)
        {
            //swap blue
            int swapBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtBlue = swapBlue;

            //swap red
            int swapRed = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][width - j - 1].rgbtRed = swapRed;

            //swap green
            int swapGreen = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][width - j - 1].rgbtGreen = swapGreen;
        }
    }
    return;
}





// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{


    //temporary variable to store the colour values
    RGBTRIPLE copy[height][width];


    //loop through each pixel and get the average value for each colour
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sumRed = 0, sumBlue = 0, sumGreen = 0;
            int  averageRed = 0, averageBlue = 0, averageGreen = 0, pixels = 0, begginingheight = i - 1, endheight = i + 1,
                 begginingwidth = j - 1, endwidth = j + 1;

            //height to take the average of the blur in each pixel
            if (begginingheight < 0)
            {
                begginingheight = 0;
            }
            else if (endheight >= height)
            {
                begginingheight = height - 2;
                endheight = height - 1;
            }
            else
            {
                endheight = i + 1;
            }

            //width to take the average of the blur in each pixel
            if (begginingwidth < 0)
            {
                begginingwidth = 0;
            }
            else if (endwidth >= width)
            {
                begginingwidth = width - 2;
                endwidth = width - 1;
            }
            else
            {
                endwidth = j + 1;
            }

            //get the sum of the box that he forms
            for (int k = begginingheight; k <= endheight; k++)
            {
                for (int z = begginingwidth; z <= endwidth; z++)
                {

                    sumRed += image[k][z].rgbtRed;
                    sumBlue += image[k][z].rgbtBlue;
                    sumGreen += image[k][z].rgbtGreen;
                    pixels += 1;
                }
            }

            //calculate their average
            averageRed = round(sumRed / pixels);
            averageBlue = round(sumBlue / pixels);
            averageGreen = round(sumGreen / pixels);

            //use the copy to store the colour value
            copy[i][j].rgbtRed = averageRed;
            copy[i][j].rgbtBlue = averageBlue;
            copy[i][j].rgbtGreen = averageGreen;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //copy the 2d copy into the true image
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
        }
    }
    return;
}
