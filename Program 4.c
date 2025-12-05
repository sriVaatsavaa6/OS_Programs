// writer.c
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd;
    char *fifo = "/tmp/myfifo";

    mkfifo(fifo, 0666);                 // create named pipe

    fd = open(fifo, O_WRONLY);          // open for writing
    write(fd, "Hi", 3);                 // send "Hi" (+ '\0')
    close(fd);

    unlink(fifo);                       // delete FIFO file
    return 0;
}



// reader.c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX 100

int main() {
    int fd;
    char *fifo = "/tmp/myfifo";
    char buf[MAX];

    fd = open(fifo, O_RDONLY);          // wait until writer opens
    read(fd, buf, MAX);                 // read message
    printf("Writer: %s\n", buf);        // output: Writer: Hi
    close(fd);

    return 0;
}
