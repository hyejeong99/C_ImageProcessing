#include <stdio.h>

void main() {
	//gray-scale ���� ����

	int i, j;
	unsigned char OrgImg[256][256];
	errno_t err;//���� �ޱ�
	FILE *infile, *outfile;

	// �������� ���� ����ó��
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

	// �ϵ��ũ�� �������� ����
	err = fopen_s(&outfile, "sample image.raw", "wb");
	fwrite(OrgImg, sizeof(char), 256 * 256, outfile);
	fclose(outfile);

}