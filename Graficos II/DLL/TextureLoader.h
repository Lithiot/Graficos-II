#pragma once
#include "Exports.h"

struct InfoBMP
{
	unsigned char header[54];
	unsigned int dataPos;
	unsigned int width, height;
	unsigned int imageSize;
	unsigned char  * data;
};

class ENGINE_API TextureLoader
{
private:
	InfoBMP info;
public:
	TextureLoader();
	~TextureLoader();
	unsigned int loadBMP(const char * imagepath);
};

