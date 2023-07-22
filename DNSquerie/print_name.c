#include <stdlib.h>
#include <stdio.h>

const unsigned char* print_name(const unsigned char *msg, const unsigned char *p, const unsigned char *end) {
    if (p + 2 > end) {
        fprintf(stderr, "End of message.\n"); 
        exit(1);
    }
    if ((*p & 0xC0) == 0xC0) {
        const int k = ((*p & 0x3F) << 8) + p[1];
        p += 2;
        printf(" (pointer %d) ", k);
        print_name(msg, msg+k, end);
        return p;
    } else {
        const int len = *p++;
        if (p + len + 1 > end) {
            fprintf(stderr, "End of message.\n"); 
            exit(1);
        }
        printf("%.*s", len, p);
        p += len;
        if (*p) {
            printf(".");
            return print_name(msg, p, end);
        } else {
            return p+1;
        }
    }
}