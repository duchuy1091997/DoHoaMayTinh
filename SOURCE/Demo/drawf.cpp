#include <GL/glew.h>
#include <GL/glut.h>
#include <stdlib.h>
GLubyte rasters[24] = {
	0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,0xff, 0x00, 0xff, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,
	0xff, 0xc0, 0xff, 0xc0 };
void init(void)
{
	//giá trị tỷ lệ, độ lệch, thay đổi trong vẽ pixel
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	//xóa màu trắng	
	glClearColor(0.0, 0.0, 0.0, 0.0);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	//Chỉ định tọa độ x,y cho vị trí raster hiện tại.
	glRasterPos2i(100, 100);
	/*xác định chiều rộng và chiều cao của hình ảnh bitmap chỉ định vị trí các giá trị x và y
	được thêm vào vị trí raster hiện tại sau khi bitmap được vẽ.*/
	glBitmap(10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
	glBitmap(10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
	glBitmap(10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
	glFlush();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
