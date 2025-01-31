int numb_split(char **argv)
{
    int i;

    i = 0;
    while (argv[i])
        i++;
    return (i);
}