#ifndef MOUSEEVENTS_H
#define MOUSEEVENTS_H

#include <QWidget>
#include <QGraphicsView>
#include <QDebug>

class mouseEvents : public QGraphicsView
{
  Q_OBJECT

public:
  mouseEvents(QWidget *parent) : QGraphicsView(parent) {}

protected:
  virtual void mousePressEvent(QMouseEvent *event);
  virtual void mouseReleaseEvent(QMouseEvent *event);
};

#endif // MOUSEEVENTS_H
