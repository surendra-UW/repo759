
#include "convolution.h"

float pixel(int x, int y, int n, const float *image) {
    if (x>=0 and x <n and y >= 0 and y <n ) {
        return image[x*n+y];
    }

    if (x>=0 and x<n) {
        return 1.0;
    }

    if (y >= 0 and y <n) {
        return 1.0;
    }

    return 0.0;
}

void convolve(const float *image, float *output, std::size_t n, const float *mask, std::size_t m)
{
    for (int x = 0; x < int(n); x++)
    {
        for (int y = 0; y < int(n); y++)
        {
            for (int i = 0; i < int(m); i++)
            {
                for (int j = 0; j < int(m); j++)
                {
                    output[x*n+y] += mask[i*m+j]*pixel(x+i-(m-1)/2, y+j-(m-1)/2, int(n), image);
                }
            }
        }
    }
}