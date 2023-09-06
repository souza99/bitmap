
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#include "libs/bitmap/bitmap_image.hpp"

using namespace std;
int main()
{
//http://www.partow.net/programming/bitmap/index.html
    string file_name("imagens/comida1.bmp");

    bitmap_image image(file_name);

    if (!image)
    {
        printf("test01() - Error - Failed to open '%s'\n", file_name.c_str());
        return 1;
    }
    
	// set background to orange
	image.set_all_channels(255, 150, 50);

	image_drawer draw(image);
	
	rgb_t color;
	
	image.get_pixel(0, 0, color);

	cout << static_cast<unsigned>(color.red) << endl;
	cout << (unsigned)color.blue << endl;
	cout << (unsigned)color.green << endl;
	draw.pen_width(1);
	draw.pen_color(255, 150, 51);
	draw.rectangle(1, 0, 1, 0);
	

	image.save_image("output.bmp");

    image.save_image("comida2.bmp");
    
    return 0;
}
