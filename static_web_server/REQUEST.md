
# Request.c

## What I learned/problems encountered:

Working with complex data types in C.
* How can I collect results in a single string (char array) and return it?
* How do I work with dynamic strings as opposed to read-only
* Traversing by incrementing pointers.
    * This is not mutation of the original string, just moving the pointer to a new location.

Problem: the following code segfaulted and I do not know why (yet):
``` c
char *to_path(char *req);

int main() {

    char *req = "GET /blog HTTP/1.1";
    char *path = to_path(req);

    printf("Path: %s", path);

    return 0;
}


char *to_path(char *req) {

    char *start = req;
    char *end;

    const char *header_file = "/index.html";
    
    //skip the operation (GET, POST, DELETE, etc..)
    while(start[0] != ' ') {
        if (start[0] == '\0') { return NULL; }
        start++;
    }

    while(start[0] != ' ') {
        if(start[0] == '/') { continue; }
        end++;
    }

    return strcat(start, header_file);
}


//example request:
//GET /blog HTTP/1.1

// goal output (strip everything and construct file path):
// blog/index.html
```

I believe the code segfaulted due to the references to the end variable.
I increment this variable although it was defined only as a byte. So
maybe it was a segfault due to accessing out of bounds values of the array.

second thought... the segfault may have been because I didnt set char *start = req;
So I was traversing a non-existent character array;

finally found the error: the req I was passing to the function was a read-only string (string literal).
This segfaults because later in the function I attempted to mutate the string, 
but you cannot mutate string literals in C. They are stored in a read-only section of memory.
