#ifndef QCANVAS_H
#define QCANVAS_H

#include <QLabel>
#include <QWidget>

class QCanvas : public QLabel
{
    Q_OBJECT
public:
    explicit QCanvas(QWidget *parent = nullptr);

signals:
    void mousePressed(QMouseEvent *event);
    void mouseMoved(QMouseEvent *event);
    void mouseReleased(QMouseEvent *event);

protected:
    void mousePressEvent(QMouseEvent *event) override {
        emit mousePressed(event);
    }

    void mouseMoveEvent(QMouseEvent *event) override {
        emit mouseMoved(event);
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        emit mouseReleased(event);
    }
};

#endif // QCANVAS_H
