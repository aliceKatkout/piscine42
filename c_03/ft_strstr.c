#include<stdio.h>



char    *ft_strstr(char *str, char *to_find)
{
        int     i;
        int     j;

        i = 0;
        j = 0;
        if (!*(to_find))
                return (str);
        while (*(str + i) != 0)
        {
                if (*(str + i) == *(to_find))
                {
                        while (to_find[j] != 0 && str[i + j] == to_find[j])
                        {
                                j ++;
                        }
                        if (*(to_find + j) == 0)
                                return (str + i);
                        j = 0;
                }
                i++;
        }
        return (0);
}

int main()
{
        printf("%s \n", ft_strstr("chou-ffleur", "fleur"));

}

