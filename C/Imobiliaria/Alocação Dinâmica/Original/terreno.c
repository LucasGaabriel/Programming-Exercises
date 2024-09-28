#include "terreno.h"

//Faz a verificacao se o solo e "Arenoso", "Argiloso" ou "Rochoso"
float verificaSolo(char s){
    if(s == 'A'){
        return 0.9;
    }
    else if(s == 'G'){
        return 1.3;
    }
    else if(s == 'R'){
        return 1.1;
    }
    return 0;
}
