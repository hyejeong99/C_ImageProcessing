#include <stdio.h>
#include <Windows.h>
#define WIDTHBYTES(bits) (((bits)+31)/32*4)//���� ���α��̴� 4����Ʈ�� ������� ��
#define BYTE unsigned char 

void main() {
	errno_t err;//���� �ޱ�
	FILE *outfile;
	typedef struct tagBITMAPINFOHEADER {
		DWORD      biSize = 40;          //���� ���� ����� ũ��(40byte)
		LONG       biWidth=256;          //������ ���� �ȼ� ��
		LONG       biHeight=256;         //������ ���� �ȼ� ��
		WORD       biPlanes=1;
		WORD       biBitCount=8;       //�ȼ� �� ��Ʈ ���� ȸ���� ������ ��� 8, rgb Ʈ�� �÷��� ��� 24(1,4,8,16,24,32�� �ϳ�)
		DWORD      biCompression=0;    //���� Ÿ������ ��Ʈ���� ��� ���� BI_RGB(0)�̴�.
		DWORD      biSizeImage=256*256;      //���� �������� ũ��
		LONG       biXPelsPerMeter=0;
		LONG       biYPelsPerMeter=0;
		DWORD      biClrUsed=256;
		DWORD      biClrImportant=256;
	} BITMAPINFOHEADER ;
	typedef struct tagRGBQUAD {
		BYTE    rgbBlue;
		BYTE    rgbGreen;
		BYTE    rgbRed;
		BYTE    rgbReserved;  //���X
	} RGBQUAD;
	typedef struct tagBITMAPFILEHEADER {
		WORD    bfType = 0x4D42;//String 'BM'
		DWORD   bfSize = 14;
		WORD    bfReserved1;
		WORD    bfReserved2;
		DWORD   bfOffBits;
	} BITMAPFILEHEADER;

	BITMAPFILEHEADER hf;//�������
	BITMAPINFOHEADER hInfo;//�������
	RGBQUAD hRGB[256];//�ȷ�Ʈ ����
	
	// ������Ÿ�� ������ �޸� �Ҵ�
	int rwsize = WIDTHBYTES(hInfo.biBitCount*hInfo.biWidth);
	BYTE *lpImg = new BYTE[hInfo.biSizeImage];
	int i, j;

	//����
	for (i = 0; i < 64; i++) {
		for (j = 0; j < hInfo.biWidth; j++) {
			lpImg[i*rwsize + j] = 255;
		}
	}
	for (i = 64; i < 128; i++) {
		for (j = 0; j < hInfo.biWidth; j++) {
			lpImg[i*rwsize + j] = 192;
		}
	}
	for (i = 128; i < 192; i++) {
		for (j = 0; j < hInfo.biWidth; j++) {
			lpImg[i*rwsize + j] = 64;
		}
	}
	for (i = 192; i < hInfo.biWidth; i++) {
		for (j = 0; j < hInfo.biWidth; j++) {
			lpImg[i*rwsize + j] = 0;
		}
	}


	//���� ���
	err = fopen_s(&outfile, "sample image.bmp", "wb");
	fwrite(&hf, sizeof(char), sizeof(BITMAPFILEHEADER), outfile);
	fwrite(&hInfo, sizeof(char), sizeof(BITMAPINFOHEADER), outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(lpImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);

	// �޸� ����
	delete[]lpImg;
}