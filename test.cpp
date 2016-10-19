#include <stdio.h>
#include <dirent.h>

static void scan_dir(const char *dir)
{
    struct dirent * entry;
    DIR *d = opendir( dir );

    if (d == 0) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(d)) != 0) {
        printf("%s\n", entry->d_name);
        //read your file here
    }
    closedir(d);
}


int main(int argc, char ** argv)
{
    scan_dir(argv[1]);
    return 0;
}
