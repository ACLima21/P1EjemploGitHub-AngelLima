package com.espe.p1ejemplogithubjavalimaangel;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.Scanner;//Se importa la librería para poder leer de consola
import org.json.simple.JSONObject;//Librería para trabajar con archivos JSON
import java.io.IOException;//Para manejar los errores al momento de crear el archivo

public class Lima_Student {

    protected String Lima_nom;
    protected double Lima_studentAverage, Lima_grade1, Lima_grade2, Lima_grade3;
    protected Boolean Lima_checkRegister = false, Lima_checkAverage = false;

    /*Constructor de la clase*/
    public Lima_Student(String Lima_nom, double Lima_studentAverage, double Lima_grade1, double Lima_grade2, double Lima_grade3, Boolean Lima_checkRegister, Boolean Lima_checkAverage) {
        this.Lima_nom = Lima_nom;
        this.Lima_studentAverage = Lima_studentAverage;
        this.Lima_grade1 = Lima_grade1;
        this.Lima_grade2 = Lima_grade2;
        this.Lima_grade3 = Lima_grade3;
        this.Lima_checkRegister = Lima_checkRegister;
        this.Lima_checkAverage = Lima_checkAverage;
    }

    public void Lima_menu() {//Método del menú
        int Lima_opcMenu;
        Scanner sc = new Scanner(System.in);//instacia de la función Scanner

        System.out.println("Escoja una opción:");
        System.out.println("1: Registrar nota de estudiante");
        System.out.println("2: Realizar promedio");
        System.out.println("3: Guardar en archivo txt");
        System.out.println("4: Salir");
        Lima_opcMenu = sc.nextInt();

        switch (Lima_opcMenu) { // Estructura switch para manejar las opciones del menú
            case 1:
                Lima_RegisterGrades();
                Lima_menu();//Recursividad
                break;
            case 2:
                Lima_average();
                Lima_menu();
                break;
            case 3:
                Lima_SaveJSON();
                Lima_menu();
                break;
            case 4:
                System.out.println("Gracias por usar el programa, adiós.");
                break;
            default:
                System.out.println("Número incorrecto, intente de nuevo por favor");
                Lima_menu();
        }
    }

    public void Lima_RegisterGrades() {
        Lima_checkRegister = true; // bandera que valida que se ingresó las notas del estudiante
        Scanner sc = new Scanner(System.in);

        System.out.print("Ingrese el nombre del estudiante: ");
        Lima_nom = sc.nextLine();
        sc = new Scanner(System.in);//Reinicio de la función scanner para evitar el salto de línea de nextLine
        System.out.print("Ingrese la nota 1: ");
        Lima_grade1 = Lima_GradeValidation();
        System.out.print("Ingrese la nota 2: ");
        Lima_grade2 = Lima_GradeValidation();
        System.out.print("Ingrese la nota 3: ");
        Lima_grade3 = Lima_GradeValidation();
    }

    public double Lima_GradeValidation() { // Función para validar que el ingreso de notas esté en el rango correcto
        Scanner sc = new Scanner(System.in);
        double Lima_grade;

        Lima_grade = sc.nextDouble();

        while (Lima_grade < 0 || Lima_grade > 20) { // bucle que valida el rango de la nota
            System.out.println("Error del rango numérico, la nota está entre 0-20");
            Lima_grade = sc.nextDouble();
        }

        return Lima_grade; // se retorna la nota
    }

    public void Lima_average() { // Procedimiento para calcular el promedio
        Lima_checkAverage = true; // bandera para confirmar que se realizó el promedio del estudiante
        if (!Lima_checkRegister) { // comprobador de que las notas se han ingresado
            System.out.println("No se encontraron notas disponibles para ser promediadas, ingrese a la primera opción del menú para poder ingresarlas");
        } else {
            Lima_studentAverage = (Lima_grade1 + Lima_grade2 + Lima_grade3) / 3; // cálculo del promedio
            System.out.println("El promedio del estudiante " + Lima_nom + " es de: " + Lima_studentAverage);
        }
    }

    public void Lima_SaveJSON() { // Procedimiento para guardar la información del estudiante en un archivo JSON
        if (!Lima_checkAverage && !Lima_checkRegister) { // Validación de que se registró y promedió las notas del estudiante
            System.out.println("No se encontraron datos para guardar en el archivo, por favor, registre las notas, promedie y luego puede guardar");
            System.out.println();
            Lima_menu();
        } else {
            JSONObject Lima_studentData = new JSONObject();//Intancia un objeto JSON para guardar los datos del estudiante

            Lima_studentData.put("Promedio", Lima_studentAverage);
            Lima_studentData.put("Estado", (Lima_studentAverage >= 14) ? "Aprobado" : "Reprobado");//Estructura condicionada para mostrar si aprobó o no

            try (BufferedWriter Lima_file = new BufferedWriter(new FileWriter("Lima_file.json", true))) { // Se crea el archivo con la modificación de que se puede sobrescribir la información de cada estudiante
                Lima_file.write(Lima_studentData.toString());
                Lima_file.newLine();
            } catch (IOException e) {//Maneja el error que se pueda causar al momento de llenar el archivo
                e.printStackTrace();//Imprime el error en particular que se generó
                Lima_menu();
            }

            System.out.println("El archivo se guardó correctamente");

            /*Reincio de banderas*/
            Lima_checkAverage = false;
            Lima_checkRegister = false;
        }
    }
}
