#include "TextureLoader.h"

InfoBMP TextureLoader::LoadBMP(const char* imagePath)
{
	unsigned char header[54];
	InfoBMP bmph;
	FILE * file;
	fopen_s(&file, imagePath, "rb");
	
	if (RightBMPFormat(header, file))
	{
		bmph.dataPos = *(int*)&(header[0x0A]);
		bmph.imageSize = *(int*)&(header[0x22]);
		bmph.width = *(int*)&(header[0x12]);
		bmph.height = *(int*)&(header[0x16]);
	}

	if (bmph.imageSize == 0)    
		bmph.imageSize = bmph.width * bmph.height * 3;
	if (bmph.dataPos == 0)
		bmph.dataPos = 54;
	bmph.data = new unsigned char[bmph.imageSize];
	fread(bmph.data, 1, bmph.imageSize, file);
	fclose(file);
	return bmph;
}


bool TextureLoader::RightBMPFormat(unsigned char  BMPheader[], FILE * BMPfile)
{
	if (!BMPfile)
	{
		printf("Image could not be opened\n");
		return 0;
	}

	if (fread(BMPheader, 1, 54, BMPfile) != 54)
	{
		printf("Not a correct BMP file\n");
		return false;
	}

	if (BMPheader[0] != 'B' || BMPheader[1] != 'M') 
	{
		printf("Not a correct BMP file\n");
		return 0;
	}
}