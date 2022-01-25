#pragma once
#include <QTreeWidgetItem>
#include "smartpointerhelp.h"
#include "polygon.h"

class Node : public QTreeWidgetItem
{
private:
    Polygon2D* polygon;
    glm::vec3 color; // color to draw polygon, range in [0,1], [R, G, B]
    QString name;

public:
    std::vector<uPtr<Node>> children;

public:
    // constructors and destructors
    Node();
    Node(QString name);
    virtual ~Node();

    // get member values
    Polygon2D* getPolygon();
    glm::vec3 getColor();
    QString getName();

    // set
    void setColor(glm::vec3 color);
    void setPolygon(Polygon2D &polygon);

    virtual glm::mat3 transform() = 0; // 3*3 transformation matrix
    Node& addChild(uPtr<Node> node);
};
