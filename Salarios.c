#include <stdio.h>

#define LONG 30

typedef struct {
    char nombre[LONG];
    unsigned int edad;
    unsigned int salario;
} Employee;

Employee IngresarDatos(Employee);
void mostrarDatos(Employee[], int);
void procesarDatos(Employee[], int);

#define MAX_EMPLOYEES 5

int main(void){
  Employee employees[MAX_EMPLOYEES];
  int opcion;
  int personalIngresado = 0;

  printf("Bienvenid@ al programa salarial de DobleVM entretainment\n");
  printf("Seleccione la tecla 1 para ver todos los salarios registrados\n");
  printf("Seleccione la tecla 2 para registrar a un empleado\n");
  printf("Seleccione la tecla 3 para cerrar el programa\n");
  scanf("%d", &opcion);

  do {
    switch(opcion) {
      case 1:  
        mostrarDatos(employees, personalIngresado);
        procesarDatos(employees, personalIngresado+1);
        break;

      case 2:
        if (personalIngresado < MAX_EMPLOYEES) {
          employees[personalIngresado] = IngresarDatos(employees[personalIngresado]);
          personalIngresado++;
        } else {
          printf("Alcanzaste el limite de empleados\n");
        }
        break;
    }

    printf("\nSeleccione la tecla correspondiente (1 - 2 - 3) : ");
    scanf("%d", &opcion);

  } while (opcion != 3);

  return 0;
}

Employee IngresarDatos(Employee employees){
  printf("Ingrese el nombre del empleado: ");
  scanf("\n%[^\n]%*c", employees.nombre);
  printf("Ingrese la edad del empleado: ");
  scanf("%d", &employees.edad);
  printf("Ingrese (en usd) el salario del empleado: ");
  scanf("%d", &employees.salario);

  return employees;
}

void mostrarDatos(Employee employees[], int personalIngresado){
  for(int i = 0; i < personalIngresado; i++){
    printf("-------------------------------------------------------------------");
    printf("\n -Nombre: %s, Edad: %d, Salario: %d \n", employees[i].nombre, employees[i].edad, employees[i].salario);
  }

}

void procesarDatos(Employee employees[], int personalIngresado){ 
  int maximo = 0;
  int sumaSalarios = 0;
  float promedio = 0;

  for(int i = 0; i < personalIngresado; i++){
    sumaSalarios += employees[i].salario;
    if (employees[i].salario > maximo) {
      maximo = employees[i].salario;
    }
  }

  if (personalIngresado > 0) {
    promedio = (float)sumaSalarios / personalIngresado;
  }

  printf("\nEl salario promedio de los empleados (hasta ahora) es: $ %.2f \n", promedio);
}