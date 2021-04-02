#include <stdio.h>

void main() {

	int i, j;
	unsigned char OrgImg[256][256];
	errno_t err;//에러 받기
	FILE *infile, *outfile;


	// 디스크에서 영상데이터 읽기
	err = fopen_s(&infile,"coin.raw", "rb");
	if (err!=0) { printf("File open error!!"); return; }
	fread(OrgImg, sizeof(char), 256 * 256, infile);
	fclose(infile);

	// 역상계산을 위한 영상처리
	for (i = 0; i < 256; i++) {
		for (j = 0; j < 256; j++) {
			OrgImg[i][j] = 255 - OrgImg[i][j];
		}
	}

	// 하드디스크에 영상데이터 쓰기
	err = fopen_s(&outfile,"coin_inv.raw", "wb");
	fwrite(OrgImg, sizeof(char), 256 * 256, outfile);
	fclose(outfile);

}