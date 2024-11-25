#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    int fd;
    const char *filename = "example.txt";
    const char *data = "Hello World!\n";
    char buffer[100];
    ssize_t bytes_;

    fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        perror("Error opening the file");
        return 1;
    }

    bytes_ = write(fd, data, strlen(data));
    if (bytes_ == -1)
    {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    if (close(fd) == -1)
    {
        perror("Error closing the file");
        return 1;
    }

    printf("File successfully opened\n");

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening the file");
        return 1;
    }

    bytes_ = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_ == -1)
    {
        perror("Error reading from file");
        close(fd);
        return 1;
    }

    buffer[bytes_] = '\0';
    printf("Read from the file: %s\n", buffer);

    if (close(fd) == -1)
    {
        perror("Error closing the file");
        return 1;
    }

    return 0;
}

