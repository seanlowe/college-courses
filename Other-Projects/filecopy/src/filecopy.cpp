#include <iostream>
#include <cstdio>

int main() {
    char buf[BUFSIZ];
    size_t size;
    size_t size2;
    FILE* source = fopen("src/pic.jpg","rb");
    FILE* source2 = fopen("src/pic2.jpg","rb");
    FILE* dest = fopen("bin/copy.jpg","wb");
    while(size = fread(buf,1,BUFSIZ,source)) {
        fwrite(buf,1,size,dest);
    }
    while(size2 = fread(buf,1,BUFSIZ,source2)) {
        fwrite(buf,1,size2,dest);
    }
    fclose(source);
    fclose(source2);
    fclose(dest);
    return 0;
}