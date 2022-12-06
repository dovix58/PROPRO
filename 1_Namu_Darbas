// LSP == 2213741 kavoliunudovyda@gmail.com(dovydas.kavoliunas@mif.stud.vu.lt) 1 užduotis 9 variantas
#include <stdio.h>
int main()
{
    int skaicius;
    char simbolis;
    int narys = 0;
    int kiekis = 0;

    printf("Iveskite  sveiku skaiciu seka: \n");
    do
    {

        printf("%d narys : ", narys + 1);
        if ((scanf("%d%c", &skaicius, &simbolis) == 2) && (simbolis == '\n'))
        {
            narys++;
            if ((narys % 2 == 0) && (skaicius > 0))
            {
                kiekis++;
            }
        }
        else
        {
            printf("netinami duomenys, pakartokite ivesti \n\n");
            scanf("%*[^\n]");
        }
    } while (skaicius != 0 || narys == 0);
    printf(" skaiciu kiekis == %d ", kiekis);

    return 0;
}
