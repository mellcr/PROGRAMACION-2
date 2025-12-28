public class PrimerPrograma{
	public static void main(String []args){
		int a=23; 
		double x=123.45;
		String nombre = "Mell Alessandra";
		boolean activo = true;
		//println -> pasa automaticamente a la sgte linea
		//System.out.println("Es mi primer programa:)");
		System.out.println("Es mi primer programa:)");
		System.out.println("A="+a);
		
		//permite darle formato , \n pasa a la sgte linea 
		System.out.printf("%10.2f\n",x);
		//cout<<left<<setw(10)<<"Mell"<<endl;
		System.out.printf("%-10s\n","Mell"); 
		
		//compareTo -> compara 2 strings 
		int cmp = nombre.compareTo("Dri");
		if(cmp ==0) System.out.printf("%-10s\n","Iguales"); 
		else if(cmp>0) System.out.printf("%-10s\n","Nombre mayor");
		else System.out.printf("%-10s\n","Nombre es menor"); 
	}
}