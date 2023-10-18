#include <GL/glut.h>
#include <cmath>

int xa, ya, xb, yb;

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void bresenhamLine(int xa, int ya, int xb, int yb) {
    int dx = abs(xb - xa);
    int dy = abs(yb - ya);
    int x, y;
    int p;

    if (xa < xb) {
        x = xa;
        y = ya;
    } else {
        x = xb;
        y = yb;
        xb = xa;
        yb = ya;
    }

    drawPixel(x, y);

    if (dx > dy) {
        p = 2 * dy - dx;
        for (x; x < xb; x++) {
            if (p >= 0) {
                y += (ya < yb ? 1 : -1);
                p -= 2 * dx;
            }
            p += 2 * dy;
            drawPixel(x, y);
        }
    } else {
        p = 2 * dx - dy;
        for (y; y < yb; y++) {
            if (p >= 0) {
                x += (xa < xb ? 1 : -1);
                p -= 2 * dy;
            }
            p += 2 * dx;
            drawPixel(x, y);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Warna garis putih
    bresenhamLine(xa, ya, xb, yb);
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Warna latar belakang hitam
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line Drawing Algorithm (12475)");
    init();

    // Masukkan koordinat titik A dan B di sini
    xa = 100;
    ya = 200;
    xb = 400;
    yb = 500;

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}