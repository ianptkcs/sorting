#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void createDirectories(const char *path)
{
    char temp[256];
    char *p = NULL;
    size_t len;

    snprintf(temp, sizeof(temp), "%s", path);
    len = strlen(temp);
    if (temp[len - 1] == '/')
        temp[len - 1] = '\0';

    for (p = temp + 1; *p; p++)
    {
        if (*p == '/')
        {
            *p = '\0';
            if (mkdir(temp, 0755) != 0 && errno != EEXIST)
            {
                printf("Erro ao criar diretório %s: %s\n", temp, strerror(errno));
                return;
            }
            *p = '/';
        }
    }
    if (mkdir(temp, 0755) != 0 && errno != EEXIST)
    {
        printf("Erro ao criar diretório %s: %s\n", temp, strerror(errno));
    }
}