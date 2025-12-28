import java.util.Scanner; 
import java.util.ArrayList;

class ListaAlumnos{
	//lista de alumnos 
	private ArrayList<Alumno> listaAlumnos; 
	
	public ListaAlumnos(){
		listaAlumnos = new ArrayList<Alumno>();
	}
	
	//METODOS SELECTORES
	
	// OTROS METODOS 
	public void leerDatos(){
		Scanner arch = new Scanner(System.in); 
		String tipoAlum; 
		Alumno alum; 
		
		while(arch.hasNext()){
			tipoAlum = arch.next(); 
			if(tipoAlum.compareTo("R")==0){
				alum = new AlumnoRegular();
			}else{
				alum = new AlumnoIntercambio();
			}
			
			alum.leerAlumno(arch); //leo
			listaAlumnos.add(alum);//añado a la lista
		}
	}
	
	public void imprimeDatos(){
		for(Alumno al: listaAlumnos){
			al.imprimeAlumno(); 
		}
	}
}