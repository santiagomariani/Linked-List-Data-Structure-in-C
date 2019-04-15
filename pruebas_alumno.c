#include <stddef.h>
#include <stdio.h>

#include "lista.h"
#include "testing.h"
#include "pila.h"
#include "vector_dinamico.h"

void pruebas_listaenlazada_vacia(){
	lista_t* lista = lista_crear();
	print_test("Crear lista nueva",lista);
	print_test("Lista vacia inicialmente",lista_esta_vacia(lista));

	print_test("Lista vacia: ver primero es NULL",lista_ver_primero(lista) == NULL);
	print_test("Lista vacia: ver ultimo es NULL",lista_ver_ultimo(lista) == NULL);
	print_test("Lista: borrar primero es NULL",lista_borrar_primero(lista) == NULL);
	print_test("Lista vacia: largo de la lista es 0",lista_largo(lista) == 0);
	lista_destruir(lista,NULL);
}

void pruebas_listaenlazada_NULL(){
	lista_t* lista = lista_crear();
	print_test("Crear lista nueva",lista);
	print_test("Lista vacia inicialmente",lista_esta_vacia(lista));

	print_test("Se inserta primero NULL",lista_insertar_primero(lista,NULL));
	print_test("Lista con NULL: ver primero es NULL",lista_ver_primero(lista) == NULL);
	print_test("Lista con NULL: ver ultimo es NULL",lista_ver_ultimo(lista) == NULL);
	print_test("Lista con NULL: largo de la lista es 1",lista_largo(lista) == 1);
	print_test("Lista con NULL: borrar primero es NULL",lista_borrar_primero(lista) == NULL);
	print_test("Lista vacia",lista_esta_vacia(lista));
	lista_destruir(lista,NULL);
}

void pruebas_listaenlazada_elementos(){
	lista_t* lista = lista_crear();
	print_test("Crear lista nueva",lista);
	print_test("Lista vacia inicialmente",lista_esta_vacia(lista));

	int valor1 = 1;
	int valor2 = 2;
	int valor3 = 3;

	print_test("Se inserta primero valor1",lista_insertar_primero(lista,&valor1));
	print_test("Lista con valor1: ver primero es valor1",lista_ver_primero(lista) == &valor1);
	print_test("Lista con valor1: ver ultimo es valor1",lista_ver_ultimo(lista) == &valor1);
	print_test("Lista con valor1: largo de la lista es 1",lista_largo(lista) == 1);
	print_test("Lista con valor1: borrar primero es valor1",lista_borrar_primero(lista) == &valor1);
	print_test("Lista vacia",lista_esta_vacia(lista));

	print_test("Se inserta primero valor1",lista_insertar_primero(lista,&valor1));
	print_test("Ver primero es valor1",lista_ver_primero(lista) == &valor1);
	print_test("Lista con valor1: largo de la lista es 1",lista_largo(lista) == 1);
	print_test("Se inserta primero valor2",lista_insertar_primero(lista,&valor2));
	print_test("Ver primero es valor2",lista_ver_primero(lista) == &valor2);
	print_test("Ver ultimo es valor1",lista_ver_ultimo(lista) == &valor1);
	print_test("Lista con valor1 y valor2: largo de la lista es 2",lista_largo(lista) == 2);
	print_test("Se inserta primero valor3",lista_insertar_primero(lista,&valor3));
	print_test("Ver primero es valor3",lista_ver_primero(lista) == &valor3);
	print_test("Ver ultimo es valor1",lista_ver_ultimo(lista) == &valor1);
	print_test("Lista con valor1,valor2 y valor3: largo de la lista es 3",lista_largo(lista) == 3);

	print_test("Borrar primero es valor3",lista_borrar_primero(lista) == &valor3);
	print_test("Borrar primero es valor2",lista_borrar_primero(lista) == &valor2);
	print_test("Borrar primero es valor1",lista_borrar_primero(lista) == &valor1);
	print_test("Lista vacia",lista_esta_vacia(lista));

	printf("Se inserta primero valor1 100\n");
	
	for(int i = 0;i < 100;i++){
		lista_insertar_primero(lista,&valor1);
	}
	print_test("Ver primero y ver ultimo es valor1",(lista_ver_primero(lista) == &valor1) && (lista_ver_ultimo(lista) == &valor1));
	
	printf("Se elimina primero 100 veces\n");
	for(int i = 0;i < 100;i++){
		lista_borrar_primero(lista);
	}
	print_test("Lista vacia",lista_esta_vacia(lista));

	printf("Insertar/eliminar consecutivo\n");
	for(int i = 0;i < 100;i++){
		lista_insertar_primero(lista,&valor1);
		lista_borrar_primero(lista);
	}
	print_test("Luego de Insertar/eliminar consecutivo se tiene lista vacia",lista_esta_vacia(lista));

	lista_destruir(lista,NULL);
}

void wrapper_pila_destruir(void* pila){
	pila_destruir((pila_t*)pila);
}

void wrapper_vectordinamico_destruir(void* vd){
	vector_destruir(vd);
}

void pruebas_listaenlazada_destruir(){
	lista_t* lista = lista_crear();
	print_test("Crear lista nueva",lista);
	print_test("Lista vacia inicialmente",lista_esta_vacia(lista));

	pila_t* pila1 = pila_crear();
	pila_t* pila2 = pila_crear();
	pila_t* pila3 = pila_crear();

	print_test("Se inserta primero pila1",lista_insertar_primero(lista,pila1));
	print_test("Ver primero es pila1",lista_ver_primero(lista) == pila1);
	print_test("Se inserta primero pila2",lista_insertar_primero(lista,pila2));
	print_test("Ver primero es pila2",lista_ver_primero(lista) == pila2);
	print_test("Se inserta primero pila3",lista_insertar_primero(lista,pila3));
	print_test("Ver primero es pila3",lista_ver_primero(lista) == pila3);

	printf("Se destruye la lista con sus elementos\n");
	lista_destruir(lista,wrapper_pila_destruir);

	lista = lista_crear();
	print_test("Crear lista nueva",lista);
	print_test("Lista vacia inicialmente",lista_esta_vacia(lista));

	vector_t* vec1 = vector_crear(5);
	vector_t* vec2 = vector_crear(5);
	vector_t* vec3 = vector_crear(5);

	print_test("Se inserta primero vec1",lista_insertar_primero(lista,vec1));
	print_test("Ver primero es vec1",lista_ver_primero(lista) == vec1);
	print_test("Se inserta primero vec2",lista_insertar_primero(lista,vec2));
	print_test("Ver primero es vec2",lista_ver_primero(lista) == vec2);
	print_test("Se inserta primero vec3",lista_insertar_primero(lista,vec3));
	print_test("Ver primero es vec3",lista_ver_primero(lista) == vec3);

	printf("Se destruye la lista con sus elementos\n");
	lista_destruir(lista,wrapper_vectordinamico_destruir);
}

void pruebas_iterador_externo_lista_vacia(){
	lista_t* lista = lista_crear();
	print_test("Crear lista nueva",lista);
	print_test("Lista vacia inicialmente",lista_esta_vacia(lista));

	lista_iter_t* iter = lista_iter_crear(lista);
	print_test("Crear iterador nuevo",iter);

	print_test("Iterador lista vacia: ver actual es NULL",lista_iter_ver_actual(iter) == NULL);
	print_test("Iterador lista vacia: vterador esta al final",lista_iter_al_final(iter));
	print_test("Iterador lista vacia: no se puede avanzar",!lista_iter_avanzar(iter));
	print_test("Iterador lista vacia: borrar es NULL",lista_iter_borrar(iter) == NULL);

	printf("Se detruye el iterador\n");
	lista_iter_destruir(iter);
	lista_destruir(lista,NULL);
}

void pruebas_iterador_externo_lista_elementos(){
	lista_t* lista = lista_crear();
	print_test("Crear lista nueva",lista);
	print_test("Lista vacia inicialmente",lista_esta_vacia(lista));

	int valor1 = 1;
	int valor2 = 2;
	int valor3 = 3;

	print_test("Se inserta primero valor1",lista_insertar_primero(lista,&valor1));
	print_test("Se inserta primero valor2",lista_insertar_primero(lista,&valor2));
	print_test("Se inserta primero valor3",lista_insertar_primero(lista,&valor3));

	lista_iter_t* iter = lista_iter_crear(lista);
	print_test("Crear iterador nuevo",iter);

	print_test("Iterador lista elementos: ver actual es valor3",lista_iter_ver_actual(iter) == &valor3);
	print_test("Iterador lista elementos: iterador no esta al final",!lista_iter_al_final(iter));
	print_test("Iterador lista elementos: el iterador avanza",lista_iter_avanzar(iter));
	print_test("Iterador lista elementos: ver actual es valor2",lista_iter_ver_actual(iter) == &valor2);
	print_test("Iterador lista elementos: iterador no esta al final",!lista_iter_al_final(iter));
	print_test("Iterador lista elementos: el iterador avanza",lista_iter_avanzar(iter));
	print_test("Iterador lista elementos: ver actual es valor1",lista_iter_ver_actual(iter) == &valor1);
	print_test("Iterador lista elementos: iterador esta al final",!lista_iter_al_final(iter));
	print_test("Iterador lista elementos: el iterador avanza",lista_iter_avanzar(iter));
	print_test("Iterador lista elementos: iterador esta al final",lista_iter_al_final(iter));
	print_test("Iterador lista elementos: borrar al final es NULL",lista_iter_borrar(iter) == NULL);
	print_test("Iterador lista elementos: iterador esta al final",lista_iter_al_final(iter));
	printf("Se destruye el iterador\n");
	lista_iter_destruir(iter);

	iter = lista_iter_crear(lista);
	print_test("Crear iterador nuevo",iter);

	print_test("Iterador lista elementos: se inserta al principio valor1",lista_iter_insertar(iter,&valor1));
	print_test("Iterador lista elementos: ver actual es valor1",lista_iter_ver_actual(iter) == &valor1);
	print_test("Iterador lista elementos: el iterador avanza",lista_iter_avanzar(iter));
	print_test("Iterador lista elementos: el iterador avanza",lista_iter_avanzar(iter));
	print_test("Iterador lista elementos: ver actual es valor2",lista_iter_ver_actual(iter) == &valor2);
	printf("Se prueba insertar al principio\n");
	print_test("Iterador lista elementos: se inserta en la 3 posicion valor1",lista_iter_insertar(iter,&valor1));
	print_test("Iterador lista elementos: ver actual es valor1",lista_iter_ver_actual(iter) == &valor1);

	printf("Iterador avanza hasta el final\n");
	while(!lista_iter_al_final(iter)){
		lista_iter_avanzar(iter);
	}
	print_test("Iterador lista elementos: iterador esta al final",lista_iter_al_final(iter));
	print_test("Iterador lista elementos: se inserta al final valor3",lista_iter_insertar(iter,&valor3));
	print_test("Iterador lista elementos: ver actual es valor3",lista_iter_ver_actual(iter) == &valor3);
	printf("Se destruye el iterador\n");
	lista_iter_destruir(iter);
	lista_destruir(lista,NULL);

	lista = lista_crear();
	print_test("Se crean nuevamente la lista y se agregan los valores",lista);
	lista_insertar_primero(lista,&valor1);
	lista_insertar_primero(lista,&valor2);
	lista_insertar_primero(lista,&valor3);

	iter = lista_iter_crear(lista);
	print_test("Crear iterador nuevo",iter);

	print_test("Iterador lista elementos: se borra el primer elemento (valor3) ",lista_iter_borrar(iter) == &valor3);
	print_test("Iterador lista elementos: ver actual es valor2",lista_iter_ver_actual(iter) == &valor2);
	print_test("Iterador lista elementos: se inserta al principio valor1",lista_iter_insertar(iter,&valor1));
	print_test("Iterador lista elementos: el iterador avanza",lista_iter_avanzar(iter));
	printf("Se prueba insertar en el medio con iterador\n");
	print_test("Iterador lista elementos: se inserta en la posicion 2 valor1",lista_iter_insertar(iter,&valor1));
	print_test("Iterador lista elementos: ver actual es valor1",lista_iter_ver_actual(iter) == &valor1);
	printf("Iterador avanza hasta el ultimo elemento\n");
	print_test("Iterador lista elementos: el iterador avanza",lista_iter_avanzar(iter));
	print_test("Iterador lista elementos: el iterador avanza",lista_iter_avanzar(iter));
	printf("Iterador se encuentra en la posicion del ultimo elemento\n");
	printf("Se prueba eliminar el ultimo elemento\n");
	print_test("Iterador lista elementos: se borra el ultimo elemento (valor1)",lista_iter_borrar(iter) == &valor1);
	printf("Se destruye el iterador\n");
	lista_iter_destruir(iter);
	lista_destruir(lista,NULL);
}

void pruebas_listaenlazada(){
	pruebas_listaenlazada_vacia();
	pruebas_listaenlazada_NULL();
	pruebas_listaenlazada_elementos();
	pruebas_listaenlazada_destruir();
}

void pruebas_iterador_externo(){
	pruebas_iterador_externo_lista_vacia();
	pruebas_iterador_externo_lista_elementos();
}

bool imprimir_elementos(void* dato,void* extra){
	printf("%d \n",*(int*)dato);
	return true;
}

bool imprimir_3_elementos(void* dato,void* extra){
	if((*(int*) extra) == 3){
		return false;
	}
	printf("%d \n",*(int*)dato);
	(*(int*)extra)++;
	return true;
}

void pruebas_iterador_interno(){
	lista_t* lista = lista_crear();
	print_test("Crear lista nueva",lista);
	print_test("Lista vacia inicialmente",lista_esta_vacia(lista));

	int extra = 0;

	int valor1 = 1;
	int valor2 = 2;
	int valor3 = 3;
	int valor4 = 4;
	int valor5 = 5;
	int valor6 = 6;

	print_test("Se inserta primero valor1",lista_insertar_primero(lista,&valor1));
	print_test("Se inserta primero valor2",lista_insertar_primero(lista,&valor2));
	print_test("Se inserta primero valor3",lista_insertar_primero(lista,&valor3));
	print_test("Se inserta primero valor4",lista_insertar_primero(lista,&valor4));
	print_test("Se inserta primero valor5",lista_insertar_primero(lista,&valor5));
	print_test("Se inserta primero valor6",lista_insertar_primero(lista,&valor6));

	printf("Se deben imprimir los 3 primeros valores\n");
	lista_iterar(lista,imprimir_3_elementos,&extra);

	printf("Se deben imprimir todos los valores \n");
	lista_iterar(lista,imprimir_elementos,NULL);

	lista_destruir(lista,NULL);
}

void pruebas_lista_alumno() {
	pruebas_iterador_externo();
	pruebas_listaenlazada();
	pruebas_iterador_interno();
}