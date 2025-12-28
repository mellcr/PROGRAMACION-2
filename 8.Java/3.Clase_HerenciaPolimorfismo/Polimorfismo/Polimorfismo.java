import java.util.ArrayList; 

class Polimorfismo{
	public static void main(String []arg){
		//definir cuadrado 
		Cuadrado c1 = new Cuadrado("C01",45.76,25.32); 
		Cuadrado c2 = new Cuadrado("C02",5,20); 
		Cuadrado c3 = new Cuadrado("C03",12.98,23.88); 
		
		Triangulo t1 = new Triangulo("T01",5,10);
		Triangulo t2 = new Triangulo("T02",8.34,5.11);	
		
		//		tipo     nombre
		ArrayList<Figura>figuras = new ArrayList<>(); 
		figuras.add(c3);
		figuras.add(t1);
		figuras.add(c1);
		figuras.add(t2);
		figuras.add(c2);
		
		//mostramos 
		for(Figura f:figuras){
			//System.out.printf("Base: %.2f\n",f.GetBase());
			f.CalcularArea();
		}
	}
}