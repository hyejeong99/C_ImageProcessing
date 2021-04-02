#include <stdio.h>
#include <Windows.h>
#define WIDTHBYTES(bits) (((bits)+31)/32*4)//���� ���α��̴� 4����Ʈ�� ������� ��
#define BYTE unsigned char 

void main()
{
	errno_t err;//���� �ޱ�
	FILE *infile, *outfile;

	//�������� �б�
	err = fopen_s(&infile, "talent.bmp", "rb");
	if (infile == NULL) { printf("There is no file!!!\n"); exit(1); }

	BITMAPFILEHEADER hf;
	fread(&hf, sizeof(BITMAPFILEHEADER), 1, infile); // �������
	if (hf.bfType != 0x4D42) exit(1); // String ��BM��
	
	BITMAPINFOHEADER hInfo;
	fread(&hInfo, sizeof(BITMAPINFOHEADER), 1, infile); // �������
	printf("Image Size: (%3dx%3d)\n", hInfo.biWidth, hInfo.biHeight);
	printf("Pallete Type: %dbit Colors\n", hInfo.biBitCount);
	
	// 8 ��Ʈ ��� ���� ó��
	if (hInfo.biBitCount != 8) { printf("Bad File format!!"); exit(1); }
	
	RGBQUAD hRGB[256];
	fread(hRGB, sizeof(RGBQUAD), 256, infile); // �ȷ�Ʈ�� ���Ͽ��� ����

	// ������Ÿ�� ������ �޸� �Ҵ�
	BYTE *lpImg = new BYTE[hInfo.biSizeImage];
	fread(lpImg, sizeof(char), hInfo.biSizeImage, infile);
	fclose(infile);

	// ������ �̹��� ���ϱ�
	int rwsize = WIDTHBYTES(hInfo.biBitCount*hInfo.biWidth);
	for (int i = 0; i < hInfo.biHeight; i++)
	{
		for (int j = 0; j < hInfo.biWidth; j++)
		{
			lpImg[i*rwsize + j] = 255 - lpImg[i*rwsize + j];
		}
	}

	//���� ���
	err = fopen_s(&outfile, "OutImg.bmp", "wb");
	fwrite(&hf, sizeof(char), sizeof(BITMAPFILEHEADER), outfile);
	fwrite(&hInfo, sizeof(char), sizeof(BITMAPINFOHEADER), outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(lpImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);

	// �޸� ����
	delete[]lpImg;

}