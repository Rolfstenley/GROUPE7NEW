#include<stdio.h>
#include<string.h>
struct facture{
	int numero;
	float montant;
	char objet[20];
	char idEtudiant[20];
};
const int N=2;
struct facture tabf[N];
void RemplirTab(struct facture tabf[N]){
	int i;
	for(i=0;i<N;i++){
		printf("veillez saisir le numero de la facture\n");
		scanf("%d",&tabf[i].numero);
		printf("veillez saisir le montant de la facture\n");
		scanf("%f",&tabf[i].montant);
		printf("veillez saisir l'objet de la facture\n");
		scanf("%s",&tabf[i].objet);
		printf("veillez saisir l'ID de l'etudiant\n");
		scanf("%s",&tabf[i].idEtudiant);
	}
}
void AfficherTab(struct facture tabf[N]){
	int i;
	for(i=0;i<N;i++){
		printf("\n	le numero de la facture est: %d\n",tabf[i].numero);
		printf("\n	le montant de la facture est: %f\n",tabf[i].montant);
		printf("\n	l'objet de la facture est: %s\n",tabf[i].objet);
		printf("\n	l'ID de l'etudiant est: %s\n",tabf[i].idEtudiant);
	}
}
float SommeTab(struct facture tabf[N]){
	int i;
	float s=0;
	for(i=0;i<N;i++){
		s=s+tabf[i].montant;
	}
		printf("la somme des factures est: %f",s);
	return s;
}
float MinTab(struct facture tabf[N]){
	int i;
	float min=tabf[0].montant;
	for(i=0;i<N;i++){
		if (tabf[i].montant<min){
			min=tabf[i].montant;
		}
	}
	printf("\n le plus petit montant des factures est :%f",min);
	return min;
}
float MaxTab(struct facture tabf[N]){
	int i;
	float max=tabf[0].montant;
	for(i=0;i<N;i++){
		if (tabf[i].montant>max){
			max=tabf[i].montant;
		}
	}
	printf("\n le plus grand montant des facture est :%.2f",max);
	return max;
}
float SommeparObjet(struct facture tabf[N]){
	int i;
	float Si=0;
	float Ss=0;
	for(i=0;i<N;i++){
		if(strcmp(tabf[i].objet,"inscription")==0){
			Si=Si+tabf[i].montant;
		}
			else if(strcmp(tabf[i].objet,"scolarite")==0){
			Ss=Ss+tabf[i].montant;
		}
	}
		printf("\n	le montant total des inscriptions est :%.2f",Si);
		printf("\n le montant total des scolarites est :%.2f",Ss);
		return Si,Ss;
}
void FactureparEtudiant(struct facture tabf[N]) {
	int i;
	char id[20];
	int t=0;
	printf("\nVeuillez saisir l'ID de l'etudiant : ");
	scanf("%s", id);
	for(i = 0; i < N; i++) {
		if(strcmp(id, tabf[i].idEtudiant) == 0) {
			printf("Facture : %d %.2f %s\n", tabf[i].numero, tabf[i].montant, tabf[i].objet);
			t=1;
		}
	}
	if(!t) {
		printf("Cet étudiant n'a pas de facture.\n");
	}
}
main(){
	RemplirTab(tabf);
	AfficherTab(tabf);
	SommeTab(tabf);
	MinTab(tabf);
	MaxTab(tabf);
	SommeparObjet(tabf);
	FactureparEtudiant(tabf);
}
void affiche_tab() {
    printf("\n--- Liste des factures ---\n");
    if (nb_factures == 0) {
        printf("Aucune facture enregistrée.\n");
        return;
    }

    for (int i = 0; i < nb_factures; i++) {
        printf("\nFacture %d:\n", i+1);
        printf("Numéro: %s\n", tab_factures[i].numero);
        printf("Montant: %.2f\n", tab_factures[i].montant);
        printf("Objet: %s\n", tab_factures[i].objet);
        printf("ID Étudiant: %s\n", tab_factures[i].id_etudiant);
        printf("Inscription: %s\n", tab_factures[i].inscription ? "Oui" : "Non");
        printf("Scolarité: %s\n", tab_factures[i].scolarite);
    }
}

float somme_tab() {
    float total = 0;
    for (int i = 0; i < nb_factures; i++) {
        total += tab_factures[i].montant;
    }
    printf("\nSomme totale des montants : %.2f\n", total);
    return total;
}

void min_tab() {
    if (nb_factures == 0) {
        printf("\nAucune facture enregistrée.\n");
        return;
    }

    float min = FLT_MAX;
    int index = -1;
    
    for (int i = 0; i < nb_factures; i++) {
        if (tab_factures[i].montant < min) {
            min = tab_factures[i].montant;
            index = i;
        }
    }

    printf("\nFacture avec le montant minimum :\n");
    printf("Numéro: %s, Montant: %.2f, Objet: %s\n", 
           tab_factures[index].numero, min, tab_factures[index].objet);
}

void max_tab() {
    if (nb_factures == 0) {
        printf("\nAucune facture enregistrée.\n");
        return;
    }

    float max = FLT_MIN;
    int index = -1;
    
    for (int i = 0; i < nb_factures; i++) {
        if (tab_factures[i].montant > max) {
            max = tab_factures[i].montant;
            index = i;
        }
    }

    printf("\nFacture avec le montant maximum :\n");
    printf("Numéro: %s, Montant: %.2f, Objet: %s\n", 
           tab_factures[index].numero, max, tab_factures[index].objet);
}

void somme_par_objet() {
    if (nb_factures == 0) {
        printf("\nAucune facture enregistrée.\n");
        return;
    }

    // Solution simple pour un petit nombre d'objets différents
    char objets[MAX_FACTURES][MAX_CHAINE];
    float sommes[MAX_FACTURES] = {0};
    int nb_objets = 0;

    for (int i = 0; i < nb_factures; i++) {
        int trouve = 0;
        for (int j = 0; j < nb_objets; j++) {
            if (strcmp(tab_factures[i].objet, objets[j]) == 0) {
                sommes[j] += tab_factures[i].montant;
                trouve = 1;
                break;
            }
        }
        if (!trouve) {
            strcpy(objets[nb_objets], tab_factures[i].objet);
            sommes[nb_objets] = tab_factures[i].montant;
            nb_objets++;
        }
    }

    printf("\nSomme des montants par objet :\n");
    for (int i = 0; i < nb_objets; i++) {
        printf("%s: %.2f\n", objets[i], sommes[i]);
    }
}

void facture_par_etudiant() {
    if (nb_factures == 0) {
        printf("\nAucune facture enregistrée.\n");
        return;
    }

    char id_etudiant[MAX_CHAINE];
    printf("\nEntrez l'ID de l'étudiant : ");
    fgets(id_etudiant, MAX_CHAINE, stdin);
    id_etudiant[strcspn(id_etudiant, "\n")] = 0;

    float total = 0;
    int trouve = 0;

    printf("\nFactures de l'étudiant %s:\n", id_etudiant);
    for (int i = 0; i < nb_factures; i++) {
        if (strcmp(tab_factures[i].id_etudiant, id_etudiant) == 0) {
            printf("Numéro: %s, Montant: %.2f, Objet: %s\n", 
                   tab_factures[i].numero, tab_factures[i].montant, tab_factures[i].objet);
            total += tab_factures[i].montant;
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucune facture trouvée pour l'étudiant %s.\n", id_etudiant);
    } else {
        printf("Total à payer: %.2f\n", total);
    }
}

int main() {
    int choix;
    
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Remplir le tableau des factures\n");
        printf("2. Afficher toutes les factures\n");
        printf("3. Calculer la somme totale des montants\n");
        printf("4. Trouver la facture avec le montant minimum\n");
        printf("5. Trouver la facture avec le montant maximum\n");
        printf("6. Calculer la somme des montants par objet\n");
        printf("7. Afficher les factures par étudiant\n");
        printf("8. Quitter\n");

        printf("\nVotre choix : ");
        scanf("%d", &choix);
        getchar(); // Pour consommer le '\n'

        switch (choix) {
            case 1:
                remplir_tab();
                break;
            case 2:
                affiche_tab();
                break;
            case 3:
                somme_tab();
                break;
            case 4:
                min_tab();
                break;
            case 5:
                max_tab();
                break;
            case 6:
                somme_par_objet();
                break;
            case 7:
                facture_par_etudiant();
                break;
            case 8:
                printf("Merci d'avoir utilisé le programme. Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 8);

    return 0;
}