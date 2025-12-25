#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


int main() {

    int fd = open("./IO.md", O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    char buff[1000]; // Increased size for null terminator

    ssize_t length = read(fd, buff, 1000 - 1);

    if (length > 0) {
        buff[length] = '\0';
        printf("%s", buff);
    } else if (length == -1) {
        perror("read");
    }

    close(fd);
}

