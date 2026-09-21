#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
using namespace std;

const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 768;

// Helper function 
void drawBitmapString(void* font, const char* text) {
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void drawText(float x, float y, const char* text,
              void* font = GLUT_BITMAP_HELVETICA_12) {
    glColor3f(0.03f, 0.03f, 0.03f);
    glRasterPos2f(x, y);
    drawBitmapString(font, text);
}

void fillRectangle(float left, float top, float right, float bottom,
                   float red, float green, float blue) {
    glColor3f(red, green, blue);
    glBegin(GL_QUADS);
        glVertex2f(left, top);
        glVertex2f(right, top);
        glVertex2f(right, bottom);
        glVertex2f(left, bottom);
    glEnd();
}

// 
void drawRectangle(float left, float top, float right, float bottom,
                   float red = 0.55f, float green = 0.55f,
                   float blue = 0.55f) {
    glColor3f(red, green, blue);
    glBegin(GL_LINE_LOOP);
        glVertex2f(left, top);
        glVertex2f(right, top);
        glVertex2f(right, bottom);
        glVertex2f(left, bottom);
    glEnd();
}

void display() {
    glClearColor(0.85f, 0.95f, 0.85f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Student information.
    fillRectangle(0.0f, 0.0f, WINDOW_WIDTH, 6.0f,
                  0.07f, 0.16f, 0.25f);
    drawText(25.0f, 35.0f, "STUDENT INFORMATION",
             GLUT_BITMAP_HELVETICA_18);
    fillRectangle(25.0f, 47.0f, 999.0f, 50.0f,
                  0.10f, 0.67f, 0.61f);

    drawText(25.0f, 72.0f, "Enrollment Status : ENROLLED");
    drawText(25.0f, 93.0f, "Student # : 202410180");
    drawText(25.0f, 114.0f, "Name : RUIZ, JOSHUA DANREI CANTAL");
    drawText(25.0f, 135.0f,
             "Phone : +639053054898    Zip Code : 1128");
    drawText(25.0f, 156.0f, "Classification :");

    drawText(520.0f, 72.0f,
             "College : COMPUTER STUDIES    Program : BSCSSE");
    drawText(520.0f, 93.0f,
             "Year Level : 3    1st term, SY 26-27");
    drawText(520.0f, 114.0f, "Address : 2- LANDS STREET");

    drawText(25.0f, 194.0f, "CLASS SCHEDULE",
             GLUT_BITMAP_HELVETICA_18);
    drawText(805.0f, 194.0f, "1ST TERM  |  SY 2026-2027");

    // Course table.
    const float tableLeft = 25.0f;
    const float tableRight = 999.0f;
    const float tableTop = 210.0f;
    const float headerBottom = 244.0f;
    const float rowHeight = 38.0f;

    fillRectangle(tableLeft, tableTop, tableRight, headerBottom,
                  0.12f, 0.23f, 0.33f);

    const char* headings[] = {
        "COURSE", "TITLE", "SECTION", "UNITS",
        "DAYS", "TIME", "ROOM"
    };
    const float columns[] = {
        36.0f, 100.0f, 475.0f, 535.0f,
        590.0f, 665.0f, 910.0f
    };

    for (int i = 0; i < 7; i++) {
        glColor3f(1.0f, 1.0f, 1.0f);
        glRasterPos2f(columns[i], 232.0f);
        drawBitmapString(GLUT_BITMAP_HELVETICA_10, headings[i]);
    }

    const char* courses[6][7] = {
        {"CS0011", "MOBILE PROGRAMMING", "TN35", "3", "M / W",
         "11:00:00-12:50:00 / 11:00:00-12:50:00", "F608 / F1209"},
        {"CS0016", "NETWORK AND COMMUNICATIONS 2A", "TN35", "3", "T / W",
         "17:00:00-18:50:00 / 17:00:00-18:50:00", "ONLINE / F1101"},
        {"CS0019", "MODELING AND SIMULATION", "TN35", "3", "F / T",
         "11:00:00-12:50:00 / 11:00:00-12:50:00", "ONLINE / ONLINE"},
        {"CS0025", "SOFTWARE ENGINEERING 1", "TN35", "3", "F / TH",
         "15:00:00-16:50:00 / 15:00:00-16:50:00", "ONLINE / E609"},
        {"CS0045", "CS ELECTIVE - COMPUTER GRAPHICS AND VISUAL COMPUTING",
         "TN35", "3", "M / TH",
         "13:00:00-14:50:00 / 13:00:00-14:50:00", "E601 / E610"},
        {"CS0053", "CS SPECIALIZATION 2 - PROGRAMMING TOOLS AND TECHNIQUES",
         "TN35", "3", "M / TH",
         "07:00:00-08:50:00 / 07:00:00-08:50:00", "F702 / F609"}
    };

    for (int row = 0; row < 6; row++) {
        const float top = headerBottom + row * rowHeight;
        const float bottom = top + rowHeight;

        if (row % 2 == 1) {
            fillRectangle(tableLeft, top, tableRight, bottom,
                          0.93f, 0.95f, 0.95f);
        } else {
            fillRectangle(tableLeft, top, tableRight, bottom,
                          1.0f, 1.0f, 1.0f);
        }

        const float textY = top + 24.0f;
        for (int column = 0; column < 7; column++) {
            drawText(columns[column], textY, courses[row][column],
                     GLUT_BITMAP_HELVETICA_10);
        }
    }

    const float totalTop = headerBottom + 6 * rowHeight;
    fillRectangle(tableLeft, totalTop, tableRight, totalTop + 34.0f,
                  0.88f, 0.93f, 0.93f);
    drawText(36.0f, totalTop + 22.0f, "TOTAL UNITS: 18");
    drawRectangle(tableLeft, tableTop, tableRight, totalTop + 34.0f,
                  0.68f, 0.73f, 0.76f);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(40, 60);
    glutCreateWindow("Ruiz_ StudentInfo");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
