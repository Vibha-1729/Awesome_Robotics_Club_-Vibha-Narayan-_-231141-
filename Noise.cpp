#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Load the image
    Mat img = imread("Photos/Noise.png");
    if (img.empty()) {
        cout << "Could not read the image." << endl;
        return 1;
    }

    Mat output_gaus, output_med, output_bilateral;

    // Gaussian Blur
    GaussianBlur(img, output_gaus, Size(5, 5), 0, 0);

    // Median Blur (reduction of noise)
    medianBlur(img, output_med, 5);

    // Bilateral Filtering (Reduction of noise + Preserving of edges)
    bilateralFilter(img, output_bilateral, 9, 75, 75);

    // Display results
    imshow("Original Image", img);
    imshow("Gaussian Blur", output_gaus);
    imshow("Median Blur", output_med);
    imshow("Bilateral Filtering", output_bilateral);

    // Wait for a key press before exiting
    waitKey(0);

    return 0;
}
