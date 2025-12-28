import java.util.Scanner;
import java.util.ArrayList; //funciona similar al vector 
import java.util.Comparator; // (NO viene) para ordenar los datos

class ListaDePersonas{
	//				   tipo      nombre
	private ArrayList <Persona> listaPersonas;
	
	public ListaDePersonas(){ //constructor
		listaPersonas = new ArrayList <Persona>();
	}
	
	public void leerPersonas(){
		Scanner arch = new Scanner(System.in);
		Persona persona; // *pt
		
		while(arch.hasNext()){
			//*pt -> instanciarlo pq son datos distintos en cada iteracion
			persona = new Persona();
			persona.leerDatos(arch); 
			listaPersonas.add(persona);
		}
	}
	
	public void mostrarDatos(){
		// for each
		for(Persona per:listaPersonas){
			per.imprimirDatos();
		}
	}
	
	public void ordenar(){
		//                                     GetDni sin()
		listaPersonas.sort(
					Comparator.comparing(Persona::GetDni)
						.thenComparing(Persona::GetNombre)
		);
	}
}