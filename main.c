   /*
    Caracteristicas de la aplicacion:\n
    \t -Solicitar al usuario la cantidad de números a capturar en la aplicación. \n
    La cantidad minima de numeros a capturar son 5.
    La cantidad máxima de números a capturar es de 10.
    Los números a capturar por el usuario, pueden estar en el rango del 0 al 99.
    Si el usuario captura la letra x en la entrada de la cantidad de números de la aplicación, esta se cerrara.
    Una vez que el usuario termine de capturar la cantidad de números que ingreso, la aplicación realizara los siguientes cálculos:
            Máximo
            Minimo
            Media
            Mediana
            Moda
    Cada uno de los cálculos solicitados, deberá implementarse a través de una función.
    La aplicación deberá mostrar el resultado de los 5 cálculos. */
#include <stdio.h>
#include <stdlib.h>

/*Funcion para el maximo*/
int max(int numeros[], int cantidad_numeros) {
   int maximo = numeros[0]; // Asignamos el primer valor del arreglo como máximo
   
   for (int i = 1; i < cantidad_numeros; i++) {
      if (numeros[i] > maximo) { // Si el valor actual es mayor que el máximo, lo asignamos como nuevo máximo
         maximo = numeros[i];
      }
   }
   return maximo;
}

/*Funcion para el minimo*/
int min(int numeros[], int cantidad_numeros) {
   int minimo = numeros[0]; // Asignamos el primer valor del arreglo como minimo
   
   for (int i = 1; i < cantidad_numeros; i++) {
      if (numeros[i] < minimo) { // Si el valor actual es menor que el minimo, lo asignamos como nuevo minimo
         minimo = numeros[i];
      }
   }
   return minimo;
}

//Funcion para la media
float half(int numeros[], int cantidad_numeros){
    float suma=0;
    for(int i=0; i< cantidad_numeros; i++){
        suma += numeros[i]; //suma acumulativa
    }
    float media = suma / cantidad_numeros;
    return media;
}

//Complementos para la funcion Mediana 
void insercion(int numeros [],int cantidad_numeros){ //Acomodo de los valores dados por el usuario
    int i,j,index;
    for(i=1; i< cantidad_numeros; i++){
        index = numeros[i];
        j=i-1;
        while(j>=0 && numeros[j] > index){
            numeros[j+1] = numeros[j];
            j--;
        }
        numeros[j+1] = index;
    }

}

double mediana(int numeros[], int cantidad_numeros){ //Funcion mediana
    insercion(numeros,cantidad_numeros);
    double mediana;
    int mitad = cantidad_numeros / 2;
    //Caso en donde es un numero par 
    if(cantidad_numeros % 2 == 0){
        mediana = (numeros[mitad-1] + numeros[mitad]) /2;
    }else{
        mediana = numeros[mitad];
    }
    return mediana;
}

 /*Funcion para la moda*/
int mode(int numeros[], int cantidad_numeros) {
   
int moda;
int contador1 = 0;
int contador2 = 0;

   for (int i = 0; i < cantidad_numeros; i++) 
   {
      for (int j = 0; j < cantidad_numeros; j++)
       {
            if (numeros[i] == numeros[j]) //compara los valores del arreglo posicion por posicion
            {
                contador1++; //si son identicos este contador avanza
             }
        }
          if (contador1 > contador2) 
        {
            contador2 = contador1;  //aqui se establece el cont2 para que siempre sea el mas grande
            moda = numeros[i];      //la moda tomara el valor del numero que mas se repita que sera el de cont2
        }
        contador1 = 0;          //regresamos el cont1 a cero para que no haya problemas en el codigo al momento de evaluar mas
   }
   return moda; 
}  

int main() {
    int numeros[10]; // Array para almacenar los números
    int cantidad_numeros; //El primer valor que ingresa el usuario el rango permitido es [5,6,7,8,9,10]
    int rango; //Variable rango para determinar si los numeros ingresados estan dentro del del rango de 0 a 99
    char x; //Variable para detectar el caracter "x" ingresado por el usuario

    // Pedir al usuario la cantidad de números que quiere ingresar
    printf("Ingrese la cantidad de numeros que desea ingresar (entre 5 y 10): ");
    scanf("%d", &cantidad_numeros); //Almacenamiento del numero en la variable

    //Condicion en donde menciona que si entra el caracter x se cierre la aplicacion
    x = getchar(); //Declaracion que x es una cadena de caracter
    if(x == 'x') { //Compara si entra X
        exit(0); //Cierra la aplicacion si el caso se cumple
    }
    // Verificar que la cantidad ingresada esté dentro del rango permitido
    while (cantidad_numeros < 5 || cantidad_numeros > 10) {
        printf("La cantidad de numeros ingresada no esta en el rango permitido.\n");
        printf("Ingrese la cantidad de numeros que desea ingresar (entre 5 y 10): ");
        scanf("%d", &cantidad_numeros);

        //En caso de que se vuelva a ingresar el caracter X erroneamente
        x = getchar();
        if(x == 'x') {
            exit(0);
        }
        printf("\n");
    }
    printf("\n");
    
    // Pedir al usuario que ingrese los números y almacenarlos en el array
    printf("Ingrese los %d numeros:\n", cantidad_numeros);
    for (int i = 0; i < cantidad_numeros; i++) {
        printf("Numero %d: ", i+1); //Se va haciendo un incremento para el arreglo
        scanf("%d", &rango); //Se almacena en la variable rango para detectar que se cumpla dicho rango
        
	//Pregunta si esta en el rango de 0 a 99
        if (rango<0 || rango>99){
            printf ("El numero debe estar en el rango de 0 a 99. Intente de nuevo \n");
            i--; //Si no se encuentra en el rango, retrocede el contador
            continue; //Continua con el programa 
        }
        numeros[i]=rango; //Se le asigna lo que este en numeros[i] a la variable rango
    }
    printf("\n");
    
    // Mostrar los números ingresados PLUS A LOS REQUERIMIENTOS DE APLICACIÓN (Ver los numeros que el mismo usuario ingreso)
    printf("Los numeros ingresados son:\n");
    for (int i = 0; i < cantidad_numeros; i++) {
        if (numeros[i]==0){
            break; //No mostrar nada en caso de que el usuario ingrese puros 0
        }
        printf("%d ", numeros[i]); //muestra los numeros del arreglo
    }
    printf("\n");

    int maximo = max(numeros, cantidad_numeros); // Llamamos a la función para obtener el máximo
    printf("\nEl valor máximo es: %d\n", maximo); // Imprimimos el resultado

    int minimo = min(numeros, cantidad_numeros); // Llamamos a la función para obtener el minimo
    printf("\nEl valor minimo es: %d\n", minimo); // Imprimimos el resultado
    
    //Mostrar la media utilizando una funcion personalizada para ese calculo
    printf("\n");
    float media=half(numeros, cantidad_numeros);
    printf("La media es: %.2f", media);

    //Mostrar la mediana utilizando una funcion personalizada para ese calculo
    printf("\n");
    printf("La mediana es: %.2f",mediana(numeros,cantidad_numeros));
    /*Cabe mencionar que para la mediana primero se hace el acomodo de los numeros de menor a mayor y luego se selecciona.
    Solo maneja la parte positiva, en caso de tener parte fraccionaria se omitira.
    */
	
    int moda = mode(numeros, cantidad_numeros); // Llamamos a la función para obtener el minimo
    printf("\nLa moda es: %d\n", moda); // Imprimimos el resultado	
	
    return 0;
}
