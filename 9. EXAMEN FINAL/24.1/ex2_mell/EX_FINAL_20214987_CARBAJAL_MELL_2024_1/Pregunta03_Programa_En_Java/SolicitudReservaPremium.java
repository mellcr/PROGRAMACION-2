import java.util.Scanner;
import java.util.ArrayList;

class SolicitudReservaPremium extends SolicitudReserva{
	private ArrayList<String> amenidades; 
	private int numeroDeAmenidades; 
	
	SolicitudReservaPremium(){
		amenidades = new ArrayList<String>(); 
	}
	
	//OTROS METODOSSSSS
	@Override
	public void leeDatos(Scanner arch){
		String UbiDeseada,oca, amen; 
		int cantPer; 
		super.leeDatos(arch); 
		
		cantPer = arch.nextInt(); 
		super.SetCantidadPersonas(cantPer); 
		
		oca = arch.next(); 
		super.SetUbicacionDeseada(oca);
		
		while(arch.hasNextInt()){
			amen = arch.next(); 
			amenidades.add(amen); 
		}
		numeroDeAmenidades  = arch.nextInt(); 
	}
	
	@Override
	public char GetTipo(){
		char tipo = 'P'; 
		return tipo; 
	}
}