// Copyright (C) 2019 Matthieu Pizenberg
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <boost/filesystem.hpp>
#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>

namespace fs = boost::filesystem;

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
