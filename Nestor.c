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