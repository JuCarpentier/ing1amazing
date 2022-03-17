#ifndef ENTETE_H_INCLUDED
#define ENTETE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct maillon{
        int element;
        struct maillon *suivant;
        }t_maillon;

typedef struct fileDyn{
        t_maillon *Maillon_ADefiler;
        t_maillon *Maillon_AEnfile;
        }t_fileDyn;

void Affichage(t_fileDyn *Pt);
int Depiler(t_fileDyn *Pt);
void AjoutFile(t_fileDyn *Pt, int nouvelelement);
int EstVide(t_fileDyn *Pt);
void InitFile(t_fileDyn *Pt);
t_fileDyn CreationDeLaPile();
void CreationDuFichier();
int Recherche(t_fileDyn *Pt);
#endif // ENTETE_H_INCLUDED
