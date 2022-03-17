#include"entete.h"

void InitFile(t_fileDyn *Pt)
{
    Pt->Maillon_ADefiler = NULL;
    Pt->Maillon_AEnfile = NULL;
}

int EstVide(t_fileDyn *Pt)
{
    if(Pt->Maillon_ADefiler == NULL && Pt->Maillon_AEnfile == NULL)
        return 1;
    else
        return 0;
}

void AjoutFile(t_fileDyn *Pt, int nouvelelement)
{
    t_maillon *Nouveau = NULL;

    Nouveau = malloc(sizeof(t_maillon));
    if(Nouveau == NULL)
    {
        printf("Erreur allocation dynamique\n");
    }
    else
    {
        Nouveau->element = nouvelelement;
        Nouveau->suivant = NULL;

        if(EstVide(Pt) == 1)
        {
            Pt->Maillon_ADefiler = Nouveau;
            Pt->Maillon_AEnfile = Nouveau;
        }
        else
        {
            Nouveau->suivant = Pt->Maillon_AEnfile;
            Pt->Maillon_AEnfile = Nouveau;
        }

    }
}

int Depiler(t_fileDyn *Pt)
{
    t_maillon *ptcourant = NULL;
    t_maillon *ptprecedent = NULL;
    int res;

    if(EstVide(Pt) == 1)
    {
        printf("Rien a rendre file vide\n");
    }
    else
    {
        ptcourant = Pt->Maillon_ADefiler;
        res = ptcourant->element;

        if(Pt->Maillon_ADefiler != Pt->Maillon_AEnfile)
        {
            ptcourant = Pt->Maillon_AEnfile;
            ptprecedent = ptcourant;
            while(ptcourant->suivant != NULL)
            {
                ptprecedent = ptcourant;
                ptcourant=ptcourant->suivant;
            }
            ptprecedent->suivant = NULL;;
            Pt->Maillon_ADefiler = ptprecedent;
        }
        else
        {
            Pt->Maillon_ADefiler = NULL;
            Pt->Maillon_AEnfile = NULL;
        }
        free(ptcourant);
        return res;
    }
}


void Affichage(t_fileDyn *Pt)
{
    if(EstVide(Pt) == 1)
    {

    }
    else
    {
        printf("%d\t", Depiler(Pt));
        Affichage(Pt);
    }
}
