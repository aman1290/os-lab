#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/wait.h> // Include this for wait()

int get_process_id() {
    return getpid();
}

int get_parent_process_id() {
    return getppid();
}

DIR* open_directory(const char *path) {
    DIR *d = opendir(path);
    if (d == NULL) {
        perror("Could not open the directory");
        exit(EXIT_FAILURE);
    }
    return d;
}

void read_directory(DIR* d) {
    struct dirent* e;
    while ((e = readdir(d)) != NULL)
        printf("%s\n", e->d_name);
}

void close_directory(DIR* d) {
    if (closedir(d) != 0) {
        perror("Could not close the directory");
        exit(EXIT_FAILURE);
    }
}

void create_process() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
        printf("Hello world! Process ID (pid) = %d\n", getpid());
}

int main() {
    printf("Process ID: %d\n", get_process_id());
    printf("Parent Process ID: %d\n", get_parent_process_id());

    const char* dir_path = "/home/shreyx/c_code";
    DIR* dir = open_directory(dir_path);
    read_directory(dir);
    close_directory(dir);

    create_process();

    return 0;
}

