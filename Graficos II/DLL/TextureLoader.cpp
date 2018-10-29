#include "TextureLoader.h"
#include <GL\glew.h>
#include <fstream>
#include <iostream>

TextureLoader::TextureLoader()
{
}

TextureLoader::~TextureLoader()
{
}

unsigned int TextureLoader::loadBMP(const char * imagepath)
{
	FILE * file;
	fopen_s(&file, imagepath, "rb");
	if (!file) 
	{
		printf("Image could not be opened\n"); 
		return 0; 
	}

	if (fread(info.header, 1, 54, file) != 54) { // If not 54 bytes read : problem
		printf("Not a correct BMP file\n");
		return false;
	}

	if (info.header[0] != 'B' || info.header[1] != 'M') {
		printf("Not a correct BMP file\n");
		return 0;
	}

	// Lectura de los enteros desde el arreglo de bytes
	info.dataPos = *(int*)&(info.header[0x0A]);
	info.imageSize = *(int*)&(info.header[0x22]);
	info.width = *(int*)&(info.header[0x12]);
	info.height = *(int*)&(info.header[0x16]);

	// Algunos archivos BMP tienen un mal formato, así que adivinamos la información faltante
	if (info.imageSize == 0)    
		info.imageSize = info.width * info.height * 3; // 3 : un byte por cada componente Rojo (Red), Verde (Green) y Azul(Blue)
	if (info.dataPos == 0)
		info.dataPos = 54; // El encabezado del BMP está hecho de ésta manera

	// Se crea un buffer
	info.data = new unsigned char[info.imageSize];

	// Leemos la información del archivo y la ponemos en el buffer
	fread(info.data, 1, info.imageSize, file);

	//Todo está en memoria ahora, así que podemos cerrar el archivo
	fclose(file);

	// Se Crea una textura OpenGL
	unsigned int textureID;
	glGenTextures(1, &textureID);

	// Se "Ata" la nueva textura : Todas las futuras funciones de texturas van a modificar esta textura
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Se le pasa la imagen a OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, info.width, info.height, 0, GL_BGR, GL_UNSIGNED_BYTE, info.data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	std::cout << "La textura se ah cargado" << std::endl;

}