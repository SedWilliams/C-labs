#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

//declare a metadata struct
struct stat metadata;

int main() {

    //open file as read only
    int fd = open("./IO.md", O_RDONLY);

    if(fstat(fd, &metadata) == -1) {
        printf("Error reading file metadata");
    }
    
    //buffer for file contents
    char buff[metadata.st_size+1];

    //read file 'fd' into 'buf'
    ssize_t read_amt = read(fd, buff, metadata.st_size+1);

    printf("Read %lu bytes\n", metadata.st_size+1);
    printf("File contents:\n%s", buff);

    //close 'fd'
    close(fd);

    return 0;
}

