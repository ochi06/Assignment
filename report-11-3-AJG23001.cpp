//AJG23001 asuka ochiai

#include <iostream>
#include <cmath>
#include "ex2image.h"

int main(int argc, const char * argv[])
{
    ex2image img;
    std::string s_file = "block.pgm";
    if( !img.load( s_file.c_str() ) ){
    std::cerr << "cannot open the file!:" <<  s_file << std::endl;
    exit( -1 );
  }

  //保存用の画像のバッファ
    ex2image mag( img );

  //画像を反転させる
  int w = mag.img_width();
  int h = mag.img_height();
  for( int j=1; j<h-1; j++ ){
    for( int i=1; i<w-1; i++ ){
      double x=img(i-1,j-1,0)*(-1)+img(i-1,j,0)*(-2)+img(i-1,j+1,0)*(-1)+img(i+1,j-1,0)*1+img(i+1,j,0)*2+img(i+1,j+1,0)*1;
      double y=img(i-1,j-1,0)*1+img(i,j-1,0)*2+img(i+1,j-1,0)*1+img(i-1,j+1,0)*(-1)+img(i,j+1,0)*(-2)+img(i+1,j+1,0)*(-1);
      double e=sqrt(x*x+y*y);
      if(e>255){
        e=255;
      }else if(e<0){
        e=0;
      }
    mag( i, j, 0 ) = e;
    }
  }

    if( !mag.write( "mag.pgm" ) ){
    std::cerr << "cannot write the file!: mag.pgm" << std::endl;
    exit( -1 );
  } 

    return 0;
}

