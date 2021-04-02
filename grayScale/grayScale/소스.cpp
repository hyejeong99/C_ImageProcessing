#include <stdio.h>

void main() {
	//gray-scale 영상 생성

	int i, j;
	unsigned char OrgImg[256][256];
	errno_t err;//에러 받기
	FILE *infile, *outfile;

	// 역상계산을 위한 영상처리
	for (i = 0; i < 64; i++) {
		for (j = 0; j < 256; j++) {
			OrgImg[i][j] = 0;
		}
	}
	for (i = 64; i < 128; i++) {
		for (j = 0; j < 256; j++) {
			OrgImg[i][j] = 64;
		}
	}
	for (i = 128; i < 192; i++) {
		for (j = 0; j < 256; j++) {
			OrgImg[i][j] = 192;
		}
	}
	for (i = 192; i < 256; i++) {
		for (j = 0; j < 256; j++) {
			OrgImg[i][j] = 255;
		}
	}

	// 하드디스크에 영상데이터 쓰기
	err = fopen_s(&outfile, "sample image.raw", "wb");
	fwrite(OrgImg, sizeof(char), 256 * 256, outfile);
	fclose(outfile);

}