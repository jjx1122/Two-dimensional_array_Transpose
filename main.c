
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//矩阵转置
void Tranpose(int** p,int row,int col) {
	int** q = (int**)malloc(sizeof(int*) * col);
	for (int i = 0; i < col; i++) {
		q[i] = (int*)malloc(sizeof(int) * row);
	}
	for (int m = 0; m < row; m++) {
		for (int n = 0; n < col; n++) {
			q[n][m] = p[m][n];
		}
	}
	for (int m = 0; m < col; m++) {
		for (int n = 0; n < row; n++) {
			printf("%d ",q[m][n]);
		}
		printf("\n");
	}
	for (int i = 0; i < col; i++) {
		free(q[i]);
	}
	free(q);
}
int main() {
	int row = 0;
	int col = 0;
	printf("请输入矩阵的行数:");
	scanf("%d", &row);
	printf("请输入矩阵的列数:");
	scanf("%d", &col);
	srand((unsigned int)time(NULL));
	int** a=(int**)malloc(sizeof(int*) * row);//给二维数组分配(行数)个int *的空间,相当于每一行都是一个一维数组。
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		a[i] = (int*)malloc(sizeof(int) * col);//给各行分配列数个int空间。
		/*a[i] = new int[col];*/
	}
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			a[i][j] = rand() % 100+1;
		}
	}
	for (int k1 = 0; k1 < row; k1++) {
		for (int k2 = 0; k2 < col; k2++) {
			printf("%d ", a[k1][k2]);
		}
		printf("\n");
	}
	//矩阵转置
	Tranpose(a,row,col);
	//释放空间。
	for (i = 0; i < row; i++) {
		free(a[i]);
	}
	free(a);
	return 0;
}
