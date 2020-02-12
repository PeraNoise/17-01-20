#include <stdio.h>
#include <stdlib.h>
#define DIM_MAX 10

struct lista {
    int inf;
    int pos;
    struct lista *next
};

struct lista *copy_list();
void visual_list(struct lista *);

int vett1[DIM_MAX];
int vett2[DIM_MAX];
int pos[DIM_MAX];
int nval;

int read_file();
int check_dupl(int);
int print_array(int *);
int ord_array(int);
int pos_arr_ord();

int main(){

    read_file();
    print_array(vett1);
    printf("\n");
    print_array(vett2);
    struct lista *pl;
    pos_arr_ord();
    pl=copy_list();
    printf("\nLista--> ");
    visual_list(pl);
    return 0;
}

int read_file(){
    FILE *fileptr;
    fileptr=fopen("file1","r");
    int i=0;
    while (feof(fileptr)==0&&i<DIM_MAX){
        fscanf(fileptr,"%d",&vett1[i]);
        if(check_dupl(i)>0) i--;
        else {
            vett2[i]=vett1[i];
            ord_array(i);
        }
        i++;
    }
    nval=i;

}

int check_dupl(int n){
    int check=0;
    for (int i = 0; i < n; ++i) {
        if (vett1[i]==vett1[n])check++;
    }
    return check;
}

int print_array(int *vett){
    for (int i = 0; i < nval; ++i) {
        printf("%d  ", *(vett+i));
    }
}

int ord_array(int j){
    int vaux;
    for (int i = 0; i < j; ++i) {
        if(vett2[i]>vett2[j]){
            vaux=vett2[j];
            vett2[j]=vett2[i];
            vett2[i]=vaux;
        }
    }
}

int pos_arr_ord(){
    for (int i = 0; i < nval; ++i) {
        for (int j = 0; j < nval; ++j) {
            if (vett2[i]==vett1[j]){
                pos[j]=i+1;
            }
        }
    }
}

struct lista *copy_list(){
    struct lista *p, *paux;
    if (nval==0)p=NULL;
    else{
        p=(struct lista *)malloc(sizeof(struct lista));
        p->inf=vett1[0];
        p->pos=pos[0];
        paux=p;
        for (int i = 1; i < nval; ++i) {
            paux->next=(struct lista *)malloc(sizeof(struct lista));
            paux=paux->next;
            paux->inf=vett1[i];
            paux->pos=pos[i];
        }
        paux->next=NULL;
    }
    return p;
}

void visual_list(struct lista *p){
    while (p!=NULL){
        printf("(%d, %d) ",p->inf,p->pos);
        p=p->next;
    }
}