/*Zweiergruppe Abgabe -- 
zusammenarbeit von: Prathik Shenoy (2226393) , Harsh Keswani (2225959)
Aufgabenummer: B21
Mittwoch 8:00 - 10:00 -- Mi08 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mannschaft{
    char Stadt[30];
    struct Mannschaft* nachfolger;
} Mannschaft;

void ausgeben(Mannschaft* Table){
    printf("Ausgabe der Liste: \n");
    while(Table != NULL){
        printf("%s\n",Table->Stadt);
        Table = Table->nachfolger;
    }
    printf("\n");
}
Mannschaft* insert(Mannschaft* Tabelle, char Stadt[30]){
    if(Tabelle == NULL){
        //Leere Liste
        Mannschaft *neu = malloc(sizeof(Mannschaft));
        neu->nachfolger = NULL;
        strncpy(neu->Stadt, Stadt, strlen(Stadt));
        Tabelle = neu;
    }else{
        //Laufe bis ans Ende der Liste
        Mannschaft *pos = Tabelle;
        while(pos->nachfolger != NULL){
            pos = pos->nachfolger;
        }
        Mannschaft *neu = malloc(sizeof(Mannschaft));
        neu->nachfolger = NULL;
        strncpy(neu->Stadt, Stadt, strlen(Stadt));
        pos->nachfolger = neu;
    }
    return Tabelle;
}
Mannschaft* absteigen(Mannschaft* Tabelle, char Stadt[30]){
    Mannschaft* pos = Tabelle;
    Mannschaft* vorgaenger = NULL;
    Mannschaft* nachfolger = NULL;
    Mannschaft* aktueller_Knoten = NULL;

    //Bestimme vorgaenger, nachfolger und den aktuellen zur Stadt passenden Knoten
    while(pos != NULL){
        if(strcmp(pos->Stadt, Stadt) == 0){
            aktueller_Knoten = pos;
            nachfolger = pos->nachfolger;
            break;
        }
        vorgaenger = pos;
        pos = pos->nachfolger;
    }
    //printf("%s %s %s\n", vorgaenger->Stadt, aktueller_Knoten->Stadt, nachfolger->Stadt);
    
    //Vertausche die Knoten
    if(vorgaenger == NULL){
        //aktueller Knoten ist das erste Element
        Tabelle = nachfolger;
        aktueller_Knoten->nachfolger = nachfolger->nachfolger;
        nachfolger->nachfolger = aktueller_Knoten;
    }else{
        vorgaenger->nachfolger = nachfolger;
        aktueller_Knoten->nachfolger = nachfolger->nachfolger;
        nachfolger->nachfolger = aktueller_Knoten;
    }

    return Tabelle;
}
int main(){
    
    Mannschaft *Tabelle = NULL;
    Tabelle = insert(Tabelle, "Leverkusen");
    Tabelle = insert(Tabelle, "Stuttgart");
    Tabelle = insert(Tabelle, "Wuppertal");
    Tabelle = insert(Tabelle, "Wolfsburg");
    Tabelle = insert(Tabelle, "Mönchengladbach");
    Tabelle = insert(Tabelle, "Berlin");
    Tabelle = insert(Tabelle, "Köln");

    ausgeben(Tabelle);

    absteigen(Tabelle, "Stuttgart");

    ausgeben(Tabelle);

    return 0; 
}