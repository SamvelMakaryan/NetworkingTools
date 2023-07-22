## DNS querie

This program sends DNS query and prints all header info.

### Usage

- compile with gcc (gcc *.c -o dns_query)
- run (./dns_query [hostname] [type])
    - [hostname] - any hostname or IP address
    - [type] - one of following record types (a, aaaa, txt, mx, any) 