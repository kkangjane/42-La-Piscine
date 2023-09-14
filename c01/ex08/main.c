#include <stdio.h>

void ft_sort_int_tab(int tab[], int size);

int main(void)
{
    int tab[] = {5, 8, 2, 200, 4};
    for(int i = 0; i < 5; i++)
        printf("%d ", tab[i]);
    ft_sort_int_tab(tab, 5);
    printf("\n");
    for(int i = 0; i < 5; i++)
        printf("%d ", tab[i]);
    return 0;
}