void matrix_multiplication(int *a, int *b, int *output, int i,
                           int k, int j) {
    for (int x = 0; x < i; x+=4) {
        for (int y = 0; y < j; y+=2) {
            int sum[8] = {0};
            for (int z = 0; z < k; z++) {
                //sum += a[x * k + z] * b[z * j + y];
                sum[0] += a[(x+0) * k + z] * b[z * j + (y+0)];
                sum[1] += a[(x+0) * k + z] * b[z * j + (y+1)];
                sum[2] += a[(x+1) * k + z] * b[z * j + (y+0)];
                sum[3] += a[(x+1) * k + z] * b[z * j + (y+1)];
                sum[4] += a[(x+2) * k + z] * b[z * j + (y+0)];
                sum[5] += a[(x+2) * k + z] * b[z * j + (y+1)];
                sum[6] += a[(x+3) * k + z] * b[z * j + (y+0)];
                sum[7] += a[(x+3) * k + z] * b[z * j + (y+1)];
            }
            //output[x * j + y] = sum;
            output[(x+0) * j + (y+0)] = sum[0];
            output[(x+0) * j + (y+1)] = sum[1];
            output[(x+1) * j + (y+0)] = sum[2];
            output[(x+1) * j + (y+1)] = sum[3];
            output[(x+2) * j + (y+0)] = sum[4];
            output[(x+2) * j + (y+1)] = sum[5];
            output[(x+3) * j + (y+0)] = sum[6];
            output[(x+3) * j + (y+1)] = sum[7];
        }
    }
    return;
}