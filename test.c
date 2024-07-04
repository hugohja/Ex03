#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int i;
    int size;

    // Se min for maior ou igual a max, não há intervalo válido
    if (min >= max)
    {
        *range = NULL;
        return 0;
    }

    // Calcula o tamanho do array
    size = max - min;

    // Aloca memória para o array
    *range = (int *)malloc(size * sizeof(int));
    if (*range == NULL)
    {
        // Retorna -1 se a alocação falhar
        return -1;
    }

    // Preenche o array com os valores de min a max - 1
    i = 0;
    while (i < size)
    {
        (*range)[i] = min + i;
        i++;
    }

    // Retorna o tamanho do array
    return size;
}

#include <stdio.h>
#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max);

int main(void)
{
    int *range;
    int size;
    int i;
    int min = 5;
    int max = 10;

    size = ft_ultimate_range(&range, min, max);

    if (size == -1)
    {
        printf("Erro na alocação de memória.\n");
    }
    else if (size == 0)
    {
        printf("Intervalo inválido.\n");
    }
    else
    {
        printf("Array size: %d\n", size);
        printf("Array elements: ");
        for (i = 0; i < size; i++)
        {
            printf("%d ", range[i]);
        }
        printf("\n");
    }

    // Libera a memória alocada
    if (range != NULL)
    {
        free(range);
    }

    return 0;
}
