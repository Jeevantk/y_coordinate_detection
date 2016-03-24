#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
  Mat dist;
  Mat img=imread("Contour_Image.jpg",0);
  /*bitwise_not(img,img);
  Mat src=imread("test.jpg");
  threshold(img,otsu, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
  imshow("Initial Image",otsu);
  waitKey(0);
  Mat dist=Mat::zeros(img.rows,img.cols,CV_8UC1);
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;
  //erode(otsu,otsu, Mat(), Point(-1, -1), 2, 1, 1);
  findContours(otsu, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
  for( int i = 0; i< contours.size(); i++ )
  {
    drawContours(dist, contours, i,255,1, 8, hierarchy, 0, Point() );
  }
  imshow("Detected Contours",dist);
  waitKey(0);*/
  imshow("Original Image",img);
  distanceTransform(img,dist, CV_DIST_L2, 3);
  normalize(dist,dist, 0.0, 1.0, NORM_MINMAX);
  threshold(dist,dist, .7, 1., CV_THRESH_BINARY);

  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;
  Mat dist_8u;
  dist.convertTo(dist_8u, CV_8U);
  imshow("y_coord.jpg",dist);
  waitKey(0);
  //vector<vector<Point> > contours;
  findContours(dist_8u, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

  //findContours(img, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
  vector<Moments> mu(contours.size() );
  for( int i = 0; i < contours.size(); i++ )
  {
    mu[i] = moments( contours[i], false );
  }


  vector<Point2f> mc( contours.size() );
  for( int i = 0; i < contours.size(); i++ )
  {
    mc[i] = Point2f( mu[i].m10/mu[i].m00 , mu[i].m01/mu[i].m00 );
    Rect myROI(int(mc[i].x-25),int(mc[i].y-50),50,150);
    imshow("First_note found",img(myROI));

    waitKey(0);
  }




  imshow("After Distance transform",dist);
  waitKey(0);


}
