import java.util.Scanner;
import java.util.ArrayList;

class Restaurante{
	private ArrayList<Mesa> mesas; 
	private ArrayList<SolicitudReserva> solicitudesReservas; 
	
	Restaurante(){
		mesas = new ArrayList<Mesa>(); 
		solicitudesReservas = new ArrayList<SolicitudReserva>(); 
	}
	//OTROS METODOS 
	public void leeMesas(Scanner archivo){
		Mesa mesa; 
		String tipoMesa; 
		
		while(archivo.hasNext()){
			tipoMesa = archivo.next(); 
			if(tipoMesa.compareTo("FIN")==0){
				//termina la iteraticva
				break;
			}else if(tipoMesa.compareTo("R")==0){
				mesa = new MesaRegular(); 
			}else{
				mesa = new MesaPremium(); 
			}
			mesa.leerDatos(archivo); 
			//asignamos la mesa al ArrayList
			mesas.add(mesa); 
		}
	}
	
	public void leeSolicitudes(Scanner arch){
		String tipo; 
		SolicitudReserva soli; 
		
		while(arch.hasNext()){
			tipo = arch.next(); 
			if(tipo.compareTo("R")==0){
				soli = new SolicitudReservaRegular();
			}else if(tipo.compareTo("C")==0){
				soli = new SolicitudReservaConRestricciones();
			}else{ //p 
				soli = new SolicitudReservaPremium();
			}
			//lee
			soli.leeDatos(arch); 
			//añade a una mesa 
			if(reservaSegunReserva(soli)){
				 //actualizamos el estado de la reserva 
				 soli.SetEstado('A'); //APROBADO
			}else{
				soli.SetEstado('R'); //RECHAZADO
			}
			//anñadimos la reserva 
			solicitudesReservas.add(soli);
		}
	}
	
	public boolean reservaSegunReserva(SolicitudReserva soli){
		//esta funcion verifica la disponibilidad 
		char tipoRes = soli.GetTipo(); 
		
		
		
		
		
		return false; 
	}
	
	
	
	//public abstract char GetTipo(); 
	// public double GetHora(){ 
		// return hora;
	// }
	// public char GetUbicacionDeseada(){ 
		// return ubicacionDeseada; 
	// }
	// public char GetOcasion(){ 
		// return ocasion; 
	// }
	// public int GetCantidadPersonas(){
		// return cantidadPersonas; 
	// }
}