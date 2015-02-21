/*
 * PointCloud.cpp
 *
 *  Created on: Feb 1, 2015
 *      Author: dernster
 */

#include "PointCloud.h"
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>

PointCloud::PointCloud() {
	// TODO Auto-generated constructor stub

}

PointCloud::PointCloud(vector<Point*> points){
	this->points = points;
}

PointCloud::~PointCloud() {
	for(uint i = 0; i < points.size(); i++){
		delete points[i];
	}
}

PointCloud::PointCloud(string fileName){

//	if (FILE *f = fopen(fileName.c_str(), "rt")){
//		for (;;){
//			float x = 0;
//			float y = 0;
//			float z = 0;
//			float color_float = 0;
//			if (fscanf(f, "%f %f %f %f", &x, &y, &z, &color_float) != 4){
//				break;
//			}
//
//			if(x != x){
//				continue;
//			}
//
//			unsigned color = *(unsigned const *)&color_float;
//			unsigned r = color & 0xff;
//			unsigned g = (color >> 8) & 0xff;
//			unsigned b = (color >> 16) & 0xff;
//
//			points.push_back(new Point(x,y,z,r,g,b));
//		}
//		fclose(f);
//	}

	if (FILE *f = fopen(fileName.c_str(), "rt")){
		for (;;){
			float x = 0;
			float y = 0;
			float z = 0;
			unsigned int color = 0;
			if (fscanf(f, "%f %f %f %u", &x, &y, &z, &color) != 4){
				break;
			}

			if(x != x){
				continue;
			}

//			unsigned  r = color & 0xff;
//			unsigned  g = (color >> 8) & 0xff;
//			unsigned  b = (color >> 16) & 0xff;

			unsigned char r = BYTE(color,0);
			unsigned char g = BYTE(color,1);
			unsigned char b = BYTE(color,2);

			points.push_back(new Point(x,y,z,(color_t)r/255,(color_t)g/255,(color_t)b/255));
		}
		fclose(f);
	}
}

void PointCloud::save(string fileName){
//	if (FILE *f = fopen(fileName.c_str(), "wt")){
//
//		fprintf(f,"# .PCD v.7 - Point Cloud Data file format\n");
//		fprintf(f,"VERSION .7\n");
//		fprintf(f,"FIELDS x y z rgb\n");
//		fprintf(f,"SIZE 4 4 4 4\n");
//		fprintf(f,"TYPE F F F F\n");
//		fprintf(f,"COUNT 1 1 1 1\n");
//		fprintf(f,"WIDTH %d\n",points.size());
//		fprintf(f,"HEIGHT 1\n");
//		fprintf(f,"VIEWPOINT 0 0 0 1 0 0 0\n");
//		fprintf(f,"POINTS %d\n",points.size());
//		fprintf(f,"DATA ascii\n");
//
//		for(uint i = 0; i < points.size(); i++){
//			Point* point = points[i];
//
//			unsigned int colorR = point->r;
//			unsigned int colorG = (point->g << 8);
//			unsigned int colorB = (point->b << 16);
//			float color_f = colorB | colorG | colorR;
//			fprintf(f,"%g %g %g %g\n",point->x,point->y,point->z,color_f/2);
//		}
//		fclose(f);
//	}
	if (FILE *f = fopen(fileName.c_str(), "wt")){

		fprintf(f,"# .PCD v.7 - Point Cloud Data file format\n");
		fprintf(f,"VERSION .7\n");
		fprintf(f,"FIELDS x y z rgb\n");
		fprintf(f,"SIZE 4 4 4 4\n");
		fprintf(f,"TYPE F F F U\n");
		fprintf(f,"COUNT 1 1 1 1\n");
		fprintf(f,"WIDTH %d\n",points.size());
		fprintf(f,"HEIGHT 1\n");
		fprintf(f,"VIEWPOINT 0 0 0 1 0 0 0\n");
		fprintf(f,"POINTS %d\n",points.size());
		fprintf(f,"DATA ascii\n");

		for(uint i = 0; i < points.size(); i++){
			Point* point = points[i];

			unsigned color;
			BYTE(color,0) = point->r*255;
			BYTE(color,1) = point->g*255;
			BYTE(color,2) = point->b*255;
			fprintf(f,"%g %g %g %u\n",point->x,point->y,point->z,color);
		}
		fclose(f);
	}
}

#define sign(x) (((x % 2) == 0) ? 1 : -1)

double uniform(){
	int randx = rand();
	double res = ((double)(randx % 100)/100);
	if (res == 0)
		res = 0.0000000003;
	return res;
}

#define gaussian() sqrt(-2*log(uniform()))*sin(2*M_PI*uniform())

#define limit(x) ((x) < 0) ? 0 : (((x) > 1) ? 1 : (x))

void PointCloud::simulateNoise(int noisePercent){

	/* initialize random seed: */
	srand (time(NULL));


	for(uint i = 0; i < points.size(); i++){

		int moneda = (rand() % 100) + 1;

		if (moneda < noisePercent){

			Point* p = points[i];
			//01 09
			p->r = limit(p->r + gaussian())*0.1 + (p->r)*0.9;
			p->g = limit(p->g + gaussian())*0.1 + (p->g)*0.9;
			p->b = limit(p->b + gaussian())*0.1 + (p->b)*0.9;
		}

	}
}

