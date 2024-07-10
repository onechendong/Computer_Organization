"loop_i: \n\t"

    "lh t0, 0(%[h]) \n\t"
    "lh t1, 0(%[x]) \n\t"
    "addi %[lw_cnt], %[lw_cnt], 2 \n\t"

    "mul t0, t0, t1 \n\t"
    "addi %[mul_cnt], %[mul_cnt], 1 \n\t"

    "add t0, t0, %[id] \n\t"
    "addi %[add_cnt], %[add_cnt], 1 \n\t"

    "sh t0, 0(%[y]) \n\t"
    "addi %[sw_cnt], %[sw_cnt], 1 \n\t"


    "addi %[h], %[h], 2 \n\t"
    "addi %[x], %[x], 2 \n\t"
    "addi %[y], %[y], 2 \n\t"
    "addi %[add_cnt], %[add_cnt], 4 \n\t"

	"addi %[arr_size], %[arr_size], -1 \n\t"

    "addi %[others_cnt], %[others_cnt], 1 \n\t"
	
	"bne x0, %[arr_size], loop_i \n\t"