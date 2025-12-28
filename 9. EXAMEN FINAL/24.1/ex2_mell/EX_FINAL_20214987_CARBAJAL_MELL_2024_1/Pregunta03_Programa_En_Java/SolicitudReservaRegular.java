import java.util.Scanner;
import java.util.ArrayList;

class SolicitudReservaRegular extends SolicitudReserva{
	//no tiene atributos 
	
	SolicitudReservaRegular(){
		
	}
	// public void SetUbicacionDeseada(String str){
		// ubicacionDeseada = str.charAt(0); 
	// }
	// public void SetiOcasion(String str){
		// ocasion = str.charAt(0); 
	// }
	@Override
	public void leeDatos(Scanner arch){
		String UbiDeseada,oca; 
		int cantPer; 
		double hor; 
		super.leeDatos(arch); 
		
		UbiDeseada = arch.next(); 	
		super.SetUbicacionDeseada(UbiDeseada);
		
		cantPer = arch.nextInt(); 
		super.SetCantidadPersonas(cantPer); 
		
		hor = arch.nextDouble(); 
		super.SetHora(hor); 
		
		oca = arch.next(); 
		super.SetUbicacionDeseada(oca);
	}
	
	@Override
	public char GetTipo(){
		char tipo = 'R'; 
		return tipo; 
	}
	
}