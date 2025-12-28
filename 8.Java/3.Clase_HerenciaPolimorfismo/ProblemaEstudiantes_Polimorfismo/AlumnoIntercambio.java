import java.util.Scanner; 
import java.util.ArrayList; 

class AlumnoIntercambio extends Alumno{
	private String paisOrigen; 
	private ArrayList<String>idiomas;
	int numeroDeSemestres; 
	
	public AlumnoIntercambio(){
		idiomas = new ArrayList<String>();
	}
	//metodos selectores 
	
	//OTROS METODOS 
	@Override
	public void leerAlumno(Scanner arch){
		String idiom; 
		
		super.leerAlumno(arch); 
		paisOrigen = arch.next();
		//lee la lista de idiomas hasta encontrar un numero int 
		while(!arch.hasNextInt()){
			idiom = arch.next(); 
			idiomas.add(idiom); 
		}
		numeroDeSemestres = arch.nextInt();
	}
	
	@Override
	public void imprimeAlumno(){
		super.imprimeAlumno();
		System.out.println("Alumno Intercambio: "); 
		System.out.println("Pais       :" + paisOrigen); 
		System.out.println("Idiomas    : " ); 
		for(int i=0; i<idiomas.size();i++){
			System.out.print(" "+idiomas.get(i));
		}
		System.out.println();
		System.out.println("NumSemest   : " + numeroDeSemestres); 
	}
	
}