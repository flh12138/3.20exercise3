#include <iostream>
#include <opencv.hpp>
using namespace cv;
using namespace std;

int main()
{

	//����ͼƬ��ֵ��
	cv::Mat src = imread("E:\\PIC\\IMG_1989.jpg", 0);
	cv::Mat binaryMat;
	threshold(src, binaryMat, 0, 255, THRESH_OTSU);
	cv::Mat dst1;

	//���и�ʴ����
	Mat getStructuringElement(int shape, Size ksize, Point anchor = Point(-1, -1));
	Mat kernel = getStructuringElement(MORPH_RECT, Size(10, 10));
	dilate(binaryMat, dst1, kernel);

	//����ʴ���ͼ��ȥԭ��ֵͼ
	cv::Mat dst2 = dst1-binaryMat;

	//������ͨ���ǣ����ԭ�����
	cv::Mat labels;
	cv::Mat stats;
	cv::Mat cenrtroids;
	cv::Mat resultMat;
	int nComp = connectedComponentsWithStats(dst2, labels, stats, cenrtroids, 8, 4);
	cout << "the number is " << nComp - 1 << endl;

	imshow("src1", dst1);
	imshow("scr2", binaryMat);
	waitKey(0);
}