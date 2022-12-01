

#include<iostream>
#include<array>
#include<string>

using namespace std;

const int TAM=100;





typedef struct{

    string palabras;

    int repeticiones;


}Estructura;

typedef array<Estructura,TAM> Tguardar;


void escribirpalabras(Tguardar &prueba);
int contarpalabras(const Tguardar&prueba);



void mostarpalabras(const Tguardar &prueba, int numpal);
void inicializar( Tguardar &prueba);

void ordenar(Tguardar &prueba,int num);




int main(){

int numpalabras;


Tguardar prueba;


inicializar(prueba);
escribirpalabras(prueba);

numpalabras=contarpalabras(prueba);

ordenar(prueba,numpalabras);


mostarpalabras(prueba,numpalabras);





return 0;

}


void escribirpalabras(Tguardar &prueba){

        
        string aux;
        string aux2;

       
        
        int i=0;

            cout<<"introduzca la frase acabada en fin "<<endl;

            cin>>aux;

            prueba[i].palabras=aux;


            i++;

                while(aux!="fin"){

                    cin>>aux;

                   
                        for(int j=0;j<i;j++){
                            
                            aux2=prueba[j].palabras;

                                if(aux==aux2){

                                    prueba[j].repeticiones++;
                                }else{

                                    prueba[i].palabras=aux;

                                }
                            
                        }

                    i++;
                }



}

int contarpalabras(const Tguardar&prueba){


        int contadorpalabras=0;

        string aux;
        
        aux=prueba[contadorpalabras].palabras;

        contadorpalabras++;



        while(aux!="fin" ){

            aux=prueba[contadorpalabras].palabras;

            contadorpalabras++;
        }


        return contadorpalabras-1;

}




void mostarpalabras(const Tguardar &prueba, int numpal){


    int np=numpal;

                for(int i=0;i<numpal;i++){


                    cout<<prueba[i].palabras<<"("<<prueba[i].repeticiones<<")"<<" ";
                }
}

void inicializar( Tguardar &prueba){


        


            for(int i=0;i<TAM;i++){

                prueba[i].repeticiones=1;
            }

}

void ordenar(Tguardar &prueba,int num){

    string temp;
    int tempn;
    int rep=num;

            for(int i=0;i<rep-1;i++){

                for(int j=i+1;j<num;j++){

                    if(prueba[i].palabras>prueba[j].palabras){
                        
                        temp=prueba[j].palabras;
                        tempn=prueba[j].repeticiones;

                        prueba[j].palabras=prueba[i].palabras;
                        prueba[j].repeticiones=prueba[i].repeticiones;

                        prueba[i].palabras=temp;
                        prueba[i].repeticiones=tempn;
                    }
                }

            }


}