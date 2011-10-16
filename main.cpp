#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "RoadExtraction.hpp"
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	RoadExtraction* CapturedMap = new RoadExtraction();
	/*
   if (argc != 2) {
      std::cout << "usage: " << argv[0] << " imageFile" << std::endl;
      return -1;
   }
   */
	CapturedMap->LoadImage("Marc.png");
	CapturedMap->ShowSource();
	CapturedMap->InitModified();

	cvWaitKey(0);

	CapturedMap->MeanShift(3,25);

	cvWaitKey(0);

	//CapturedMap->InitKMean();
	CapturedMap->ManualKMean(10,0,0,0);

	cvWaitKey(0);

	return 0;
}

