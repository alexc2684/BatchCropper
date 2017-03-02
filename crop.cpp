#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv )
{
  float rows = 3456;
  float cols = 5184;
  int xlen = (int) rows/500;
  int ylen = (int) cols/500;
  int width=500,height=500;
  int count = 0;
  for (int k = 0; k < 56; k++) {
    std::string curr = std::to_string(k);
    std::string name = "samples/" + curr + ".jpg";
    Mat image=imread(name,1);
    for (int i = 250; i < cols - 1000; i += 250) {
      for (int j = 250; j < rows - 1000; j += 250) {
        // cout << i;
        // cout << j;

        Mat ROI(image, Rect(i,j,width,height));

        Mat croppedImage;

        // Copy the data into new matrix
        ROI.copyTo(croppedImage);
        std::string c = std::to_string(count);
        std::string name = "imgs/" + curr + "-" + c + ".jpg";
        imwrite(name,croppedImage);

        count = count + 1;
      }
    }
  }



}
