#include <iostream>

#include <iostream>
#define TAM 50

class Alumno{
private:
    std::string nombre;
    std::string carrera;
    int materias;
    int promedio;
public:
    Alumno(){};
    friend std::ostream & operator<<(std::ostream &O, Alumno &x){
         O<<"\n Nombre: "<<x.nombre<<std::endl;
          O<<"\n Carrera: "<<x.carrera<<std::endl;
           O<<"\n Materias: "<<x.materias<<std::endl;
            O<<"\n Promedio: "<<x.promedio<<std::endl;
            return O;
    }
    friend std::istream & operator>>(std::istream &O, Alumno &x){
            std::cout<<"\n Nombre: ";
            O>>x.nombre;
            std::cout<<"\n Carrera:";
            O>>x.carrera;
            std::cout<<"\n materias:";
            O>>x.materias;
            std::cout<<"\n promedio:";
            O>>x.promedio;
            return O;
    }
};

template<class T>
class Cola;

template<class T>
class node{
private:
    T data;
    node<T>* sig;
public:
    node():sig(nullptr){};
    friend class Cola<T>;
};

template<class T>
class Cola{
private:
    node<T>* lista;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
public:
    Cola():lista(nullptr){};
    bool vacia()const;
    void imprimir()const;
    void Enqueue(T elem);
    void Dequeue();
    T Front();
};

template<class T>
T Cola<T>::Front(){
    if(!vacia()){
       return primero()->data;
    }
}

template<class T>
void Cola<T>::Dequeue(){
    eliminar(primero());
}

template<class T>
void Cola<T>::Enqueue(T elem){
    insertar(ultimo(),elem);
}

template<class T>
void Cola<T>::imprimir()const{
    node<T>* aux=lista;
    while(aux!=nullptr){
        std::cout<<aux->data<<"-> ";
        aux=aux->sig;
    }
}

template<class T>
bool Cola<T>::eliminar(node<T>* pos){
    if(vacia() || pos==nullptr){
        return false;
    }
    if(pos==lista){
        lista=lista->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    return true;
}

template<class T>
void Cola<T>::insertar(node<T>* pos, T elem){
    node<T>* aux= new node<T>;
    aux->data=elem;
    if(pos==nullptr){
        aux->sig=lista;
        lista=aux;
    }
    else{
        aux->sig=pos->sig;
        pos->sig=aux;
    }
}

template<class T>
node<T>* Cola<T>::anterior(node<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
node<T>* Cola<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return lista;
}


template<class T>
node<T>* Cola<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
bool Cola<T>::vacia()const{
    if(lista==nullptr)
        return true;
    return false;
}

int main()
{
    Cola<Alumno> MiCola;
    Alumno x;
    int menu;
    do
    {
    std::cout<<"Menu "<<std::endl;
    std::cout<<"1.Alta de constancia"<<std::endl;
    std::cout<<"2.Imprimir constancia"<<std::endl;
    std::cout<<"3.Salir"<<std::endl;
    std::cin>>menu;
    switch(menu)
    {
    case 1:

        std::cout<<"Datos de la constancia"<<std::endl;
        std::cin>>x;
        MiCola.Enqueue(x);
        break;
    case 2:
        if(MiCola.vacia()){
         std::cout<<"Cola vacia"<<std::endl;
         }
         else
         {
         x=MiCola.Front();
         std::cout<<x<<std::endl;
         MiCola.Dequeue();
         }
    }
    }while(menu!=3);


    return 0;
}
