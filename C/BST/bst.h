//
// Created by Lucas Gabriel on 03/05/2022.
//

#ifndef ARVORE_BINARIA_DE_BUSCA_BST_H
#define ARVORE_BINARIA_DE_BUSCA_BST_H

typedef struct arvore Arvore;

Arvore* criarArvoreVazia();
Arvore* criarArvore(int chave);
Arvore* inserirChave(Arvore* arvore, int chave);
void liberarArvore(Arvore* arvore);
int alturaBST(Arvore* arvore);
int retornarChave(Arvore* arvore);
void rec_preorder(Arvore* arvore, void (*visit)(Arvore*));
void rec_inorder(Arvore* arvore, void (*visit)(Arvore*));
void rec_postorder(Arvore* arvore, void (*visit)(Arvore*));


#endif //ARVORE_BINARIA_DE_BUSCA_BST_H
