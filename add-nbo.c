#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Usage: ./add-nbo <file1> <file2>\n");
        return 0;
    }

    FILE * file1 = fopen(argv[1], "rb");
    FILE * file2 = fopen(argv[2], "rb");

    uint32_t buf, buf2, temp, temp2,ret;

    fread(&buf, sizeof(uint32_t), 1, file1);
    fread(&buf2, sizeof(uint32_t), 1, file2);

    temp = htonl(buf);
    temp2 = htonl(buf2);
    ret = temp + temp2;

    printf("%d(0x%2x) + %d(0x%2x) = %d(0x%2x)\n", temp, temp, temp2, temp2, ret, ret);

    fclose(file2);
    fclose(file1);

    return 0;
}
