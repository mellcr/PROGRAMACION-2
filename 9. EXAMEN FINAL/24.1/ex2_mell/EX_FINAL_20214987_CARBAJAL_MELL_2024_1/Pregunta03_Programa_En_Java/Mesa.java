import java.util.Scanner;
import java.util.ArrayList;

abstract class Mesa{
	private String codigo;
	private String ubicacion;
	private int capacidad;
	private boolean ocupadaPrimerTurno; //¿ocupada para primer turno?
	
	//CONSTRUCTOR -> no tiene , es abstract
	// Mesa(){
		// ocupadaPrimerTurno = false; 
	// }
	
	//METODOS SELECTORES
	
	//OTROS METODOS 
	// public abstract void metodo(){
		
	// }
	public void leerDatos(Scanner arch){
		codigo = arch.next();
		ubicacion = arch.next();
		capacidad = arch.nextInt(); 
		
	}
	
	
}