"li t3, -1 \n\t"

"li t1, 0 \n\t"	//t1=i=0
"addi %[lw_cnt], %[lw_cnt], 2 \n\t"
"fcvt.d.l f1, t3\n\t"
"addi %[others_cnt], %[others_cnt], 1 \n\t"
"loop_i: \n\t"

	"add t2, t1, t1 \n\t" //t2=2*i
	"addi %[add_cnt], %[add_cnt], 1 \n\t"
	
	"addi t2, t2, 1 \n\t" //t2=2*i+1
	"addi %[add_cnt], %[add_cnt], 1 \n\t"

	"fneg.d f1, f1 \n\t" 
	"fcvt.d.l f2, t2 \n\t"
	"fdiv.d f2, f1, f2 \n\t"
	"addi %[others_cnt], %[others_cnt], 2 \n\t"
	"addi %[div_cnt], %[div_cnt], 1 \n\t"
	
	"fadd.d %[pi], %[pi], f2 \n\t"
	"addi %[add_cnt], %[add_cnt], 1 \n\t"

	"addi t1, t1, 1 \n\t"	//i++
	"addi %[add_cnt], %[add_cnt], 1 \n\t"
	
	"addi %[others_cnt], %[others_cnt], 1 \n\t"
	"bne t1, %[N], loop_i \n\t"
