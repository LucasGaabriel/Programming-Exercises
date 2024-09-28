#include"ponto.h"

PONTO* InicializaPonto(){
  
  PONTO * novo_ponto = (PONTO*) malloc(sizeof(PONTO));
  novo_ponto->prox = NULL; 
  return novo_ponto;
    
}

void InicializaMap(PONTO* lista,char*vet[]){
  
  int cont = 0;
  for(PONTO* p = lista;p!=NULL;p=p->prox){
    vet[cont] = strdup(p->name);
    cont+=1;
  }
}

PONTO* InserePonto(PONTO* lista,PONTO* pont){

  pont->prox = lista;
  return pont;
  
}

int NumeroPontos(PONTO* lista){
 

  PONTO*p = lista;
  int cont = 0;

  while(p!=NULL){
    cont++;
    p=p->prox;
  }

  return cont;

}

int retornaDimensao(char *argv){
  
  FILE* arq = fopen(argv, "r");

  if(arq == NULL){
    printf("<ERROR 005> Arquivo não encontrado.\n");
    exit(EXIT_FAILURE);
  }
  
  char  conta[100000];

  if(fscanf(arq,"%[^\n]",conta)==1){}
  
  int cont = 0;
   
  for (int i=0; conta[i] != '\0'; i++){
    if(conta[i] == ','){
      cont++;
    }
  }


  fclose(arq);
  return cont;
  
  
}



char* retornaNome(PONTO* pont){
  
  return pont->name;
  
}

double* retornaVet(PONTO* pont){
  
  return pont->vet;
  
}

void EscreveNome(PONTO* pont){
  
  printf("%s\n",pont->name);
  
}

void EscreveValores(PONTO * pont,int m){
  
  for(int i = 0; i<m;i++){
    printf("%lf\n",pont->vet[i]);
  }
  
}


void EscreveListaPontos (PONTO* lista,int m){

  PONTO * p;

  for(p = lista;p!=NULL; p = p->prox){
    EscreveNome(p);
    EscreveValores(p,m);
    
    printf("\n");
  }

  printf("\n\n");

}

void printMap(char* map[],int v){
  
  for(int i=0;i<v;i++){
    printf("Indice: %d | Map[Indice]: %s\n",i,map[i]);
  }
  
}


PONTO* Leitura(PONTO* lista,char* argv,int m){
  
  FILE* arq = fopen(argv,"r");

  if(arq == NULL){
    printf("<ERROR 005> Arquivo não encontrado.\n");
    exit(EXIT_FAILURE);
  }
  
  char  conta[100000] ;
  
  
  if(fscanf(arq,"%[^\n]",conta)==1){}
  else{
    printf("<ERROR 006> Erro de Leitura\n");
  }
  
 
  int cont = 10;
  
  while(fgetc(arq) != EOF ){
    PONTO* ponto = InicializaPonto();
    ponto->vet = (double*)calloc(m,sizeof(double));
    int k =0;
    char *tokenC = strtok(conta,",");
     
      
    cont = 0;
   
    while(tokenC!=NULL){
      if(cont == 0){
        
        int num = 0;
        num = strlen(tokenC)+1;
        ponto ->name=(char *)calloc(num, sizeof(char));
        
        strcpy(ponto->name,tokenC);
        
        cont+=1;
      }
      else{
        
        double p = 0;
        
        p = atof(tokenC);
        
       
        ponto -> vet[k] = p;
        
        k+=1;
        cont+=1;
     
        
      }
      
       
      tokenC = strtok(NULL,",");
    }
     
    lista = InserePonto(lista,ponto);
    
    if(fscanf(arq,"%[^\n]",conta)==1){}
    
   
  
  }

  
  fclose(arq);
  return lista;
    
}


void LiberaListaPonto(PONTO* lista){

  PONTO*p = lista;

  PONTO* t;

  while(p!=NULL){
    t = p->prox;
    free(p->name);
    free(p->vet);
    free(p);
    p = t;
  }
}



void LiberaMap(char* map[], int v){
  
  for(int i=0; i< v; i++){
    free(map[i]);
  }
  
}

void isKValid(PONTO* lista,int k, int v){
  if(k < 0){
    printf("<ERROR 001> Entrada inválida. Verifique o k e tente novamente\n");
    LiberaListaPonto(lista);
    exit(EXIT_FAILURE);
  }
  else if(k == 0){
    printf("<ERROR 001> Entrada inválida. Verifique o k e tente novamente\n");
    LiberaListaPonto(lista);
    exit(EXIT_FAILURE);
  }
  else if(k > v){
    printf("<ERROR 001> Entrada inválida. Verifique o k e tente novamente\n");
    LiberaListaPonto(lista);
    exit(EXIT_FAILURE);
  }
  else{
    // Entrada valida!
  }
}