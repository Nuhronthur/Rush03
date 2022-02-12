#include <stdlib.h>
 
int     get_abs_val(int nb)
{
    if (nb < 0)
        return (-nb);
    return (nb);
}
 
int     get_len(int nb)
{
    int len;
    
    len = 0;
    if (nb <= 0)
        len++;
    while (nb != 0)
    {
        len++;
        nb = nb / 10;
    }
    return (len);
}
 
char    *itoa(int nb)
{
    char *res;
    int len;
 
    len = get_len(nb);
    res = malloc(sizeof(char) * (len + 1));
    res[len] = '\0';
    if (nb < 0)
        res[0] = '-';
    else if (nb == 0)
        res[0] = '0';
    while (nb != 0)
    {
        len--;
        res[len] = get_abs_val(nb % 10) + '0';
        nb = nb / 10;
    }
    return (res);
}
