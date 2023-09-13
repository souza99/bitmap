
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
    
	image_drawer draw(image);
	
	rgb_t color = image.get_pixel(2, 0);

	unsigned cores[3];
	
	color = image.get_pixel(2, 0);

	image.save_image("output.bmp");

    image.save_image("comida2.bmp");
    
    bitmap_image image2("output.bmp");
    
    color = image2.get_pixel(2, 0);
    
    cores[0] = static_cast<unsigned>(color.red);
	cores[1] = static_cast<unsigned>(color.green);
	cores[2] = static_cast<unsigned>(color.blue);
	
	cout << cores[0] << endl;
	cout << cores[1] << endl;
	cout << cores[2] << endl;

    image2.set_pixel(2, 0, cores[0], cores[1], cores[2]+1);

    color = image2.get_pixel(2, 0);
    
    int i = 0;
	int tamanho = 40;
    
    //while(i <= tamanho) {}
    
    for (int i = 0; i <= tamanho; i++) {
    	if(i >= image2.height()) {
    		int tamanho_novo = tamanho - i;
    	}
    }

    cout << static_cast<unsigned>(color.red) << endl;
    cout << static_cast<unsigned>(color.green) << endl;
    cout << static_cast<unsigned>(color.blue) << endl;
    
    return 0;
}
