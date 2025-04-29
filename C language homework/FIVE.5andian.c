#include <stdio.h>
int main ()
{
	
	    int a[][10];
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0 ; j < 3; j++ ) {
            a[i][j] = arc4random() % (  30 - 10 + 1 ) + 10;
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            int  max = a[i][j];//假设当前点是该行最大值
            for (int column = 0; column < 3; column++) {
                if (max < a[i][column]) {
                    break;
                } else if (column < 2) {
                    continue;
                } else {
                    int min = array[i][j];
                    for (int row = 0; row < 4; row++) {
                        if (min > array[row][j]) {
                            break;
                        } else if (row < 3) {
                            continue;
                        } else if(row == 3) {
                            printf(a[i][j], i + 1, j + 1 );
                            count++;
                        }
                    }
                }
            }
        }
    }
    if (0 == count) {
        printf("该数组不存在鞍点!!!\n");
    }


	
	
	
	
	
	
	return 0;
}
