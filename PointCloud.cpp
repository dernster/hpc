/*
 * PointCloud.cpp
 *
 *  Created on: Feb 1, 2015
 *      Author: dernster
 */

#include "PointCloud.h"
#include <stdio.h>

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

			cout << "color " << color << endl;



//			unsigned  r = color & 0xff;
//			unsigned  g = (color >> 8) & 0xff;
//			unsigned  b = (color >> 16) & 0xff;

			unsigned char r = BYTE(color,0);
			unsigned char g = BYTE(color,1);
			unsigned char b = BYTE(color,2);

			points.push_back(new Point(x,y,z,r,g,b));
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
			BYTE(color,0) = point->r;
			BYTE(color,1) = point->g;
			BYTE(color,2) = point->b;
			fprintf(f,"%g %g %g %u\n",point->x,point->y,point->z,color);
		}
		fclose(f);
	}
}

