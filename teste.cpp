
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <array>

#include "libs/bitmap/bitmap_image.hpp"

using namespace std;

template <typename T>
inline T extract_bits (const T v, const unsigned bstart, const unsigned blength) {
	const T mask = (1 << blength) - 1;

	return ((v >> bstart) & mask);
}

template <typename T>
inline T set_bits (const T v, const unsigned bstart, const unsigned blength, const T bits) {
	const T mask = ((1 << blength) - 1) << bstart; 

	return (v & ~mask) | (bits << bstart);
}

array<int, 3> cores_pintadas(bitmap_image imagem, int linha, int coluna) {
	array<int, 3> cores;
	rgb_t color = imagem.get_pixel(coluna, linha);
	
	cores[0] = static_cast<unsigned>(color.red);
	cores[1] = static_cast<unsigned>(color.green);
	cores[2] = static_cast<unsigned>(color.blue);
	
	return cores;
}


int main()
{
//http://www.partow.net/programming/bitmap/index.html
	//unsigned x = 0;
	//x = set_bits(x, 1, 2, static_cast<unsigned>(0x03));
	//cout << x << endl;
	//return 0;
	
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

	image2.set_pixel(2, 0, cores[0], cores[1], (cores[2] >= 255) ? cores[2]-1 : cores[2]+1);
	
	color = image2.get_pixel(2, 0);
	
	int pixel = 0;
	int largura = 40;
	string texto = "Inicial";
	
	// estraindo os bites da nossa mensagem
	bool bit = extract_bits(static_cast<unsigned char>(caracter), 0, 1);
	
	for (int caracter_mensagem = 0; caracter_mensagem <= texto.size(); caracter_mensagem++) {
		// estraindo os bites da nossa mensagem
		char caracter = texto[caracter_mensagem];
		
		for (int bit_caracter = 0; bit_caracter <= 8; bit_caracter++) {
			bool bit = extract_bits(static_cast<unsigned char>(caracter), bit_caracter, 1);
			
			if(pixel >= image2.width()) {
				int linha = static_cast<int>(pixel/image2.width());
				int coluna = pixel % image2.width();
				auto cores = cores_pintadas(image2, linha, coluna);
				image2.set_pixel(coluna, linha, cores[0], cores[1], (cores[2] >= 255) ? cores[2]-1 : cores[2]+1);
			}
			else {
				auto cores = cores_pintadas(image2, 0, pixel);
				image2.set_pixel(pixel, 0, cores[0], cores[1], (cores[2] >= 255) ? cores[2]-1 : cores[2]+1);
			}
			
			pixel++;
		}
	}

	cout << static_cast<unsigned>(color.red) << endl;
	cout << static_cast<unsigned>(color.green) << endl;
	cout << static_cast<unsigned>(color.blue) << endl;
	
	return 0;
}



