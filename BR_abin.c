#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "BR_abin.h"
#include "y.tab.h"

#define COUNT 10 //variable para printear el arbol, numero de espacios(no es importante para la funcionalidad)

//RED BLACK TREE
//Arbol binario que se balancea a través de colores
struct TreeNode{
    TIPOELEMENTOABB data;
    char color;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent;
};

//variable global que guarda la raiz del arbol
struct TreeNode* raiz = NULL;

//funciones privadas
void _left_rotate(nodo x);
void _right_rotate(nodo x);
void _rebalanceo(nodo z);


void crearArbol(nodo* root){
    *root = NULL;
}

//crea un nodo con el lexema y el id correspondiente
struct TreeNode* _crearNodo(char* lex,int id,union u the_union){
    nodo new = (nodo)malloc(sizeof (struct TreeNode));
    new->data.lexema = (char*) malloc(sizeof(lex) * sizeof (char));
    strcpy(new->data.lexema,lex);
    new->data.comp_lexico = id;
    new->color = 'r'; //por defecto siempre se crea un nodo rojo
    new->right=NULL;
    new->left=NULL;
    new->parent=NULL;
    //valor de la variable
    new->data.valor = the_union;
    return new;
}

//rotacion a la izquierda
void _left_rotate(nodo x){
    nodo y = x->right;
    x->right = y->left;

    if(y->left!=NULL){
        y->left->parent = x;
    }

    y->parent = x->parent;

    if(x->parent==NULL)raiz = y;
    else if(x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;

    y->left = x;
    x->parent = y;

}
//rotacion derecha
void _right_rotate(nodo x){
    nodo y = x->left;
    x->left = y->right;

    if(y->right != NULL) y->right->parent= x;
    y->parent = x->parent;

    if(x->parent==NULL)raiz = y;
    else if(x == x->parent->right) x->parent->right = y;
    else x->parent->left = y;

    y->right = x;
    x->parent = y;
}

//funcion para equilibrar el arbol una vez un nodo se inserta
//dificial de explicar, pero esta en google
// https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/?ref=lbp
void _rebalanceo(nodo z){
    nodo padre=NULL;
    nodo abuelo = NULL;
    while(z!=raiz && z->parent->color == 'r'){
        padre = z->parent;
        abuelo = z->parent->parent;
        if(padre == abuelo->left){ //el tio es el derecho del abuelo
            nodo y = abuelo->right;
            if(y!=NULL && y->color == 'r') {
                padre->color = 'b';
                y->color = 'b';
                abuelo->color = 'r';
                z = z->parent->parent;
            }else{
                if(z == padre->right) {
                    _left_rotate(padre);
                    z = padre;
                    padre = z->parent;
                }
                _right_rotate(abuelo);
                char c = padre->color;
                padre->color = abuelo->color;
                abuelo->color = c;
            }
        }else{ //cambiar los right por left y viceversa
            nodo y = abuelo->left;
            if(y!=NULL && y->color == 'r') {
                padre->color = 'b';
                y->color = 'b';
                abuelo->color = 'r';
                z = abuelo;
            }else{
                if(z == padre->left) {
                    _right_rotate(padre);
                    z = padre;
                    padre = z->parent;
                }
                _left_rotate(abuelo);
                char c = padre->color;
                padre->color = abuelo->color;
                abuelo->color = c;
                z = padre;
            }
        }
        if(z->parent == NULL) break; //    if z == root  ---> break
    }
}


void buscarElemento(nodo root,char* lexema,int* identificador){
    if(root==NULL){
        *identificador = ID;
        return ;
    }
    int cmp = strcmp(lexema,root->data.lexema); //comparamos lexema con el nodo del arbol
    if(cmp == 0) { //si encontramos el lexema lo devolvemos
        *identificador = root->data.comp_lexico;
        return;
    }
    //si es menor(alfabeticamnte) buscamos en el subarbol izquierdo
    //si es mayor buscamos en el subarbol derecho
    else if(cmp < 0) buscarElemento(root->left,lexema,identificador);
    else buscarElemento(root->right,lexema,identificador);
}

/*FUNCIONES NUEVAS PARA INTERPRETE MATEMATICO*/
nodo insertarFunciones(nodo* root,TIPOELEMENTOABB info,nodo padre){
    if(*root == NULL){
        if(padre == NULL){
            *root = _crearNodo(info.lexema,info.comp_lexico,info.valor);

            //si el nodo es la raiz el color siempre es negro
            (*root)->color = 'b';
            raiz = *root;
            return raiz;
        }
        nodo leaf = _crearNodo(info.lexema,info.comp_lexico,info.valor);
        //comparamos su lexema con el del padre para saber si va a su izq o a su derecha
        int comp = strcmp(info.lexema,padre->data.lexema);
        if(comp>0) padre->right = leaf;
        else padre->left = leaf;
        //le asignamos su padre
        leaf->parent = padre;
        //al introducir el nodo tenemos que rebalancear
        _rebalanceo(*root);
        raiz->color='b';
        return raiz;
    }

    int cmp = strcmp(info.lexema,(*root)->data.lexema); //comparamos lexema con el nodo del arbol
    //si es menor(alfabeticamnte) buscamos en el subarbol izquierdo
    //si es mayor buscamos en el subarbol derecho
    if(cmp < 0) insertarFunciones(&((*root)->left),info,*root);
    else insertarFunciones(&(*root)->right,info,*root);
    return raiz;
}


nodo guardarValor(nodo* root,char* lexema,double v,nodo padre){
    if(*root == NULL){
        union u uni;
        uni.val = v;
        nodo leaf = _crearNodo(lexema,ID,uni);
        int comp = strcmp(lexema,padre->data.lexema);
        if(comp>0) padre->right = leaf;
        else padre->left = leaf;
        //le asignamos su padre
        leaf->parent = padre;
        //al introducir el nodo tenemos que rebalancear
        _rebalanceo(*root);
        raiz->color='b';
        return raiz;
    }
    int cmp = strcmp(lexema,(*root)->data.lexema); //comparamos lexema con el nodo del arbol
    if(cmp == 0) { //si encontramos el lexema lo devolvemos
        if((*root)->data.comp_lexico ==ID)(*root)->data.valor.val = v;
        return raiz;
    }
        //si es menor(alfabeticamnte) buscamos en el subarbol izquierdo
        //si es mayor buscamos en el subarbol derecho
    else if(cmp < 0) guardarValor(&((*root)->left),lexema,v,*root);
    else guardarValor(&(*root)->right,lexema,v,*root);
    return raiz;
}

void obtenerValor(nodo root,char* lexema,union u * valorObtenido){
    if(root == NULL){
        valorObtenido->val = VARIABLE_NO_ASIGNADA;
        return ;
    }
    int cmp = strcmp(lexema,root->data.lexema); //comparamos lexema con el nodo del arbol
    if(cmp == 0) { //si encontramos el lexema devolvemos el valor que tiene
        *valorObtenido = root->data.valor;
    }
        //si es menor(alfabeticamnte) buscamos en el subarbol izquierdo
        //si es mayor buscamos en el subarbol derecho
    else if(cmp < 0) obtenerValor(root->left,lexema,valorObtenido);
    else obtenerValor(root->right,lexema,valorObtenido);
    return ;
}
/*FUNCION RECURSIVA
 * Libera memoria del arbol y lo elimina*/
void destruirArbol(nodo* root){
    if(*root == NULL){
        return;
    }
    destruirArbol(&((*root)->left));
    destruirArbol(&((*root)->right));
    (*root)->right = NULL;
    (*root)->left = NULL;
    (*root)->parent = NULL;
    if((*root)->data.lexema != NULL ) {
        free((*root)->data.lexema);
        (*root)->data.lexema = NULL;
    }
    free((*root));
    (*root) = NULL;
}


void printVariables(nodo root){
    if(root==NULL)return;
    printVariables(root->left);
    if(root->data.comp_lexico==ID)printf("\t%s\t|\t%.2lf\n", root->data.lexema, root->data.valor.val);
    printVariables(root->right);
}

void printFuncines(nodo root){
    if(root==NULL)return;
    printFuncines(root->left);
    if(root->data.comp_lexico==FUNC || root->data.comp_lexico==FUNC2)printf("\t%s\n", root->data.lexema);
    printFuncines(root->right);
}

//muestra el arbol en inorden -> FUNCION RECURSIVA
void inorden(nodo root){
    if(!root) return;
    inorden(root->left);
    printf("%s: %d ", root->data.lexema, root->data.comp_lexico);
    inorden(root->right);
}

//Muestra el arbol en 2D
void _print2DUtil(nodo root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    _print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%s", root->data.lexema);
    if(root->data.comp_lexico == ID) printf("->%.2lf\n",root->data.valor.val);

    // Process left child
    _print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(nodo root)
{
    // Pass initial space count as 0
    _print2DUtil(root, 0);
}
