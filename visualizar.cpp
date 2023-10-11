#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>
#include <array>
#include <vector>

#include "libs/bitmap/bitmap_image.hpp"

using namespace std;

string PALAVRA_CHAVE = "´^`";

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

bool comparar_pixel_imagens(const rgb_t cor_imagem_original, const rgb_t cor_imagem_modificada) {
	if (cor_imagem_original.blue == cor_imagem_modificada.blue) {
		return 0;
	}
	
	return 1;
}

string transformar_binario_em_char(vector<bool>& mensagem_em_binario) {
	string mensagem;
	unsigned char c;
	
	for(int i = 0; i < mensagem_em_binario.size(); i++ ) {
		int posicao = i % 8;
		
		if(posicao == 0) {
			if(i > 0) {
				mensagem += c;
			}
			c = 0;
		}
		c = set_bits(c, posicao, 1, static_cast<unsigned char>(mensagem_em_binario[i])); 
		
		if (mensagem.ends_with(PALAVRA_CHAVE)) {
			string mensagem_convertida = replace(-3, PALAVRA_CHAVE.size(), "")
			mensagem = mensagem_convertida;
			break;
		}
	}
	
	return mensagem;
}

string comparar_imagens() {
	string file_name("imagens/comida1.bmp");

	bitmap_image imagem_original(file_name);
	
	bitmap_image imagem_modificada("output.bmp");
	
	vector<bool> mensagem_em_binario;
	
	string mensagem;
	
	for (int linha = 0; linha < imagem.height(); linha++) {
		for (int coluna = 0; coluna < imagem.width(); coluna++) {
			rgb_t cor_imagem_original = imagem_original.get_pixel(coluna, linha);
			rgb_t cor_imagem_modificada = imagem_modificada.get_pixel(coluna, linha);
			mensagem_em_binario.insert(comparar_pixel_imagens(cor_imagem_original, cor_imagem_modificada));
		}
	}
	
	mensagem.insert(transformar_binario_em_char(mensagem_em_binario));
	
}

void mostrar_mensagem() {
	string mensagem;
	
	bitmap_image imagem("output.bmp");
	
	mensagem = comparar_imagens();
	
	
	cout << mensagem << endl;
	
}

int main() {

	mostrar_mensagem();

	return 0;
}
