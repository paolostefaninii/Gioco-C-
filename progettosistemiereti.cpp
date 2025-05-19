#include <curses.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h> // Necessario per la funzione usleep()

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int ch;
    char playerc = 'O';
    char nemico = '£'; //carattere scelto per migliorare l'interffaccia grafica del gioco
    char nemico2 = '£';
    char nemico3 = '£';
    char nemico4 = '£';
    char nemico5 = '£';
    char nemico6 = '£';
    char bersagli = '*';
	char bersagli1 = '*';
	char bersagli2 = '*';
	char bersagli3 = '*';
    char emptyc = ' ';
    int x, y;  // Posizione iniziale del giocatore
    int my, mx;
    int nx, ny, nx2, ny2, nx3, ny3, nx4, ny4, nx5, ny5, nx6, ny6;
    int vite = 3;
    int direction;
    int bx, by, bx1, by1, bx2, by2, bx3, by3;
    int punteggio = 0;

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);
    refresh();

    // Ottieni le dimensioni della finestra
    getmaxyx(stdscr, my, mx);

    // Calcola la posizione iniziale centrale del giocatore
    x = mx / 2;
    y = my / 2;

    // Disegna il bordo
    box(stdscr, 0, 0);
    refresh();

    // Posiziona il giocatore al centro
    mvaddch(y, x, playerc);

    // Posiziona il nemico in una posizione casuale all'interno del bordo
    nx = rand() % (mx - 2) + 1;
    ny = rand() % (my - 2) + 1;
    mvaddch(ny, nx, nemico);
    
    nx2 = rand() % (mx - 2) + 1;
    ny2 = rand() % (my - 2) + 1;
    mvaddch(ny2, nx2, nemico2);
    
    nx3 = rand() % (mx - 2) + 1;
    ny3 = rand() % (my - 2) + 1;
    mvaddch(ny3, nx3, nemico3);
    
    nx4 = rand() % (mx - 2) + 1;
    ny4 = rand() % (my - 2) + 1;
    mvaddch(ny4, nx4, nemico4);
    
    nx5 = rand() % (mx - 2) + 1;
    ny5 = rand() % (my - 2) + 1;
    mvaddch(ny5, nx5, nemico5);
    
    nx6 = rand() % (mx - 2) + 1;
    ny6 = rand() % (my - 2) + 1;
    mvaddch(ny6, nx6, nemico6);

    // Posiziona il bersaglio in una posizione casuale all'interno del bordo
    bx = rand() % (mx - 2) + 1;
    by = rand() % (my - 2) + 1;
    mvaddch(by, bx, bersagli);
    
    bx1 = rand() % (mx - 2) + 1;
    by1 = rand() % (my - 2) + 1;
    mvaddch(by1, bx1, bersagli1); 
	
    bx2 = rand() % (mx - 2) + 1;
    by2 = rand() % (my - 2) + 1;
    mvaddch(by2, bx2, bersagli2); 
	
    bx3 = rand() % (mx - 2) + 1;
    by3 = rand() % (my - 2) + 1;
    mvaddch(by3, bx3, bersagli3); 

    // Posiziona punteggio e vite all'interno del bordo
    mvprintw(1, 2, "Punteggio: %d", punteggio);
    mvprintw(1, mx - 20, "Vite rimaste: %d", vite);

    // Imposta timeout per getch() per permettere aggiornamenti continui
    timeout(100); // Timeout di 100 ms

    while (vite > 0) {
        // Movimento del giocatore con input
        ch = getch();
        // Cancella la posizione precedente del giocatore
        mvaddch(y, x, emptyc);

        // Aggiorna la posizione del giocatore in base all'input, rispettando i bordi
        if (ch == KEY_LEFT && x > 1) x--;
        else if (ch == KEY_RIGHT && x < mx - 2) x++;
        else if (ch == KEY_UP && y > 1) y--;  // Evita la riga 1 dove ci sono le informazioni
        else if (ch == KEY_DOWN && y < my - 2) y++;

        // Riposiziona il giocatore
        mvaddch(y, x, playerc);

        // Movimento del nemico
        mvaddch(ny, nx, emptyc); // Cancella nemico precedente
        direction = rand() % 4 + 1;
        switch (direction) {
            case 1: if (nx < mx - 2) nx++; break; // Destra
            case 2: if (nx > 1) nx--; break;      // Sinistra
            case 3: if (ny < my - 2) ny++; break; // Giù
            case 4: if (ny > 1) ny--; break;      // Su
        }
        mvaddch(ny, nx, nemico); // Riposiziona il nemico
        
        
        // Movimento del nemico2
        mvaddch(ny2, nx2, emptyc); // Cancella nemico precedente
        direction = rand() % 4 + 1;
        switch (direction) {
            case 1: if (nx2 < mx - 2) nx2++; break; // Destra
            case 2: if (nx2 > 1) nx2--; break;      // Sinistra
            case 3: if (ny2 < my - 2) ny2++; break; // Giù
            case 4: if (ny2 > 1) ny2--; break;      // Su
        }
        mvaddch(ny2, nx2, nemico2); // Riposiziona il nemico
        
        // Movimento del nemico3
        mvaddch(ny3, nx3, emptyc); // Cancella nemico precedente
        direction = rand() % 4 + 1;
        switch (direction) {
            case 1: if (nx3 < mx - 2) nx3++; break; // Destra
            case 2: if (nx3> 1) nx3--; break;      // Sinistra
            case 3: if (ny3 < my - 2) ny3++; break; // Giù
            case 4: if (ny3 > 1) ny3--; break;      // Su
        }
        mvaddch(ny3, nx3, nemico3); // Riposiziona il nemico
        
         // Movimento del nemico4
        mvaddch(ny4, nx4, emptyc); // Cancella nemico precedente
        direction = rand() % 4 + 1;
        switch (direction) {
            case 1: if (nx4 < mx - 2) nx4++; break; // Destra
            case 2: if (nx4> 1) nx4--; break;      // Sinistra
            case 3: if (ny4 < my - 2) ny4++; break; // Giù
            case 4: if (ny4 > 1) ny4--; break;      // Su
        }
        mvaddch(ny4, nx4, nemico4); // Riposiziona il nemico
        
         // Movimento del nemico5
        mvaddch(ny5, nx5, emptyc); // Cancella nemico precedente
        direction = rand() % 4 + 1;
        switch (direction) {
            case 1: if (nx5 < mx - 2) nx5++; break; // Destra
            case 2: if (nx5> 1) nx5--; break;      // Sinistra
            case 3: if (ny5 < my - 2) ny5++; break; // Giù
            case 4: if (ny5 > 1) ny5--; break;      // Su
        }
        mvaddch(ny5, nx5, nemico5); // Riposiziona il nemico
        
        // Movimento del nemico3
        mvaddch(ny6, nx6, emptyc); // Cancella nemico precedente
        direction = rand() % 4 + 1;
        switch (direction) {
            case 1: if (nx6 < mx - 2) nx6++; break; // Destra
            case 2: if (nx6> 1) nx6--; break;      // Sinistra
            case 3: if (ny6 < my - 2) ny6++; break; // Giù
            case 4: if (ny6 > 1) ny6--; break;      // Su
        }
        mvaddch(ny6, nx6, nemico6); // Riposiziona il nemico

        // Controlla collisione nemico
        if (ny == y && nx == x) {
            vite--;
            mvprintw(1, mx - 20, "Vite rimaste: %d", vite); // Aggiorna vite rimanenti
            // Ripristina il giocatore in una posizione iniziale dopo la collisione
            mvaddch(y, x, emptyc);
            y = my / 2;
            x = mx / 2;
            mvaddch(y, x, playerc);
        }
        
        
        // Controlla collisione nemico numeroc 2
        if (ny2 == y && nx2 == x) {
            vite--;
            mvprintw(1, mx - 20, "Vite rimaste: %d", vite); // Aggiorna vite rimanenti
            // Ripristina il giocatore in una posizione iniziale dopo la collisione
            mvaddch(y, x, emptyc);
            y = my / 2;
            x = mx / 2;
            mvaddch(y, x, playerc);
        }

		// Controlla collisione nemico NUMERO 3
        if (ny3 == y && nx3 == x) {
            vite--;
            mvprintw(1, mx - 20, "Vite rimaste: %d", vite); // Aggiorna vite rimanenti
            // Ripristina il giocatore in una posizione iniziale dopo la collisione
            mvaddch(y, x, emptyc);
            y = my / 2;
            x = mx / 2;
            mvaddch(y, x, playerc);
        }
        
        // Controlla collisione nemico NUMERO 4
        if (ny4 == y && nx4 == x) {
            vite--;
            mvprintw(1, mx - 20, "Vite rimaste: %d", vite); // Aggiorna vite rimanenti
            // Ripristina il giocatore in una posizione iniziale dopo la collisione
            mvaddch(y, x, emptyc);
            y = my / 2;
            x = mx / 2;
            mvaddch(y, x, playerc);
        }
        
        // Controlla collisione nemico NUMERO 5
        if (ny5 == y && nx5 == x) {
            vite--;
            mvprintw(1, mx - 20, "Vite rimaste: %d", vite); // Aggiorna vite rimanenti
            // Ripristina il giocatore in una posizione iniziale dopo la collisione
            mvaddch(y, x, emptyc);
            y = my / 2;
            x = mx / 2;
            mvaddch(y, x, playerc);
        }
        
        // Controlla collisione nemico NUMERO 5
        if (ny6 == y && nx6 == x) {
            vite--;
            mvprintw(1, mx - 20, "Vite rimaste: %d", vite); // Aggiorna vite rimanenti
            // Ripristina il giocatore in una posizione iniziale dopo la collisione
            mvaddch(y, x, emptyc);
            y = my / 2;
            x = mx / 2;
            mvaddch(y, x, playerc);
            }
        
        // Controlla raccolta bersaglio
        if (by == y && bx == x) {
            punteggio += 10;
            mvprintw(1, 2, "Punteggio: %d", punteggio); // Aggiorna il punteggio
            // Cancella il bersaglio precedente
            mvaddch(by, bx, emptyc);
            // Genera una nuova posizione per il bersaglio
            do {
                bx = rand() % (mx - 2) + 1;
                by = rand() % (my - 2) + 1;
            } while ((bx == x && by == y) || (bx == nx && by == ny)); // Evita di posizionare il bersaglio sul giocatore o sul nemico
            mvaddch(by, bx, bersagli); // Posiziona il nuovo bersaglio
        }
        
        // Controlla raccolta bersaglio
        if (by1 == y && bx1 == x) {
            punteggio += 10;
            mvprintw(1, 2, "Punteggio: %d", punteggio); // Aggiorna il punteggio
            // Cancella il bersaglio precedente
            mvaddch(by1, bx1, emptyc);
            // Genera una nuova posizione per il bersaglio
            do {
                bx1 = rand() % (mx - 2) + 1;
                by1 = rand() % (my - 2) + 1;
            } while ((bx1 == x && by1 == y) || (bx1 == nx2 && by1 == ny2)); // Evita di posizionare il bersaglio sul giocatore o sul nemico
            mvaddch(by1, bx1, bersagli); // Posiziona il nuovo bersaglio
        }
        
        // Controlla raccolta bersaglio
        if (by2 == y && bx2 == x) {
            punteggio += 10;
            mvprintw(1, 2, "Punteggio: %d", punteggio); // Aggiorna il punteggio
            // Cancella il bersaglio precedente
            mvaddch(by2, bx2, emptyc);
            // Genera una nuova posizione per il bersaglio
            do {
                bx2 = rand() % (mx - 2) + 1;
                by2 = rand() % (my - 2) + 1;
            } while ((bx2 == x && by2 == y) || (bx2 == nx3 && by2 == ny3)); // Evita di posizionare il bersaglio sul giocatore o sul nemico
            mvaddch(by2, bx2, bersagli); // Posiziona il nuovo bersaglio
        }
        
        // Controlla raccolta bersaglio
        if (by3 == y && bx3 == x) {
            punteggio += 10;
            mvprintw(1, 2, "Punteggio: %d", punteggio); // Aggiorna il punteggio
            // Cancella il bersaglio precedente
            mvaddch(by3, bx3, emptyc);
            // Genera una nuova posizione per il bersaglio
            do {
                bx3 = rand() % (mx - 2) + 1;
                by3 = rand() % (my - 2) + 1;
            } while ((bx3 == x && by3 == y) || (bx3 == nx4 && by3 == ny4)); // Evita di posizionare il bersaglio sul giocatore o sul nemico
            mvaddch(by3, bx3, bersagli); // Posiziona il nuovo bersaglio
        }
        
        if (nx == bx1 && ny==by1 || nx2 == bx1 && ny2==by1 || nx3 == bx1 && ny3==by1 ||nx4 == bx1 && ny4==by1 ||nx5 == bx1 && ny5==by1 ||nx6 == bx1 && ny6==by1)
        {
            mvaddch(by1, bx1, emptyc);
            // Genera una nuova posizione per il bersaglio
            do {
                bx1 = rand() % (mx - 2) + 1;
                by1 = rand() % (my - 2) + 1;
            } while ((bx1 == x && by1 == y)); // Evita di posizionare il bersaglio sul giocatore o sul nemico
            mvaddch(by1, bx1, bersagli); // Posiziona il nuovo bersaglio
        }

        if (nx == bx2 && ny==by2 || nx2 == bx2 && ny2==by2 || nx3 == bx2 && ny3==by2 ||nx4 == bx2 && ny4==by2 ||nx5 == bx2 && ny5==by2 ||nx6 == bx2 && ny6==by2)
        {
            mvaddch(by2, bx2, emptyc);
            // Genera una nuova posizione per il bersaglio
            do {
                bx2 = rand() % (mx - 2) + 1;
                by2 = rand() % (my - 2) + 1;
            } while ((bx2 == x && by2 == y)); // Evita di posizionare il bersaglio sul giocatore o sul nemico
            mvaddch(by2, bx2, bersagli); // Posiziona il nuovo bersaglio
        }
        
        if (nx == bx3 && ny==by3 || nx2 == bx3 && ny2==by3 || nx3 == bx3 && ny3==by3 ||nx4 == bx3 && ny4==by3 ||nx5 == bx3 && ny5==by3 ||nx6 == bx3 && ny6==by3)
        {
            mvaddch(by3, bx3, emptyc);
            // Genera una nuova posizione per il bersaglio
            do {
                bx3 = rand() % (mx - 2) + 1;
                by3 = rand() % (my - 2) + 1;
            } while ((bx3 == x && by3 == y)); // Evita di posizionare il bersaglio sul giocatore o sul nemico
            mvaddch(by3, bx3, bersagli); // Posiziona il nuovo bersaglio
        }
        mvprintw(1, 2, "Punteggio: %d", punteggio);
        mvprintw(1, mx - 20, "Vite rimaste: %d", vite);
    
        // Ridisegna il bordo
        box(stdscr, 0, 0);

        refresh();
        usleep(100000); // Pausa di 100 ms
    }

    // Mostra il messaggio di fine gioco
    mvprintw(my / 2, (mx / 2) - 10, "Game Over! Punteggio: %d", punteggio);
    refresh();
    getch(); // Aspetta un input prima di chiudere

    endwin();
    return 0;
}
