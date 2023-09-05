/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package entidad;

import java.util.Scanner;

/**
 *
 * @author Usuario
 */
public class cancion {
    private String titulo,autor;
    Scanner input = new Scanner(System.in);

    public cancion(String titulo, String autor) {
        this.titulo = titulo;
        this.autor = autor;
    }

    public cancion() {
        titulo=" ";
        autor=" ";
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }
    
    public void crearCancion(){
        System.out.println("ingrese el titulo de la cancion");
        titulo=input.next();
        System.out.println("ingrese el autor de la cancion");
        autor=input.next();      
        
    }
    
    public String toString(){
        return "el titulo es "+titulo+" y el autor es "+autor;
    }
    
}
