import java.util.Scanner;
import java.util.ArrayList;

class MesaRegular extends Mesa{
	private String camarera; 
	private boolean ocupadaSegundoTurno; 
	
	MesaRegular(){
		ocupadaSegundoTurno = false; 
	}
	//OTROS METODOS
	@Override
	public void leerDatos(Scanner arch){
		super.leerDatos(arch); 
		camarera = arch.next(); 
		
	}
}