#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    int map_size = 1000;
    QGraphicsScene* scene = new QGraphicsScene();
    QPixmap map(map_size, map_size);
    QPainter p(&map);

    QColor array[200];
    for (int i = 0; i < 200; i++)
    {
        if (i < 35) array[i] = QColor(230, 46, 46);
        else if (i < 45) array[i] = QColor(230, 83, 46);
        else if (i < 50) array[i] = QColor(230, 114, 46);
        else if (i < 55) array[i] = QColor(230, 151, 46);
        else if (i < 60) array[i] = QColor(230, 200, 46);
        else if (i < 65) array[i] = QColor(194, 230, 46);
        else if (i < 70) array[i] = QColor(138, 230, 46);
        else if (i < 75) array[i] = QColor(58, 230, 46);
        else if (i < 80) array[i] = QColor(46, 230, 138);
        else if (i < 85) array[i] = QColor(46, 230, 180);
        else if (i < 90) array[i] = QColor(46, 175, 230);
        else if (i < 95) array[i] = QColor(46, 80, 230);
        else if (i < 100) array[i] = QColor(65, 46, 230);
        else if (i < 105) array[i] = QColor(31, 18, 148);
        else if (i < 110) array[i] = QColor(19, 10, 97);
        else array[i] = QColor(0, 0, 0);
    }

    for(int i = 0; i < map_size; i++){
        for(int j = 0; j < map_size; j++){
            int dBm_array[5];
            dBm_array[0] = (int)getDBm(i + 1, j + 1, 500, 500);
            dBm_array[1] = (int)getDBm(i + 1, j + 1, 850, 100);
            dBm_array[2] = (int)getDBm(i + 1, j + 1, 278, 300);
            dBm_array[3] = (int)getDBm(i + 1, j + 1, 756, 765);
            dBm_array[4] = (int)getDBm(i + 1, j + 1, 58, 700);
            for (int k = 0; k < 5; k++) {
                for (int l = 0; l < 5; l++) {
                    if (dBm_array[l] > dBm_array[l + 1]) {
                        int b = dBm_array[l];
                        dBm_array[l] = dBm_array[l + 1];
                        dBm_array[l + 1] = b;
                    }
                }
            }
            p.setPen(array[dBm_array[0]]);
            /*if (dBm <= 40)
            {
                p.setPen(QColor(235, 18, 18));
            }
            else if (dBm > 40 && dBm <= 55)
            {
                p.setPen(QColor(236, 107, 21));
            }
            else if (dBm > 55 && dBm <= 65)
            {
                p.setPen(QColor(239, 208, 56));
            }
            else if (dBm > 65 && dBm <= 75)
            {
                p.setPen(QColor(156, 230, 44));
            }
            else if (dBm > 75 && dBm <= 85)
            {
                p.setPen(QColor(44, 230, 199));
            }
            else if (dBm > 85 && dBm <= 95)
            {
                p.setPen(QColor(44, 193, 230));
            }
            else if (dBm > 95 && dBm <= 105)
            {
                p.setPen(QColor(44, 100, 230));
            }
            else if (dBm > 105 && dBm <= 120)
            {
                p.setPen(QColor(25, 29, 139));
            }
            else if (dBm > 120)
            {
                p.setPen(QColor(Qt::black));
            }*/
            p.drawPoint(i, j);
        }
    }

    p.end();
    scene->addPixmap(map);
    QGraphicsView* view = new QGraphicsView(scene);
    setCentralWidget(view);
}

double MainWindow::calcDBm (double dist, double h)
{
    return (20 * (log10((40 * 3.14 * dist * 5) / 3)) + qMin(0.03 * pow(h, 1.72), 10.0) * log10(dist) - qMin(0.044 * pow(h, 1.72), 14.77) + (0.002 * log10(h) * dist));
}

double MainWindow::getDBm (int i, int j, int x, int y)
{
    int a = qAbs(x - i);
    int b = qAbs(y - j);
    double dist = (qSqrt(a * a + b * b)) * 0.2;
    double break_point = (2 * 3.14 * 5000000000) / 3 * qPow(10, 8);
    double h = 5;

    if (dist < 10)
    {
        return 1;
    }
    else if (dist >= 10.0 && dist <= break_point)
    {
        return calcDBm(dist, h);
    }
    else if (dist > break_point && dist < 10000.0)
    {
        return (calcDBm(break_point, h) + (40 * log10(dist / break_point)));
    }
    else
    {
        return 199;
    }

}

MainWindow::~MainWindow()
{
}

