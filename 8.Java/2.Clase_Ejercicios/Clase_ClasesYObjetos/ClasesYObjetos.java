//array list -> no se puede poner la lista del tipo int 
// int , double datos primitivos
// SE USA: integer variable 

//cada clase en un archivo distinto 

class ClasesYObjetos{
	public static void main(String []arg){
		//como esta en el mismo directorio(carpeta), se hace automaticamente el #include
		Persona persona;
		Persona persona2=new Persona(); //llama al const por defecto
		Persona persona3; //=new Persona(); no es necesario 
		
		//damos espacio de memoria pq es un puntero y usamos el const por parametros
		persona = new Persona(76284769,"Dri",2020.20);
		persona.imprimirDatos();
		
		persona2.SetDni(20284769);
		persona2.SetNombre("BeeYhonguito");
		persona2.SetSueldo(2020.22);
		persona2.imprimirDatos();
		
		persona3=persona2;         // SON PUNTEROS 
		persona3.imprimirDatos();
		persona3.SetDni(20202020); //apunta al mismo sitio-> cambia uno cambia el otro 
		System.out.println("Prueba datos cambiado");
		persona2.imprimirDatos();
		persona3.imprimirDatos();
		
		Persona persona4 = new Persona(persona2);
		System.out.println("Constructor copia");
		persona4.SetNombre("Soy la copia");
		persona4.imprimirDatos();
	}
}