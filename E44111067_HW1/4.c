#include<stdio.h>
int main()
{ 
    int i = 0;
    int h[9] = {0}, x[6] = {0}, y[6] = {0}; 
    FILE *input = fopen("../input/4.txt", "r");
    for(i = 0; i < 9; i++) fscanf(input, "%d", &h[i]);
    for(i = 0; i < 6; i++) fscanf(input, "%d", &x[i]);
    for(i = 0; i < 6; i++) fscanf(input, "%d", &y[i]);
    fclose(input);
    
    int *p_x = &x[0];
    int *p_h = &h[0];
    int *p_y = &y[0];
    
    //t0:i
    //t1:j
    //t2:f
    asm volatile(
    	"li t0, 3\n\t"                // i=3
    	"loop_i:\n\t"                  // start loop_i
    	
    	"    li t1, 2\n\t"            // j=2
    	"    loop_j:\n\t"              // start loop_j
    	
    	"        li t2, 3\n\t"        // f=3
    	"        loop_f:\n\t"         // start loop_f
    	
    			//t3:x	t4:h	t6:y
			"lw t3,0(%[x])\n\t"   
			"lw t4,0(%[h])\n\t"
			"lw t6,0(%[y])\n\t"
			"mul t4,t4,t3\n\t"	//h=h*x
			"add t6,t6,t4\n\t"	//y=h*x
			"sw t6,0(%[y])\n\t"
			"addi %[x],%[x],8\n\t"
			"addi %[h],%[h],4\n\t" 
			"li t5,1\n\t"
			"beq t2,t5,nextY\n\t"
			"j end_label\n\t"
			"nextY:\n\t"
			"addi %[y],%[y],4\n\t"
			"addi %[h],%[h],-12\n\t"
			"beq t1,t5,nextX\n\t"
			"addi %[x],%[x],-20\n\t"
			"j end_label\n\t"
			"nextX:\n\t"
			"addi %[h],%[h],12\n\t"
			"addi %[x],%[x],-28\n\t"
			"end_label:\n\t"

    	"          addi t2, t2, -1\n\t"  // f--
    	"          bnez t2, loop_f\n\t"  // when f!=0, keep run loop_f
    	
    	"     addi t1, t1, -1\n\t"      // j--
    	"     bnez t1, loop_j\n\t" // when j!=0, keep run loop_j
  
    	" addi t0, t0, -1\n\t"         // i--
    	" bnez t0, loop_i\n\t"    // when i!=0, keep run loop_i
    	
    	: [h] "+r" (p_h), [x] "+r" (p_x), [y] "+r" (p_y)
    	:
    	: "t0", "t1", "t2", "t3", "t4", "t5", "t6" 
    );

    p_y = &y[0];
    for(i = 0; i < 6; i++)
        printf("%d ", *p_y++);
    printf("\n");
    return 0; 
 
}
