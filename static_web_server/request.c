#include <unistd.h>
#include <stdio.h>
#include <string.h>

//example request:
//GET /blog HTTP/1.1

// goal output (strip everything and construct file path):
// blog/index.html

char *to_path(char *req);
// char *get_request_type(char *req);

int main() {

    char req[] = "GET /blog HTTP/1.1";
    // char *req_type = get_request_type(req);
    char *path = to_path(req);

    // printf("Req type: %s", req_type);
    printf("Path: %s\n", path);

    return 0;
}

/*
char *get_request_type(char *req) {
    char *start = req;

    while(start[0] != ' ') {

        //all equivalent: checks for end of given string.
        //      Stops loop from traversing out of bounds memory
        //      early return
        if (start[0] == '\0') { return NULL; }
        if (start[0] == 0) { return NULL; }
        if (!start[0]) { return NULL; }
    }
   

    //set the space after the request type to a null terminator, closing the string
    start[0] = 0;
    return start;
}
*/

//This function mutates the passed req, which contrary to my intuition is MORE efficient
//      than building a new string and returning that string
char *to_path(char *req) {

    //NOTE:
    //      When incrementing the start and end values
    //      and not indexing them, we are accessing the pointer
    //      and incrementing THAT value, not the value found
    //      at the memory address that pointer points to

    char *start;
    char *end;

    const char *default_file = "index.html";
    
    //skip the operation (GET, POST, DELETE, etc..) stops when encountering ' '
    for(start = req; start[0] != ' '; start++) {

        //all equivalent: checks for end of given string.
        //      Stops loop from traversing out of bounds memory
        //      early return
        if (start[0] == '\0') { return NULL; }
        if (start[0] == 0) { return NULL; }
        if (!start[0]) { return NULL; }
    }
    
    //prev loop stops at the ' ' and we want to throw that value away
    //      so we do a start++ to skip it.
    start++;
    
    //traverses from 'start' until the end of the file segment of req header
    for(end = start; end[0] != ' '; end++) {
        if(end[0] == 0) { return NULL; }
    }
    
    //if there is an '/' at the end of the file path remove it
    //      we are going to manually add it so it is consistent
    if(end[-1] == '/') { 
        end--;
    } else {
        //manually add the slash
        end[0] = '/';
    }
    
    memcpy(end + 1, default_file, strlen(default_file) + 1);
    return start;
}


//example request:
//GET /blog HTTP/1.1

// goal output (strip everything and construct file path):
// blog/index.html
















