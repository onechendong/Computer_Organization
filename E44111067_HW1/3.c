#include<stdio.h>
int main()
{ 
    int f, i, j;
    int h[9] = {0}, x[6] = {0}, y[6] = {0}; 
    FILE *input = fopen("../input/3.txt", "r");
    for(i = 0; i < 9; i++) fscanf(input, "%d", &h[i]);
    for(i = 0; i < 6; i++) fscanf(input, "%d", &x[i]);
    for(i = 0; i < 6; i++) fscanf(input, "%d", &y[i]);
    fclose(input);
    int *p_x = &x[0] ;
    int *p_h = &h[0] ;
    int *p_y = &y[0] ;
    for (i = 0; i < 3; i++){ 
        for (j = 0; j < 2; j++){        	
            for (f = 0; f < 3; f++){
                asm volatile(
			"mul %[tmp], %[h], %[x]\n\t"	//tmp=h*x
			"add %[tmp], %[tmp], %[y]\n\t"	//tmp+=y
			"mv %[y], %[tmp]\n\t"	//move tmp back to y
                   	: [tmp] "+r" (y[i*2+j])
                   	: [h] "r" (h[i*3+f]), [x] "r" (x[f*2+j]), [y] "r" (y[i*2+j])
                );
            }
	}
    }
    p_y = &y[0];
    for(i = 0; i < 6; i++)
    printf("%d ", *p_y++);
    printf("\n");
    return 0; 
 
}
