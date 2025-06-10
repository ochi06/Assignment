//AJG23001 ASUKA OCHIAI

#include "ex2image.h"
#include <iostream>
#include<string>
using namespace std;

int main(int argc, const char *argv[]) {
  ex2image img;
  std::string s_file = "block.pgm";
  if (!img.load(s_file.c_str())) { //画像読み込み
    std::cerr << "cannot open the file!:" << s_file << std::endl;
    exit(-1);
  }

  //保存用の画像のバッファ
  ex2image average_3(img);
  ex2image average_5(img);
  ex2image average_7(img);

  double p;
  //画像を反転させる
  int w = average_3.img_width();
  int h = average_3.img_height();
  for (int j = 1; j < h-1; j++) {
    for (int i = 1; i < w-1; i++) {
      average_3(i,j,0)=(average_3(i-1,j-1,0)+average_3(i-1,j,0)+average_3(i-1,j+1,0)+average_3(i,j-1,0)+average_3(i,j,0)+average_3(i,j+1,0)+average_3(i+1,j-1,0)+average_3(i+1,j,0)+average_3(i+1,j+1,0))/9;
    }
  }

  string output_file_3 = "average-AJG23001-3.pgm";
  if (!average_3.write("average-AJG23001-3.pgm")) { //各画素値の書き出し
    std::cerr << "cannot write the file!: average_3.pgm" << std::endl;
    exit(-1);
  }

  for (int j = 2; j < h-2; j++) {
    for (int i = 2; i < w-2; i++) {
      average_5(i,j,0)=(average_5(i-2,j-2,0)+average_5(i-2,j-1,0)+average_5(i-2,j,0)+average_5(i-2,j+1,0)+average_5(i-2,j+2,0)+average_5(i-1,j-2,0)+average_5(i-1,j-1,0)+average_5(i-1,j,0)+average_5(i-1,j+1,0)+average_5(i-1,j+2,0)+average_5(i,j-2,0)+average_5(i,j-1,0)+average_5(i,j,0)+average_5(i,j+1,0)+average_5(i,j+2,0)+average_5(i+1,j-2,0)+average_5(i+1,j-1,0)+average_5(i+1,j,0)+average_5(i+1,j+1,0)+average_5(i+1,j+2,0)+average_5(i+2,j-2,0)+average_5(i+2,j-1,0)+average_5(i+2,j,0)+average_5(i+2,j+1,0)+average_5(i+2,j+2,0))/25;
    }
  }
  string output_file_5 = "average-AJG23001-5.pgm";
  if (!average_5.write("average-AJG23001-5.pgm")) { //各画素値の書き出し
    std::cerr << "cannot write the file!: average_5.pgm" << std::endl;
    exit(-1);
  }

  for (int j = 3; j < h-3; j++) {
    for (int i = 3; i < w-3; i++) {
      average_7(i,j,0)=(average_7(i-3,j-3,0)+average_7(i-3,j-2,0)+average_7(i-3,j-1,0)+average_7(i-3,j,0)+average_7(i-3,j+1,0)+average_7(i-3,j+2,0)+average_7(i-3,j+3,0)+average_7(i-2,j-3,0)+average_7(i-2,j-2,0)+average_7(i-2,j-1,0)+average_7(i-2,j,0)+average_7(i-2,j+1,0)+average_7(i-2,j+2,0)+average_7(i-2,j+3,0)+average_7(i-1,j-3,0)+average_7(i-1,j-2,0)+average_7(i-1,j-1,0)+average_7(i-1,j,0)+average_7(i-1,j+1,0)+average_7(i-1,j+2,0)+average_7(i-1,j+3,0)+average_7(i,j-3,0)+average_7(i,j-2,0)+average_7(i,j-1,0)+average_7(i,j,0)+average_7(i,j+1,0)+average_7(i,j+2,0)+average_7(i,j+3,0)+average_7(i+1,j-3,0)+average_7(i+1,j-2,0)+average_7(i+1,j-1,0)+average_7(i+1,j,0)+average_7(i+1,j+1,0)+average_7(i+1,j+2,0)+average_7(i+1,j+3,0)+average_7(i+2,j-3,0)+average_7(i+2,j-2,0)+average_7(i+2,j-1,0)+average_7(i+2,j,0)+average_7(i+2,j+1,0)+average_7(i+2,j+2,0)+average_7(i+2,j+3,0)+average_7(i+3,j-3,0)+average_7(i+3,j-2,0)+average_7(i+3,j-1,0)+average_7(i+3,j,0)+average_7(i+3,j+1,0)+average_7(i+3,j+2,0)+average_7(i+3,j+3,0))/49;
    }
  }

  string output_file_7 = "average-AJG23001-3.pgm";
  if (!average_7.write("average-AJG23001-7.pgm")) { //各画素値の書き出し
    std::cerr << "cannot write the file!: average_7.pgm" << std::endl;
    exit(-1);
  }

  return 0;
}


