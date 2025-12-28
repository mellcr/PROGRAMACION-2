import java.util.Scanner;
import java.util.ArrayList;

class MesaPremium extends Mesa{
	private ArrayList<String> camareros; 
	private ArrayList<String> amenidades; 
	private int numeroDeAmenidades; 
	
	MesaPremium(){
		numeroDeAmenidades = 0; 
		camareros = new ArrayList<String>(); 
		amenidades = new ArrayList<String>(); 
	}
	
	//OTROS METODOS
	@Override
	public void leerDatos(Scanner arch){
		super.leerDatos(arch); 
		while(!arch.hasNextInt()){
			String cam; 
			cam=arch.next();
			//asignamos al arralist
			camareros.add(cam); 
		}
		numeroDeAmenidades = arch.nextInt(); 
		for(int i=0; i<numeroDeAmenidades; i++){
			String amenidad; 
			amenidad =arch.next(); 
			amenidades.add(amenidad); 
		}
		
	}
}