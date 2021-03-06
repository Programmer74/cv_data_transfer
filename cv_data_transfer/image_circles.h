#ifndef _IMG_CIRCLES_H
#define _IMG_CIRCLES_H

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define MAX_CIRCLES 30
#define MAX_UNIQ_CIRCLES 10

/* used to retrieve founded circles data */
union CustomData {
	char bytes[12];
	float floats[3];
};

/* used for founded circle info */
struct Circle_t
{
	float x;
	float y;
	float r;
};
/* used to retrieve all circles from image */
/* returns array of circles and stores the amount of them in n */
void getAllCirlces(IplImage* img, struct Circle_t* buf, size_t* n);

/* used to retrieve uniq circles from image */
/* returns array of circles and stores the amount of them in outputAmount */
void getUniqCircles(struct Circle_t* inputArray, size_t inputAmount, int minRadius, struct Circle_t* outputArray, size_t* outputAmount);

/* used to define circles on image for their easier usage */
void calculateCircles(struct Circle_t* array, struct Circle_t* top_left, struct Circle_t* top_right, struct Circle_t* bottom_left, struct Circle_t* sync, struct Circle_t* data);

/* returns 1 if bit represented by circle is set to 1 and 0 otherwise */
int bitSet(IplImage* image, struct Circle_t* circle, float threshold);

#endif