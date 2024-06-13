#include "my_widget.h"

#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>

MyWidget::MyWidget(QWidget* parent)
        : QWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);  // Umożliwia odbieranie zdarzeń klawiatury
}

void MyWidget::paintEvent([[maybe_unused]] QPaintEvent* event)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(QColor(Qt::GlobalColor::darkMagenta)));
    auto r = this->rect();
    painter.drawRect(r);

    painter.setBrush(QBrush(circleColor));  // Użyj aktualnego koloru kółek
    for (const auto& circ : circles)
    {
        QPointF point(circ.center.x() * r.width(), circ.center.y() * r.height());
        painter.drawEllipse(point, circ.radius, circ.radius);
    }
}

void MyWidget::mousePressEvent(QMouseEvent* event)
{
    auto pos = event->localPos();
    auto rec = rect();
    Circle c;
    c.radius = DEFAULT_RADIUS;
    c.center.setX(pos.x() / rec.width());
    c.center.setY(pos.y() / rec.height());
    circles.push_back(c);
    repaint();
}

void MyWidget::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Z && (event->modifiers() & Qt::ControlModifier))
    {
        if (!circles.empty())
        {
            circles.pop_back();
            repaint();
        }
    }
}

void MyWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        circleColor = (circleColor == Qt::darkYellow) ? Qt::darkCyan : Qt::darkYellow;  // Przełącz kolor kółek
        repaint();
    }
}
