///
/// Miejsce na copyright :-)
///

#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <vector>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    constexpr static double DEFAULT_RADIUS = 75.0;

    explicit MyWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;  // Deklaracja metody obsługi zdarzeń klawiatury
    void mouseDoubleClickEvent(QMouseEvent *event) override;  // Deklaracja metody obsługi dwukliku myszki

    struct Circle
    {
        QPointF center;
        double radius;
    };

    signals:

private:
    std::vector<Circle> circles;
    QColor circleColor = Qt::darkYellow;  // Aktualny kolor kółek
};

#endif  // MYWIDGET_H
