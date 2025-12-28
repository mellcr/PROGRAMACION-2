import java.util.Scanner;

class ProgramaArchivo {
    public static void main(String []arg) {
        Scanner arch = new Scanner(System.in);//definir un archivo del tipo scanner
        int dni;
        String nombre, aux;
        double sueldo;
        char sexo;
        
        while (arch.hasNext()) { //si hay una linea siguiente
            dni = arch.nextInt();
            aux = arch.next();//lo jala como un string
            sexo = aux.charAt(0); //solo me interesa el primer caracter, para trabajarlo como char xd (opcional)
            nombre = arch.next();//string -> solamente next()
            sueldo = arch.nextDouble();
            System.out.printf("%10d %5c %-50s %10.2f\n", dni, sexo, nombre, sueldo);
        }
    }
}
