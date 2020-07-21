#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t file_read(char* fileName){
    uint32_t ret;
    FILE* file = fopen(fileName, "rb");
    if(fread(&ret, 1, sizeof(uint32_t), file) == 0){
        fclose(file);
        printf("Error\n");
        exit(1);
    }
    fclose(file);

    return ret;
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 0;
    }
    uint32_t ret, ret1, ret2;

    ret1 = file_read(argv[1]);
    ret2 = file_read(argv[2]);

    ret1 = ntohl(ret1);
    ret2 = ntohl(ret2);

    ret = ret1 + ret2;

    printf("%d(0x%2x) + %d(0x%2x) = %d(0x%2x)\n", ret1, ret1, ret2, ret2, ret, ret);

    return 0;
}
