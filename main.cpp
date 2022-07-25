#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include<netinet/in.h>

uint32_t add(uint32_t *x, uint32_t *y){
    return (*x + *y);
}

uint32_t read_file(char *fname) {
    FILE *fp = fopen(fname, "r");

    uint32_t num;

    fread(&num, 1, sizeof(uint32_t), fp);

    num = ntohl(num);

    fclose(fp);
    return num;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("syntax : add-nbo <file1> <file2>\n");
        printf("sample : add-nbo a.bin c.bin\n");
        return -1;
    }

    uint32_t x = read_file(argv[1]);
    uint32_t y = read_file(argv[2]);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", x, x, y, y, add(&x, &y), add(&x, &y));
}
