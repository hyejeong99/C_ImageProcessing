#include <stdio.h>

void main() {

	int i, j;
	unsigned char OrgImg[256][256];
	errno_t err;//���� �ޱ�
	FILE *infile, *outfile;


	// ��ũ���� �������� �б�
	err = fopen_s(&infile,"coin.raw", "rb");
	if (err!=0) { printf("File open error!!"); return; }
	fread(OrgImg, sizeof(char), 256 * 256, infile);
	fclose(infile);

	// �������� ���� ����ó��
	for (i = 0; i < 256; i++) {
		for (j = 0; j < 256; j++) {
			OrgImg[i][j] = 255 - OrgImg[i][j];
		}
	}

	// �ϵ��ũ�� �������� ����
	err = fopen_s(&outfile,"coin_inv.raw", "wb");
	fwrite(OrgImg, sizeof(char), 256 * 256, outfile);
	fclose(outfile);

}