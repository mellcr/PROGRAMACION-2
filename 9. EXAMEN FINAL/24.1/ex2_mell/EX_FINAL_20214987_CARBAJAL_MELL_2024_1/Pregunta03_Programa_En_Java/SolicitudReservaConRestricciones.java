import java.util.Scanner;
import java.util.ArrayList;

class SolicitudReservaConRestricciones extends SolicitudReserva{
	private ArrayList<String> alergias; 
	private int numeroDeAlergias; 
	
	SolicitudReservaConRestricciones(){
		numeroDeAlergias = 0; 
		alergias = new ArrayList<String>(); 
	}
	
	//OTROS METODOSSSSS
	@Override
	public void leeDatos(Scanner arch){
		String UbiDeseada,oca, alerg; 
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
		
		numeroDeAlergias =arch.nextInt(); 
		for(int i=0; i<numeroDeAlergias; i++){
			alerg = arch.next(); 
			alergias.add(alerg); 
		}
	}
	
	@Override
	public char GetTipo(){
		char tipo = 'C'; 
		return tipo; 
	}
	
}