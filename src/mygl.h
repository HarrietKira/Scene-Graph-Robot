#pragma once

#include <openglcontext.h>
#include <shaderprogram.h>
#include <scene/grid.h>
#include <scene/polygon.h>
#include <QTreeWidgetItem>

#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>
#include "scene/node.h"
#include "scene/translatenode.h"
#include "scene/scalenode.h"
#include "scene/rotatenode.h"

class MyGL
    : public OpenGLContext
{
    Q_OBJECT
private:
    ShaderProgram prog_flat;// A shader program that uses "flat" reflection (no shadowing at all)

    Grid m_geomGrid; // The instance of the object used to render the 5x5 grid
    Polygon2D m_geomSquare; // The singular instance of our square object that can be re-drawn with different colors
                         // to create the appearance of there being multiple squares

    bool m_showGrid; // Read in paintGL to determine whether or not to draw the grid.

    GLuint vao; // A handle for our vertex array object. This will store the VBOs created in our geometry classes.

    Node *mp_selectedNode; // A pointer to the Node that was last clicked on in the GUI's Tree Widget

    // TO Do
    uPtr<Node> m_root;
    Polygon2D m_geomCircle;

public:
    explicit MyGL(QWidget *parent = 0);
    ~MyGL();

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    // TO DO
    uPtr<Node> SceneGraph();
    void traverse(const uPtr<Node> &node, glm::mat3 mat);
    void setGeo(Node* node);

protected:
    void keyPressEvent(QKeyEvent *e);

signals:
    void sig_sendRootNode(QTreeWidgetItem*);

public slots:
    // Assigns mp_selectedNode to the input pointer.
    // Is connected to a signal from the Tree Widget in the GUI
    // that is emitted every time an element in the widget is clicked.
    void slot_setSelectedNode(QTreeWidgetItem*);
};

