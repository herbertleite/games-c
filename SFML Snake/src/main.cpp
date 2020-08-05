#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <windows.h>
#include <list>
#include <iostream>
using namespace std;

const int XTAM = 66, YTAM = 40;
const int SZ = 12;

struct Punto{
    int x, y;
};


void cuadrado ( Punto &p,  sf::RenderWindow &laventana ){
    sf::RectangleShape rectangle;
    
    rectangle.setPosition ( p.x*SZ, p.y*SZ ); 	
	rectangle.setSize ( sf::Vector2f ( SZ-1, SZ-1) );  // *_*   

	rectangle.setFillColor(sf::Color::Red);	
	
	laventana.draw(rectangle);
}

bool colision( const Punto &cabeza, const list<Punto>& cola ){
    if( cabeza.x >= XTAM || cabeza.x < 0 ){
        return true;        
    } 
    if( cabeza.y >= YTAM || cabeza.y < 0 ) {
        return true;
    }
    list<Punto>::const_iterator it;
    for( it = cola.begin(); it != cola.end(); it++ ){
        if( cabeza.x == it->x && cabeza.y == it->y ){
            return true;            
        }
    }
    return false;
}

Punto aleatorio(){
    Punto p = { rand() % XTAM, rand() & YTAM } ;
    return p;
}


int main() {
    sf::RenderWindow window ( sf::VideoMode ( XTAM * SZ, YTAM * SZ, 32 ), "SFML APP" );
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    Punto cabeza = {XTAM/2, YTAM/2}; //cabeza, punto salida
    Punto comida = aleatorio();
    Punto temp = {0, 0};  
    int vx = 1, vy = 0;         //Velocidad
    int engorda = 0;
    bool choque = false;
    list<Punto> cola;
    int retraso = 0;
    while ( window.isOpen() && !choque ) {
        retraso++;
                    
        sf::Event tecla;
		while ( window.pollEvent ( tecla ) ) {
			switch ( tecla.type ) {
                case sf::Event::Closed:
                    std::cout << "Fin de juego!" << std::endl;
					window.close();
					break;
				case sf::Event::KeyPressed:
                    if(tecla.key.code == sf::Keyboard::Up )
                        vx = 0, vy = -1;
                    else if(tecla.key.code == sf::Keyboard::Down )
                        vx = 0, vy = +1;
                    else if(tecla.key.code == sf::Keyboard::Left )
                        vx = -1, vy = 0;
                    else if(tecla.key.code == sf::Keyboard::Right )
                        vx = +1, vy = 0;
                    else if(tecla.key.code == sf::Keyboard::Space )
                        engorda = 1;
                    break;
				default:
                    break;
			}
			
		}        
		window.clear ();
		if ( retraso == 7 ) {
            cola.push_front(cabeza);    
            if ( engorda > 0 ){
                engorda --;            
            }else{
                cola.pop_back();
            }
            

			cabeza.x = cabeza.x + vx;
			cabeza.y = cabeza.y + vy;
			
			if ( colision( cabeza, cola) ) {
                choque = true;
			} else if (cabeza.x == comida.x && cabeza.y == comida.y){
                engorda = 1;
                comida = aleatorio();
                while ( colision(comida, cola) || comida.x == cabeza.x && comida.y == cabeza.y ){
                    comida = aleatorio();
                }
			}
			
			retraso = 0;
		}
		
		if ( !choque ) {
		
			list<Punto>::const_iterator it;
			
			for ( it = cola.begin(); it != cola.end(); it++ ) {
				temp = *it;
				cuadrado ( temp, window );
			}
			
			cuadrado ( cabeza, window );
			cuadrado (comida, window );
			window.display();
		}
    }//END BUCLE

    //return EXIT_SUCCESS;
}
