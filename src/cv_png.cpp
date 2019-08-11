#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {

  // Read input file.
  std::ifstream file(argv[1], std::ios::binary);
  std::vector<char> input(std::istreambuf_iterator<char>{file}, {});

  // Bench PNG reading.
  clock_t begin = clock();
  for (int i = 0; i < 100; i++) {
    cv::Mat img;
    int flags = cv::IMREAD_ANYDEPTH | cv::IMREAD_UNCHANGED;
    cv::imdecode(input, flags, &img);
  }
  clock_t end = clock();
  double elapsed_ms = 1000.0 * double(end - begin) / CLOCKS_PER_SEC;
  std::cerr << "Elapsed time: " << elapsed_ms << " ms" << std::endl;

  return 0;
}
