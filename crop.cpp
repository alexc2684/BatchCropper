#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv )
{
  Mat image=imread("test.jpg",1);
  cv::Size s = image.size();
  float rows = s.height;
  float cols = s.width;
  int xlen = (int) rows/500;
  int ylen = (int) cols/500;
  cout << cols;
  int width=500,height=500;
  int count = 0;
  for (int i = 250; i < cols - 1000; i += 500) {
    for (int j = 250; j < rows - 1000; j += 500) {
      // cout << i;
      // cout << j;
      Mat ROI(image, Rect(i,j,width,height));

      Mat croppedImage;

      // Copy the data into new matrix
      ROI.copyTo(croppedImage);
      std::string c = std::to_string(count);
      std::string name = "imgs/" + c + ".jpg";
      imwrite(name,croppedImage);

      count = count + 1;
    }
  }


}
