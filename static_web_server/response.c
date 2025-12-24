#include <unistd.h>
#include <string.h>

int main() {

    char* res = "HTTP/1.1 200 OK";

    write(1, res, strlen(res));

    return 0;
}




