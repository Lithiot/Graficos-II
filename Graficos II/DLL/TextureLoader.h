#pragma once
#include "Exports.h" 
#include <stdio.h>
#include <stdlib.h>

struct InfoBMP
{
	unsigned int dataPos;
	unsigned int width, height;
	unsigned int imageSize;
	unsigned char* data;
};

static class ENGINE_API TextureLoader
{
public:
	static InfoBMP LoadBMP(const char* BMPname);
	static bool RightBMPFormat(unsigned char  BMPheader[], FILE * BMPfile);
};

