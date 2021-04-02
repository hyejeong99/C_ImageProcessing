#include <stdio.h>
#include <Windows.h>
#define WIDTHBYTES(bits) (((bits)+31)/32*4)//영상 가로길이는 4바이트의 배수여야 함
#define BYTE unsigned char 

void main() {
	errno_t err;//에러 받기
	FILE *outfile;
	typedef struct tagBITMAPINFOHEADER {
		DWORD      biSize = 40;          //영상 정보 헤더의 크기(40byte)
		LONG       biWidth=256;          //영상의 가로 픽셀 수
		LONG       biHeight=256;         //영상의 세로 픽셀 수
		WORD       biPlanes=1;
		WORD       biBitCount=8;       //픽셀 당 비트 수로 회색조 영상의 경우 8, rgb 트루 컬러일 경우 24(1,4,8,16,24,32중 하나)
		DWORD      biCompression=0;    //압축 타입으로 비트맵의 경우 보통 BI_RGB(0)이다.
		DWORD      biSizeImage=256*256;      //영상 데이터의 크기
		LONG       biXPelsPerMeter=0;
		LONG       biYPelsPerMeter=0;
		DWORD      biClrUsed=256;
		DWORD      biClrImportant=256;
	} BITMAPINFOHEADER ;
	typedef struct tagRGBQUAD {
		BYTE    rgbBlue;
		BYTE    rgbGreen;
		BYTE    rgbRed;
		BYTE    rgbReserved;  //사용X
	} RGBQUAD;
	typedef struct tagBITMAPFILEHEADER {
		WORD    bfType = 0x4D42;//String 'BM'
		DWORD   bfSize = 14;
		WORD    bfReserved1;
		WORD    bfReserved2;
		DWORD   bfOffBits;
	} BITMAPFILEHEADER;

	BITMAPFILEHEADER hf;//파일헤더
	BITMAPINFOHEADER hInfo;//영상헤더
	RGBQUAD hRGB[256];//팔레트 정보
	
	// 영상데이타를 저장할 메모리 할당
	int rwsize = WIDTHBYTES(hInfo.biBitCount*hInfo.biWidth);
	BYTE *lpImg = new BYTE[hInfo.biSizeImage];
	int i, j;

	//영상
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


	//영상 출력
	err = fopen_s(&outfile, "sample image.bmp", "wb");
	fwrite(&hf, sizeof(char), sizeof(BITMAPFILEHEADER), outfile);
	fwrite(&hInfo, sizeof(char), sizeof(BITMAPINFOHEADER), outfile);
	fwrite(hRGB, sizeof(RGBQUAD), 256, outfile);
	fwrite(lpImg, sizeof(char), hInfo.biSizeImage, outfile);
	fclose(outfile);

	// 메모리 해제
	delete[]lpImg;
}