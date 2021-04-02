#include <stdio.h>

void main() {
	//color image 생성

	int i, j;
	unsigned char OrgImg[256][256];
	unsigned char R[256][256], G[256][256], B[256][256];
	errno_t err;//에러 받기
	FILE *infile, *outfile;
	
	// 역상계산을 위한 영상처리
	for (j = 0; j < 256; j++) {
		for (i = 0; i < 64; i++) {
			R[i][j] = 255;
			G[i][j] = 0;
			B[i][j] = 0;
		}
		for (i = 64; i < 128; i++) {
			R[i][j] = 0;
			G[i][j] = 255;
			B[i][j] = 0;
		}
		for (i = 128; i < 192; i++) {
			R[i][j] = 0;
			G[i][j] = 0;
			B[i][j] = 255;
		}
		for (i = 192; i < 256; i++) {
			R[i][j] = 0;
			G[i][j] = 0;
			B[i][j] = 0;
		}
	}

	// 하드디스크에 영상데이터 쓰기
	err = fopen_s(&outfile, "sample color image.raw", "wb");
	fwrite(R, sizeof(char), 256 * 256, outfile);
	fwrite(G, sizeof(char), 256 * 256, outfile);
	fwrite(B, sizeof(char), 256 * 256, outfile);
	fclose(outfile);

}