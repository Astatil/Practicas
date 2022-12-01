#include <iostream>
#include <string>
#include <array>

using namespace std;

const  int TAM=9;


typedef array<char,TAM> filacad;                   // F
typedef array<filacad,TAM> Tmatriz;                  // F C



void leercadena(string &entrada);

void rellenar(string &entrada, Tmatriz &m);

void desplazarColV( Tmatriz &m, int ic, int id);

void mostrarmatriz(Tmatriz &m);

void desplazar (Tmatriz &m, long int clave);

string extraer (const Tmatriz &m);

string codificar (const string &entrada,long int clave_, Tmatriz &m);




int main(){

string entrada;
string salida;
Tmatriz m;

long int key;

        

         leercadena(entrada);

        cout<<"introduzca una clave de 9 caracteres"<<endl;
        cin>>key;


      
      

        rellenar(entrada,m);                            
        desplazar(m,key);
        salida=extraer(m);

        cout<<salida<<endl;


       


return 0;

}

void leercadena(string &entrada){
    

    cout<<" introduzca la cadena "<<endl;

    getline(cin,entrada);

    while(entrada.size()>81){

        cout<<" debe introducir de nuevo la cadena, el maximo es 81 caracteres"<<endl;
        
        entrada.clear();
        getline(cin,entrada);
    }
}


void rellenar(string &entrada, Tmatriz &m){

      long int caracteres=0;

      long int total =entrada.size();

        for(int f=0;f<TAM;f++){


                for(int c=0;c<TAM;c++){


                        if(caracteres<total){

                            m[f][c]=entrada[caracteres];

                            caracteres++;

                        }else {

                            m[f][c]='.';

                            caracteres++;
                        }
                }
        }



}

void mostrarmatriz(Tmatriz &m){


    for(int f=0;f<TAM;f++){

        for(int c=0;c<TAM;c++){

            cout<<m[f][c];
        }

        cout<<endl;
    }

}


void desplazarColV( Tmatriz &m, int ic, int id){

        int columna=ic-1;
        int desplazar=id;
        
        
    for(int j=0;j<desplazar;j++){
        
        char aux=m[TAM-1][columna];

        for(int i=TAM-1;i>0;i--){
        
        m[i][columna]=m[i-1][columna];
       
        }

        m[0][columna]=aux;
       
    }
                
               

        

}   



void desplazar (Tmatriz &m, long int clave){


    long int key=clave;
    


    

    long int indicedesplazamiento;




                      for(int digitos=9;digitos>0;digitos--){
                        
                        indicedesplazamiento=key%10;

                        key=key/10;

                        
                    
                        desplazarColV(m,digitos,indicedesplazamiento);

                         

                      }
                       
}


string extraer (const Tmatriz &m){



    string cd;


                for(int f=0;f<TAM;f++){

                    for(int c=0;c<TAM;c++){


                        cd+=m[f][c];
                    }
                }


            return cd;

}




  