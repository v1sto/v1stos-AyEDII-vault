#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length)
{
    printf("\"");
    for (unsigned int j = 0u; j < length; j++)
    {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size)
{

    FILE *file;
    file = fopen(path, "r");
    unsigned int length = 0;
    if (file == NULL)
    {
        fprintf(stderr, "Error al abrir el archivo\n");
        return 0;
    }

    while (fscanf(file, "%u -> *%c*", &indexes[length], &letters[length]) == 2)
    {
        length++;
    }

    fclose(file);

    if (length > max_size)
    {
        fprintf(stderr, "Error tamaño excedido\n");
        return 0;
    }

    return length;
}

void sort_array(unsigned int indexes[], char letters[], char sorted[], unsigned int length)
{
    unsigned int i = 0;
    while (i < length && length <= MAX_SIZE)
    {
        sorted[indexes[i]] = letters[i];
        i++;
    }
}

char *parse_filepath(int argc, char *argv[])
{
    char *result = NULL;

    bool valid_args_count = (argc == 2);

    if (!valid_args_count)
    {
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

int main(int argc, char *argv[])
{
    char *filepath = NULL;
    filepath = parse_filepath(argc, argv);
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length = 0;

    length = data_from_file(filepath, indexes, letters, MAX_SIZE);

    sort_array(indexes, letters, sorted, length);

    dump(sorted, length);

    return EXIT_SUCCESS;
}