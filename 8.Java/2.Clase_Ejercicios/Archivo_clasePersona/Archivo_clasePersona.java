import java.util.Scanner;

class Archivo_clasePersona{
    public static void main(String []arg) {
		//definir un archivo del tipo scanner
        Scanner arch = new Scanner(System.in);
		// instanciar clase persona
		Persona persona = new Persona();
		
        while (arch.hasNext()) { //si hay una linea siguiente
			persona.leerDatos(arch);
			persona.imprimirDatos();    
        }
    }
}
