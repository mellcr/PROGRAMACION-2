
class Herencia{
	public static void main(String []arg){
		//creacion de un circulo 
		Circulo circulo = new Circulo("CirculoA",56.78); 
		System.out.printf("Objeto : %-15s \nRadio: %10.2f\nArea: %10.2f\nPerimetro: %10.2f\n\n",
			circulo.GetIdentificacion(), circulo.GetRadio(), circulo.area(), circulo.perimetro());
		
		//creacion del cilindro 
		Cilindro cilindro = new Cilindro("CilindroA",213.45,12.7); 
		System.out.printf("Objeto : %-15s \nRadio: %10.2f\nAltura: %10.2f\nArea: %10.2f\nPerimetro: %10.2f\nArea de la base: %10.2f\n\n",
			cilindro.GetIdentificacion(), cilindro.GetRadio(), cilindro.GetAltura(),cilindro.area(), cilindro.perimetro(), cilindro.areaBase());
		
				
	}
}