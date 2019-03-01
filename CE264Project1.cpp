//CE264 Project 1
//Jared Waters and Leo Chen

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/photo.hpp>
#include "opencv2/imgcodecs.hpp"
#include "iostream"
#include <vector>
#include <stdio.h> //printf
#include <math.h> //for pow to calibrate images

using namespace cv;
using namespace std;


//takes a pointer to an image name with size greater than 110x110. Fills an int array that is the three color channels averge in a hundred pixel patch.
//0=blue; 1=green; 2=red
void averageVal(const char * imageName, int* dest)//takes a pointer to an image with size greater than 110x110. Fills in array with the three color channels averge in a hundred pixel patch. 
{
	Mat image1 = imread(imageName);
	//imshow("Window1",image1); 
	//waitKey();
	int blueAvg = 0;
	int redAvg = 0;
	int greenAvg = 0;
	for (int i = 2000; i < 2010; i++) {//sum up the color channel values within a 100 pixel area
		for (int j = 1200; j < 1210; j++) {
			Vec3b intensity = image1.at<Vec3b>(i, j);
			blueAvg += intensity.val[0];
			redAvg += intensity.val[2];
			greenAvg += intensity.val[1];
		}
	}

	//divide each of the sums by 100 to get a lower noise signal
	blueAvg = blueAvg / 100;
	redAvg = redAvg / 100;
	greenAvg = greenAvg / 100;

	dest[0] = blueAvg;
	dest[1] = greenAvg;
	dest[2] = redAvg;

}

//prints the averaged brightness for a region within each of the 17 calibration photos. 
void getBrightness()//prints the values stored in the brightness images
{
	//names of the images. These must be in the dirrectory of the program.
	char image1[18] = "1.jpg";
	char image2[10] = "2.jpg";
	char image3[10] = "3.jpg";
	char image4[10] = "4.jpg";
	char image5[10] = "5.jpg";
	char image6[10] = "6.jpg";
	char image7[10] = "7.jpg";
	char image8[10] = "8.jpg";
	char image9[10] = "9.jpg";
	char image10[10] = "10.jpg";
	char image11[10] = "11.jpg";
	char image12[10] = "12.jpg";
	char image13[10] = "13.jpg";
	char image14[10] = "14.jpg";
	char image15[10] = "15.jpg";
	char image16[10] = "16.jpg";
	char image17[10] = "17.jpg";

	//end image names

	//empty arrays to hold rgb values
	int destInt1[3] = { 0 };
	int destInt2[3] = { 0 };
	int destInt3[3] = { 0 };
	int destInt4[3] = { 0 };
	int destInt5[3] = { 0 };
	int destInt6[3] = { 0 };
	int destInt7[3] = { 0 };
	int destInt8[3] = { 0 };
	int destInt9[3] = { 0 };
	int destInt10[3] = { 0 };
	int destInt11[3] = { 0 };
	int destInt12[3] = { 0 };
	int destInt13[3] = { 0 };
	int destInt14[3] = { 0 };
	int destInt15[3] = { 0 };
	int destInt16[3] = { 0 };
	int destInt17[3] = { 0 };
	//end empty arrays

	//fill the arrays with hthe channel values
	averageVal(image1, destInt1);
	averageVal(image2, destInt2);
	averageVal(image3, destInt3);
	averageVal(image4, destInt4);
	averageVal(image5, destInt5);
	averageVal(image6, destInt6);
	averageVal(image7, destInt7);
	averageVal(image8, destInt8);
	averageVal(image9, destInt9);
	averageVal(image10, destInt10);
	averageVal(image11, destInt11);
	averageVal(image12, destInt12);
	averageVal(image13, destInt13);
	averageVal(image14, destInt14);
	averageVal(image15, destInt15);
	averageVal(image16, destInt16);
	averageVal(image17, destInt17);
	//end filling

	//print result to console
	printf("Blue Values:\n");
	printf("1:%d 2:%d 3:%d 4:%d 5:%d 6:%d 7:%d 8:%d 9:%d 10:%d 11:%d 12:%d 13:%d 14:%d 15:%d 16:%d 17:%d\n", destInt1[0], destInt2[0], destInt3[0], destInt4[0], destInt5[0], destInt6[0], destInt7[0], destInt8[0], destInt9[0], destInt10[0], destInt11[0], destInt12[0], destInt13[0], destInt14[0], destInt15[0], destInt16[0], destInt17[0]);
	printf("Green Values:\n");
	printf("1:%d 2:%d 3:%d 4:%d 5:%d 6:%d 7:%d 8:%d 9:%d 10:%d 11:%d 12:%d 13:%d 14:%d 15:%d 16:%d 17:%d\n", destInt1[1], destInt2[1], destInt3[1], destInt4[1], destInt5[1], destInt6[1], destInt7[1], destInt8[1], destInt9[1], destInt10[1], destInt11[1], destInt12[1], destInt13[1], destInt14[1], destInt15[1], destInt16[1], destInt17[1]);
	printf("Red Values:\n");
	printf("1:%d 2:%d 3:%d 4:%d 5:%d 6:%d 7:%d 8:%d 9:%d 10:%d 11:%d 12:%d 13:%d 14:%d 15:%d 16:%d 17:%d\n", destInt1[2], destInt2[2], destInt3[2], destInt4[2], destInt5[2], destInt6[2], destInt7[2], destInt8[2], destInt9[2], destInt10[2], destInt11[2], destInt12[2], destInt13[2], destInt14[2], destInt15[2], destInt16[2], destInt17[2]);

	//printf("blue %d\n",destInt1[2]);
	waitKey();
}

int main() {
	//-----------Part 1: Radiometric Calibration----------------------------
	//Take a serries of images taken at varying exposure time but constant ISO. Take a patch from each of those images and calculate the average values for each color channel.
	//To verify our results: Uncomment the line getBrightness(); Run the program. It will print the values. 


		//getBrightness(); //for each image print out the average value of each color channel within a 100 pixel square

	//this resulted in G[3], which is the blue green red exponents needed to alter the brightness of each pixel/channel 
	//Plots included in report. To Confirm plot, please open exel shet included in project dirrectory
	//----------------End Code for part 1-------------------------------


	//---------------Part 2: Obtain a picture stack--------------------
	//We took several pictures using my Canon SL1 with a mini tripod. The tripod left much to be desired, but we were able to get good images. 
	//Brightness is linearized by raising each pixel/channel value to the G for that channel. The altered image is stored as a float mat.

	//	//parameters related to the regression found using the brightness values and exposure time
	double G[3] = { 1.12, 1.15, 1.16 };// B=B'^g blue green red

	double ratios[3] = { 1, 2, 4 };//contains the ratio of times
//
//	//get the images being used
	Mat image1 = imread("500.jpg");//Properly exposed
	Mat image2 = imread("250.jpg");//Brights saturated
	Mat image3 = imread("125.jpg");//Foreground mostly saturated


	Mat image1clone, image2clone, image3clone;
	//convert to float type
	image1.convertTo(image1clone, CV_32FC3);//convert the images to float so that arithmatic is more precise and can contain larger results
	image2.convertTo(image2clone, CV_32FC3);
	image3.convertTo(image3clone, CV_32FC3);
	//end converting to float

	//split each float mat into three color channels
	Mat image1BGR[3], image2BGR[3], image3BGR[3];//this will contain the separate color channels for the images
	Mat image1Altered[3], image2Altered[3], image3Altered[3];
	split(image1clone, image1BGR);
	split(image2clone, image2BGR);
	split(image3clone, image3BGR);
	//end splitting into color channels

	//alters the brightness values to be closer to the 'raw' values
	for (int i = 0; i < 3; i++) {
		pow(image1BGR[i], G[i], image1Altered[i]);
		pow(image2BGR[i], G[i], image2Altered[i]);
		pow(image3BGR[i], G[i], image3Altered[i]);
		image1Altered[i] = image1Altered[i] / 2;//After exponentiation, 255=>585, but values are now linear. To re range back to 255=saturated, scale by 255/585~2
		image2Altered[i] = image2Altered[i] / 2;
		image3Altered[i] = image3Altered[i] / 2;
	}
	//the images have been linearized
	
	//---------------merge them back together into a 3 channel mat------------------------
	Mat image3_pt2, image2_pt2, image1_pt2;
	merge(image1Altered, 3, image1_pt2);
	merge(image2Altered, 3, image2_pt2);
	merge(image3Altered, 3, image3_pt2);
	//---------------end linearized image generation---------------

//-------------------------end part 2 code--------------------------------------------------------------------

	// ALGORITHM 1: Pick and Place. For every pixel in the composite image, set it equal to teh scaled values from teh brightest image in which it was not saturated
	int count_x = 0, count_y = 0;
	int count1 = 0, count2 = 0, count3 = 0;
	//-------------Method 1: Uncomment below to implement-------------------
	Vec3f white = (255, 255, 255);
	Mat image_Alg1(Size(image1.cols, image1.rows), CV_32FC3);
		for (int x = 0; x < image1.cols; x++) {// walk through all x
			for (int y = 0; y < image1.rows; y++) {//walk through all y
				Vec3f firstIntensity = image1_pt2.at<Vec3f>(y, x);
				Vec3f secondIntensity = image2_pt2.at<Vec3f>(y, x);
				Vec3f thirdIntensity = image3_pt2.at<Vec3f>(y, x);
				if (thirdIntensity[0] >= 255.0, thirdIntensity[1] >= 255.0, thirdIntensity[2] >= 255.0) {//if the brightest image is sat
					if (secondIntensity[0] >= 255.0, secondIntensity[1] >= 255.0, secondIntensity[2] >= 255.0) {//if the mid image is sat
						image_Alg1.at<Vec3f>(y, x) = firstIntensity;
						count1++;
					}
					else {
						image_Alg1.at<Vec3f>(y, x) = secondIntensity/2;
						count2++;
					}
				}
				else {
					image_Alg1.at<Vec3f>(y,x) = thirdIntensity/4;
					count3++;
				}
			}
			count_y++;
			count_x++;
			//printf("x: %d, y: %d\n", count_x, count_y);
		}

		//printf("1: %d, 2: %d, 3: %d", count1, count2, count3);
	namedWindow("Results_Alg1", WINDOW_NORMAL);
	imwrite("Results_Alg1.jpg", image_Alg1);
//---------------------End Method 1---------------------

//--------------Method 2: uncomment below to generate image.-----------------
	Mat image_Alg2(Size(image1.cols, image1.rows), CV_32FC3);

	int c1 = 0, c2 = 0, c3 = 0;

	// ALGORITHM 2
	for (int x = 0; x < image1.cols; x++) {// walk through all x
		for (int y = 0; y < image1.rows; y++) {//walk through all y
			Vec3f firstIntensity2 = image1_pt2.at<Vec3f>(y, x);
			Vec3f secondIntensity2 = image2_pt2.at<Vec3f>(y, x);
			Vec3f thirdIntensity2 = image3_pt2.at<Vec3f>(y, x);
			if (thirdIntensity2[0] >= 255.0, thirdIntensity2[1] >= 255.0, thirdIntensity2[2] >= 255.0) {//if the brightest image is sat
				if (secondIntensity2[0] >= 255.0, secondIntensity2[1] >= 255.0, secondIntensity2[2] >= 255.0) {//if the mid image is sat
					image_Alg2.at<Vec3f>(y, x) = firstIntensity2;
					c1++;
				}
				else {
					image_Alg2.at<Vec3f>(y, x) = (secondIntensity2 + (firstIntensity2 / 2)) / 2;
					c2++;
				}
			}
			else {
				image_Alg2.at<Vec3f>(y, x) = (firstIntensity2 + (secondIntensity2 / 2) + (thirdIntensity2 / 4)) / 3;
				c3++;
			}
		}
	}
	printf("c1: %d, c2: %d, c3: %d", c1, c2, c3);

	imwrite("Results_Alg2.jpg", image_Alg2);

	//composite image histogram generation. Uncomment below
	//These histograms write to some of the same windows as the first batch of histograms. If you run this with the other section uncommented, it will
	//overwrite those plots
	//-------------------create histograms for output images with method 1,2-------
	//uncomment below to generate and print histograms



	//---------PART 4: Tone mapped composite----------------

	Mat ldr;
	Ptr<TonemapDurand>tonemap = createTonemapDurand(2.2f);
	tonemap->process(image_Alg2, ldr);

	imwrite("ldr.jpg", ldr * 255);

	printf("Done.");
	waitKey();
	//std::cin.get();
	return 0;
}
