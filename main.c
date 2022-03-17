#include"entete.h"

int main()
{
    srand(time(NULL));
    t_fileDyn MaFile;
    int res;

    CreationDuFichier();

    MaFile = CreationDeLaPile();

    res = Recherche(&MaFile);

    if(res == 1)
        printf("Le nombre existe\n");
    else
        printf("Le nombre n'existe pas\n");

    return 0;
}

void CreationDuFichier()
{
    FILE * doc;
    int nb;

    printf("saisir Nb de caractere voulu\n");
    scanf("%d", &nb);

    doc = fopen("donnees.txt","w");

    for(int i=0; i<nb; i++)
    {
        fprintf(doc,"%d\n",rand()%(5));
    }

    fclose(doc);
}

t_fileDyn CreationDeLaPile()
{
    FILE * doc = NULL;
    t_fileDyn Temp;
    int res;

    InitFile(&Temp);

    doc = fopen("donnees.txt","r");

    if(doc == NULL)
    {
        printf("Erreur ouverture fichier\n");
    }
    else
    {
        while(!feof(doc))
        {
            fscanf(doc,"%d\n",&res);
            AjoutFile(&Temp, res);
        }
        fclose(doc);
    }

    return Temp;
}

int Recherche(t_fileDyn *Pt)
{
    int res;

    int choix;

    printf("saisir nb de recherche :\n");
    scanf("%d", &choix);

    while(EstVide(Pt) == 0 && res!=choix)
    {
        res = Depiler(Pt);
    }

    if(res == choix)
        return 1;
    else
        return 0;
}
