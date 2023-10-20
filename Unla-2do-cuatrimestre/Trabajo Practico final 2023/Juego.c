#include "Juego.h"


JuegoPtr crearJuego(listaJugadoresPtr listaJugadores){
    JuegoPtr j;
    j=(JuegoPtr)malloc(sizeof(struct Juego));
    j->listajugadores=listaJugadores;
    return j;
};
listaJugadoresPtr getListaJugadores(JuegoPtr juego) {
    return juego->listajugadores;
};

void setListaJugadores(JuegoPtr juego, listaJugadoresPtr lista) {
    juego->listajugadores = lista;
};
int seleccionJugadores() {
    int cantJugadores;

    do {
        bienvenda();
        printf("Ingrese la cantidad de jugadores (entre 2 y 4): ");
        scanf("%d", &cantJugadores);

        if (cantJugadores < 2 || cantJugadores > 4) {
            system("cls");
            printf("La cantidad de jugadores debe estar entre 2 y 4. Por favor, intentelo de nuevo.\n");
        }
    } while (cantJugadores < 2 || cantJugadores > 4);

    return cantJugadores;
};
void mostrarRanking(int **ranking, int filas, int columnas){
    printf("*****************************************\n");
    printf("*        RANKING DE JUGADORES           *\n");
    printf("*****************************************\n");
    printf("*  DNI     *\t  PUNTUACION            *\n");
    printf("*****************************************\n");

    for (int i = 0; i < filas; i++) {
        int dni = ranking[i][0];
        int puntaje = ranking[i][1];
        printf("* %5d *\t%10d\t\t*\n", dni, puntaje);
    }

    printf("*****************************************\n");
};
void menuPrincipal(int **ranking, int filas, int columnas, listaJugadoresPtr listaJugadores,int cantJugadores,int *dniJugadores){
    int opcion;
    char salir;
    JugadorPtr jugadorActual;
    int correcta;
    PreguntaPtr preguntaActual;
    nodoPreguntaPtr nodoPreguntaActual;
    nodoRespuestaPtr nodoRespuestaActual;
    int numeroTipeado;
    int bandera=0;
    int jugaron=0;
    int** rankingActuales;
    int** rankingActualesMostrar;
    int tiempoTranscurrido=0;
    JugadorPtr jugadorCampeon;
    system("cls");
    do {
        nombreApp();
        printf("********** MENU PRINCIPAL **********\n");
        printf("1. Jugar\n");
        printf("2. Ver puntuaciones historicas\n");
        printf("3. Ver estadisticas de jugadores actuales\n");
        printf("4. Salir del juego\n");
        printf("\n");
        printf("Elija una opcion (1-4): ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:

                for(int i=0;i<cantJugadores;i++){
                    correcta=0;
                    jugadorActual=buscarJugadorPorDNI(listaJugadores,dniJugadores[i]);
                    jugadorActual->Puntos->actuales=0;
                    barajarListaPreguntas(jugadorActual->preguntas);
                    nodoPreguntaActual=jugadorActual->preguntas->inicio;
                        do{
                            system("cls");
                            nombreApp();
                            printf("Es el turno de: %s\n",jugadorActual->alias);
                            mostrarJugador(jugadorActual);
                            preguntaActual=nodoPreguntaActual->pregunta;
                            mostrarPregunta(preguntaActual);//muestra la pregunta y posibles respuestas
                            printf("\n");
                            numeroTipeado=temporizador(TIEMPO,&tiempoTranscurrido);
                            nodoRespuestaActual=preguntaActual->respuestasPosibles->inicio;

                            while(nodoRespuestaActual!=NULL){
                                if(numeroTipeado==nodoRespuestaActual->respuesta->nroRespuesta){
                                    correcta=nodoRespuestaActual->respuesta->correcta;
                                    bandera=1;
                                    break;
                                };
                                nodoRespuestaActual=nodoRespuestaActual->siguiente;
                            };//fin while

                                if(correcta&&bandera){
                                    jugadorActual->Puntos->actuales=jugadorActual->Puntos->actuales+(10*(TIEMPO-tiempoTranscurrido));
                                    if(jugadorActual->Puntos->actuales>jugadorActual->Puntos->puntuacionMax){
                                        jugadorActual->Puntos->puntuacionMax=jugadorActual->Puntos->actuales;
                                    };
                                    //setPuntuacionMaxima(jugadorActual->Puntos,jugadorActual->Puntos->puntuacionMax+=jugadorActual->Puntos->actuales);
                                }else{
                                    system("cls");
                                    cartelPerdedor();
                                    printf("\n***Tu puntuacion en esta partida: %d***\n\n",jugadorActual->Puntos->actuales);
                                    bandera=0;
                                    break;
                                };

                            nodoPreguntaActual=nodoPreguntaActual->siguiente;
                            bandera=0;
                        }while(nodoPreguntaActual!=NULL);//Fin priimer while
                        cartelSinPreguntas(nodoPreguntaActual,jugadorActual);
                };//Fin de for
                rondaDesempate(listaJugadores);
                jugadorCampeon=obtenerJugadorCampeon(listaJugadores);
                system("cls");
                cartelCampeon();
                mostrarJugador(jugadorCampeon);
                system("pause");
                opcion=1;
                jugaron=1;
                eliminarDnisMatriz(&ranking,&filas,columnas,dniJugadores,cantJugadores);
                rankingActuales=recuperarRankingListaJugadores(listaJugadores,cantJugadores);
                rankingActualesMostrar=unirMatricesVert(ranking,filas,columnas,rankingActuales,cantJugadores);
                escribirMatrizEnArchivo("ranking.txt",rankingActualesMostrar,filas+cantJugadores,2);
                system("cls");
                break;
            case 2:
                system("cls");
                if(!jugaron){
                    ordenarPorPuntajeMasAlto(ranking,filas);
                    mostrarRanking(ranking,filas,columnas);
                }else{
                    ordenarPorPuntajeMasAlto(rankingActualesMostrar,filas+cantJugadores);
                    mostrarRanking(rankingActualesMostrar,filas+cantJugadores,columnas);
                };
                system("pause");
                system("cls");
                break;
            case 3:
                if(listaJugadores!=NULL){
                    system("cls");
                    printf("********** ESTADISTICAS ACTUALES **********\n");
                    ordenarListaJugadoresPorPuntaje(listaJugadores);
                    mostrarListaJugadores(listaJugadores);
                    system("pause");
                }else{
                    printf("No se pudo acceder a los datos. Volviendo al menu principal...");
                    system("pause");
                };
                    system("cls");
                break;
            case 4:

                system("cls");
                printf("\n============================================\n");
                printf("       ESTAS SEGURO QUE QUIERES SALIR?       \n \t\t\t[s/n]\n");
                printf("============================================\n");
                fflush(stdin);
                scanf("%c",&salir);

                if(salir=='s'||salir=='S'){
                       // Liberar memoria al salir del juego
                    liberarMemoriaMatriz(rankingActuales, cantJugadores);
                    liberarMemoriaMatriz(rankingActualesMostrar, filas + cantJugadores);
                    printf("\n");
                    printf("\nSaliendo...\n");
                    opcion = 4;
                }else{
                    system("cls");
                    opcion=3;
                };

                break;
            default:
                system("cls");
                printf("*************Opcion %d no valida. Por favor, seleccione una opcion valida (1-3).***********\n",opcion);
        }
    } while (opcion != 4);
};

nodoJugadorPtr rondaDesempate(listaJugadoresPtr listaJugadores) {
    srand(time(NULL));
    int cantJugadores = 0;
    listaJugadoresPtr nuevaLista = crearListaJugadores();
    nodoJugadorPtr actualJugador = listaJugadores->inicio;
    long respuesta;
    int puntajeActualMax=0;
    puntajeActualMax=buscarPuntajeActualMaximo(listaJugadores);
    while (actualJugador != NULL) {
        nodoJugadorPtr compararJugador = listaJugadores->inicio;

        while (compararJugador != NULL) {
            if (actualJugador->jugador->Puntos->actuales == compararJugador->jugador->Puntos->actuales && compararJugador != actualJugador) {
                if (!jugadorEnLista(nuevaLista, actualJugador->jugador)&&compararJugador->jugador->Puntos->actuales==puntajeActualMax ) {
                    cantJugadores++;
                    nodoJugadorPtr nuevoNodo = crearNodoJugador(actualJugador->jugador);
                    insertarNodoJugadorPrincipio(nuevoNodo, nuevaLista);
                };
            };
            compararJugador = compararJugador->siguiente;
        };
        actualJugador = actualJugador->siguiente;
    };

    if (nuevaLista->inicio == NULL) {
        //liberacion de memoria
        eliminarListaJugadoresTemporales(nuevaLista);
        return nuevaLista->inicio;
    };

    system("cls");
    nombreApp();
    printf("Los siguientes jugadores deberan desempatar con una pregunta por aproximacion:\n");
    mostrarListaJugadores(nuevaLista);
    system("pause");
    system("cls");

    int** dniRespuestas = crearMatrizEnteros(cantJugadores, 2);
    int indice = 0;
    actualJugador = nuevaLista->inicio;

    int distanciaMinima = 2147483647; // Valor máximo para int
    int a;
    int b;
    long respuestaAux;
    a=GenerarAleatorioInt(1,10);
    b=GenerarAleatorioInt(1,10);

    while (actualJugador != NULL) {
        mostrarJugador(actualJugador->jugador);
        //printf("la multiplicacion da: %d\n",a*b);
        printf("Cuanto es %d * %d ?\nTu respuesta: ",a,b);
        scanf("%ld", &respuesta);
        dniRespuestas[indice][0] = actualJugador->jugador->dni;
        dniRespuestas[indice][1] = respuesta;
        indice++;
        actualJugador = actualJugador->siguiente;
    }


    for (int i = 0; i < cantJugadores; i++) {
        int respuesta = dniRespuestas[i][1];
        int distancia = abs(respuesta - (a*b));

            if (distancia<distanciaMinima) {
                distanciaMinima = distancia;
                respuestaAux=respuesta;
            };
        };


    for(int i=0; i<cantJugadores;i++){
        if(dniRespuestas[i][1]==respuestaAux){
            JugadorPtr jugadorSumar = buscarJugadorPorDNI(nuevaLista, dniRespuestas[i][0]);
            jugadorSumar->Puntos->actuales=jugadorSumar->Puntos->actuales+1;
            if(jugadorSumar->Puntos->actuales>jugadorSumar->Puntos->puntuacionMax){
                jugadorSumar->Puntos->puntuacionMax=jugadorSumar->Puntos->actuales;
            };
        };
    };
    //Se libera memoria...
    liberarMemoriaMatriz(dniRespuestas,cantJugadores);
    eliminarListaJugadoresTemporales(nuevaLista);
    return rondaDesempate(listaJugadores); // Llamada recursiva
};//Fin ronda desempate funcion
int buscarPuntajeActualMaximo(listaJugadoresPtr listaJugadores) {
    int puntajeMaximo = 0; // Inicializa con un valor mínimo válido
    nodoJugadorPtr actualJugador = listaJugadores->inicio;

    while (actualJugador != NULL) {
        int puntajeActual = actualJugador->jugador->Puntos->actuales;
        if (puntajeActual > puntajeMaximo) {
            puntajeMaximo = puntajeActual;
        }
        actualJugador = actualJugador->siguiente;
    }

    return puntajeMaximo;
};
int contarJugadores(listaJugadoresPtr lista) {
    int contador = 0;
    nodoJugadorPtr actual = lista->inicio;

    while (actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }

    return contador;
};
void cartelCampeon(){
    printf(" #####        #       #     #    ######     #######    #######    #     #\n");
    printf("#     #      # #      ##   ##    #     #    #          #     #    ##    #\n");
    printf("#           #   #     # # # #    #     #    #          #     #    # #   #\n");
    printf("#          #     #    #  #  #    ######     #####      #     #    #  #  #\n");
    printf("#          #######    #     #    #          #          #     #    #   # #\n");
    printf("#     #    #     #    #     #    #          #          #     #    #    ##\n");
    printf(" #####     #     #    #     #    #          #######    #######    #     #\n");
};
int jugadorEnLista(listaJugadoresPtr lista, JugadorPtr jugador) {
    int retorno=0;
    nodoJugadorPtr actual=lista->inicio;
    while(actual!=NULL){
        if(jugador==actual->jugador){
            retorno=1;
            break;
        };
        actual=actual->siguiente;
    };
    // Retorna 1 si el jugador está en la lista, 0 en caso contrario
    return retorno;
};
JugadorPtr obtenerJugadorCampeon(listaJugadoresPtr lista) {

    int maxPuntos=0;
    JugadorPtr jugadorCampeon;
    if (lista->inicio == NULL) {
        // La lista está vacía
        return NULL;
    };

    nodoJugadorPtr actualJugador = lista->inicio;

    while (actualJugador != NULL) {
        int puntosActuales = actualJugador->jugador->Puntos->actuales;

        if (puntosActuales > maxPuntos) {
            maxPuntos = puntosActuales;
            jugadorCampeon=actualJugador->jugador;
        }

        actualJugador = actualJugador->siguiente;
    }

    return jugadorCampeon;
};
void cartelSinPreguntas(nodoPreguntaPtr preguntaActual,JugadorPtr jugadorActual){
    if(preguntaActual==NULL){
        system("cls");
        printf("Ya no hay mas preguntas que responder...");
        printf("\n***Tu puntuacion en esta partida: %d***\n\n",jugadorActual->Puntos->actuales);
    }
        system("pause");
};
void cartelPerdedor(){
printf(" _____                      _   _         _            _ \n");
printf("|  __ \\                    | | (_)       | |          | |\n");
printf("| |__) |   ___   _ __    __| |  _   ___  | |_    ___  | |\n");
printf("|  ___/   / _ \\ | '__|  / _` | | | / __| | __|  / _ \\ | |\n");
printf("| |      |  __/ | |    | (_| | | | \\__ \\ | |_  |  __/ |_|\n");
printf("|_|       \\___| |_|     \\__,_| |_| |___/  \\__|  \\___| (_)\n");

};
void bienvenda(){

printf(" ____    _                                         _       _                 _ \n");
printf("|  _ \\  (_)                                       (_)     | |               | |\n");
printf("| |_) |  _    ___   _ __   __   __   ___   _ __    _    __| |   ___    ___  | |\n");
printf("|  _ <  | |  / _ \\ | '_ \\  \\ \\ / /  / _ \\ | '_ \\  | |  / _` |  / _ \\  / __| | |\n");
printf("| |_) | | | |  __/ | | | |  \\ V /  |  __/ | | | | | | | (_| | | (_) | \\__ \\ |_|\n");
printf("|____/  |_|  \\___| |_| |_|   \\_/    \\___| |_| |_| |_|  \\__,_|  \\___/  |___/ (_)\n\n\n");
};
void nombreApp(){
 printf(" ____                             _     _   _ _   _ _        _    \n");
        printf("|  _ \\ _ __ ___  __ _ _   _ _ __ | |_  | | | | \\ | | |      / \\   \n");
        printf("| |_) | '__/ _ \\/ _` | | | | '_ \\| __| | | | |  \\| | |     / _ \\  \n");
        printf("|  __/| | |  __/ (_| | |_| | | | | |_  | |_| | |\\  | |___ / ___ \\ \n");
        printf("|_|   |_|  \\___|\\__, |\\__,_|_| |_|\\__|  \\___/|_| \\_|_____/_/   \\_\\ \n");
        printf("                |___/                                           \n\n\n");
};
int temporizador(int tiempoLimite,int *tiempoTranscurrido){
     *tiempoTranscurrido=0;
    //int tiempoLimite = 15; // 15 segundos
    clock_t inicio = clock();
    int numeroTipeado = 0;
    while (*tiempoTranscurrido < tiempoLimite) {
        if (kbhit()) {
            numeroTipeado = getch() - '0'; // Leer un solo carácter y convertirlo a número
            if(numeroTipeado!=1&&numeroTipeado!=2&&numeroTipeado!=3&&numeroTipeado!=4){
                numeroTipeado=0;
                continue;
            }else{
                break;
            };
        };

        *tiempoTranscurrido = (int)((clock() - inicio) / CLOCKS_PER_SEC);
        printf("Tiempo restante: %2d segundos\r", tiempoLimite - *tiempoTranscurrido);
        fflush(stdout); // Forzar la actualización de la salida

        // Pausar durante 1 segundo
        sleep(1);
    }
    return numeroTipeado;
};
