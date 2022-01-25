#include "mygl.h"
#include <la.h>

#include <iostream>
#include <QApplication>
#include <QKeyEvent>


MyGL::MyGL(QWidget *parent)
    : OpenGLContext(parent),
      prog_flat(this),
      m_geomGrid(this),
      m_geomSquare(this, {glm::vec3(0.5f, 0.5f, 1.f),
                          glm::vec3(-0.5f, 0.5f, 1.f),
                          glm::vec3(-0.5f, -0.5f, 1.f),
                          glm::vec3(0.5f, -0.5f, 1.f)}),
      m_showGrid(true),
      mp_selectedNode(nullptr),
      // TO DO
      m_geomCircle(this, 100)
{
    setFocusPolicy(Qt::StrongFocus);
}

MyGL::~MyGL()
{
    makeCurrent();

    glDeleteVertexArrays(1, &vao);
    m_geomSquare.destroy();
    m_geomGrid.destroy();
}

void MyGL::initializeGL()
{
    // Create an OpenGL context using Qt's QOpenGLFunctions_3_2_Core class
    // If you were programming in a non-Qt context you might use GLEW (GL Extension Wrangler)instead
    initializeOpenGLFunctions();
    // Print out some information about the current OpenGL context
    debugContextVersion();

    // Set a few settings/modes in OpenGL rendering
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    // Set the size with which points should be rendered
    glPointSize(5);
    // Set the color with which the screen is filled at the start of each render call.
    glClearColor(0.5, 0.5, 0.5, 1);

    printGLErrorLog();

    // Create a Vertex Attribute Object
    glGenVertexArrays(1, &vao);

    //Create the scene geometry
    m_geomGrid.create();
    m_geomSquare.create();
    m_geomCircle.create();

    // Create and set up the flat lighting shader
    prog_flat.create(":/glsl/flat.vert.glsl", ":/glsl/flat.frag.glsl");

    // We have to have a VAO bound in OpenGL 3.2 Core. But if we're not
    // using multiple VAOs, we can just bind one once.
    glBindVertexArray(vao);


    // TODO: Call your scene graph construction function here
    m_root = SceneGraph();
    emit sig_sendRootNode(m_root.get());
}

void MyGL::resizeGL(int w, int h)
{
    glm::mat3 viewMat = glm::scale(glm::mat3(), glm::vec2(0.2, 0.2)); // Screen is -5 to 5

    // Upload the view matrix to our shader (i.e. onto the graphics card)
    prog_flat.setViewMatrix(viewMat);

    printGLErrorLog();
}

// This function is called by Qt any time your GL window is supposed to update
// For example, when the function update() is called, paintGL is called implicitly.
void MyGL::paintGL()
{
    // Clear the screen so that we only see newly drawn images
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (m_showGrid)
    {
        prog_flat.setModelMatrix(glm::mat3());
        prog_flat.draw(*this, m_geomGrid);
    }

    traverse(m_root, glm::mat3());
    //VVV CLEAR THIS CODE WHEN YOU IMPLEMENT SCENE GRAPH TRAVERSAL VVV///////////////////

    // Shapes will be drawn on top of one another, so the last object
    // drawn will appear in front of everything else

//    prog_flat.setModelMatrix(glm::mat3());
//    m_geomSquare.setColor(glm::vec3(0,1,0));
//    prog_flat.draw(*this, m_geomSquare);

//    m_geomSquare.setColor(glm::vec3(1,0,0));
//    prog_flat.setModelMatrix(glm::translate(glm::mat3(), glm::vec2(-1.f, 0.f)) * glm::rotate(glm::mat3(), glm::radians(-30.f)));
//    prog_flat.draw(*this, m_geomSquare);

//    m_geomSquare.setColor(glm::vec3(0,0,1));
//    prog_flat.setModelMatrix(glm::translate(glm::mat3(), glm::vec2(1.f, 0.f)) * glm::rotate(glm::mat3(), glm::radians(30.f)));
//    prog_flat.draw(*this, m_geomSquare);

    //^^^ CLEAR THIS CODE WHEN YOU IMPLEMENT SCENE GRAPH TRAVERSAL ^^^/////////////////

    // Here is a good spot to call your scene graph traversal function.
    // Any time you want to draw an instance of geometry, call
    // prog_flat.draw(*this, yourNonPointerGeometry);
}

void MyGL::keyPressEvent(QKeyEvent *e)
{
    // http://doc.qt.io/qt-5/qt.html#Key-enum
    switch(e->key())
    {
    case(Qt::Key_Escape):
        QApplication::quit();
        break;

    case(Qt::Key_G):
        m_showGrid = !m_showGrid;
        break;
    }
}

void MyGL::slot_setSelectedNode(QTreeWidgetItem *i) {
    mp_selectedNode = static_cast<Node*>(i);
    qDebug() << mp_selectedNode->getName();
}
// TO DO
uPtr<Node> MyGL::SceneGraph()
{
    glm::vec3 skin_color = glm::vec3(1, 0.88, 0.74);
    float head_angle = 45.f;
    float arm_angle = 45.f;
    float leg_angle = 30.f;

    // body center, root node
    uPtr<Node> torso = mkU<TranslateNode>("torso", 0, 0);
    // head 4*2
    Node& translate_whole_head = torso->addChild(mkU<TranslateNode>("translate whole head", 0, 1));
    Node& rotate_whole_head = translate_whole_head.addChild(mkU<RotateNode>("rotate whole head", head_angle));
    Node& translate_head = rotate_whole_head.addChild(mkU<TranslateNode>("translate head", 0, 2));
    Node& scale_head = translate_head.addChild(mkU<ScaleNode>("scale head", 4, 2));
    scale_head.setPolygon(m_geomSquare);
    scale_head.setColor(skin_color);
    // hat 6*0.5
    Node& translate_hat = rotate_whole_head.addChild(mkU<TranslateNode>("translate hat", 0, 3.25));
    Node& scale_hat = translate_hat.addChild(mkU<ScaleNode>("scale hat", 6, 0.5));
    scale_hat.setPolygon(m_geomSquare);
    scale_hat.setColor(glm::vec3(1, 0.80, 0.898)); // light pink
    // neck 2*1
    Node& translate_neck = rotate_whole_head.addChild(mkU<TranslateNode>("translate neck", 0, 0.5));
    Node& scale_neck = translate_neck.addChild(mkU<ScaleNode>("scale neck", 2, 1));
    scale_neck.setPolygon(m_geomSquare);
    scale_neck.setColor(skin_color);
    // left eye
    Node& translate_LE = rotate_whole_head.addChild(mkU<TranslateNode>("translate left eye", -1, 2));
    Node& scale_LE = translate_LE.addChild(mkU<ScaleNode>("scale left eye", 0.5, 0.5));
    scale_LE.setPolygon(m_geomCircle);
    scale_LE.setColor(glm::vec3(0, 0, 0));
    // right eye
    Node& translate_RE = rotate_whole_head.addChild(mkU<TranslateNode>("translate right eye", 1, 2));
    Node& scale_RE = translate_RE.addChild(mkU<ScaleNode>("scale right eye", 0.5, 0.5));
    scale_RE.setPolygon(m_geomCircle);
    scale_RE.setColor(glm::vec3(0, 0, 0));
    // mouth
    Node& translate_mouth = rotate_whole_head.addChild(mkU<TranslateNode>("translate mouth", 0, 1.5));
    Node& scale_mouth = translate_mouth.addChild(mkU<ScaleNode>("scale mouth", 2, 0.25));
    scale_mouth.setPolygon(m_geomCircle);
    scale_mouth.setColor(glm::vec3(1, 0, 0));

    // body 3*3
    Node& translate_body = torso->addChild(mkU<TranslateNode>("translate body", 0, -0.5));
    Node& scale_body = translate_body.addChild(mkU<ScaleNode>("scale body", 3, 3));
    scale_body.setPolygon(m_geomSquare);
    scale_body.setColor(glm::vec3(0.80, 0.898, 1)); // light blue

    // left upper arm 1.5*1
    Node& translate_LA = torso->addChild(mkU<TranslateNode>("translate Left Arm", -1.5, 0));
    Node& rotate_LA = translate_LA.addChild(mkU<RotateNode>("rotate Left Arm", arm_angle));
    Node& translate_LUA = rotate_LA.addChild(mkU<TranslateNode>("translate Left Upper Arm", -0.75, 0));
    Node& scale_LUA = translate_LUA.addChild(mkU<ScaleNode>("scale Left Upper Arm", 1.5, 1));
    scale_LUA.setPolygon(m_geomSquare);
    scale_LUA.setColor(glm::vec3(0.898, 1, 0.80)); // light green
    // left lower arm 3*1
    Node& translate_LLA = rotate_LA.addChild(mkU<TranslateNode>("translate Left Lower Arm", -1.5, 0));
    Node& rotate_LLA = translate_LLA.addChild(mkU<RotateNode>("rotate Left Lower Arm", arm_angle));
    Node& translate_LLA1 = rotate_LLA.addChild(mkU<TranslateNode>("translate Left Lower Arm", -0.75, 0));
    Node& scale_LLA = translate_LLA1.addChild(mkU<ScaleNode>("scale Left Lower Arm", 1.5, 1));
    scale_LLA.setPolygon(m_geomSquare);
    scale_LLA.setColor(glm::vec3(0.898, 1, 0.80)); // light green
    // right upper arm 3*1
    Node& translate_RA = torso->addChild(mkU<TranslateNode>("translate Right Arm", 1.5, 0));
    Node& rotate_RA = translate_RA.addChild(mkU<RotateNode>("rotate Right Arm", arm_angle));
    Node& translate_RUA = rotate_RA.addChild(mkU<TranslateNode>("translate Right Upper Arm", 0.75, 0));
    Node& scale_RUA = translate_RUA.addChild(mkU<ScaleNode>("scale Right Upper Arm", 1.5, 1));
    scale_RUA.setPolygon(m_geomSquare);
    scale_RUA.setColor(glm::vec3(0.898, 1, 0.80)); // light green
    // right lower arm 3*1
    Node& translate_RLA = rotate_RA.addChild(mkU<TranslateNode>("translate Right Lower Arm", 1.5, 0));
    Node& rotate_RLA = translate_RLA.addChild(mkU<RotateNode>("rotate Right Lower Arm", arm_angle));
    Node& translate_RLA1 = rotate_RLA.addChild(mkU<TranslateNode>("translate Right Lower Arm", 0.75, 0));
    Node& scale_RLA = translate_RLA1.addChild(mkU<ScaleNode>("scale Right Lower Arm", 1.5, 1));
    scale_RLA.setPolygon(m_geomSquare);
    scale_RLA.setColor(glm::vec3(0.898, 1, 0.80)); // light green
    // left leg 1*2
    Node& translate_LL = torso->addChild(mkU<TranslateNode>("translate Left Leg", -1, -2));
    Node& rotate_LL = translate_LL.addChild(mkU<RotateNode>("rotate Left Leg", -leg_angle));
    Node& translate_LL1 = rotate_LL.addChild(mkU<TranslateNode>("translate Left Leg", 0, -1));
    Node& scale_LL = translate_LL1.addChild(mkU<ScaleNode>("scale Left Leg", 1, 2));
    scale_LL.setPolygon(m_geomSquare);
    scale_LL.setColor(glm::vec3(1, 1, 0.8)); // light yellow
    // left shoe 1*3
    Node& translate_LS = rotate_LL.addChild(mkU<TranslateNode>("translate Left Shoe", -0.75, -1.5));
    Node& scale_LS = translate_LS.addChild(mkU<ScaleNode>("scale Left Shoe", 0.5, 1));
    scale_LS.setPolygon(m_geomSquare);
    scale_LS.setColor(glm::vec3(0, 0, 0)); // black
    // right leg 1*3
    Node& translate_RL = torso->addChild(mkU<TranslateNode>("translate Right Leg", 1, -2));
    Node& rotate_RL = translate_RL.addChild(mkU<RotateNode>("rotate Right Leg", leg_angle));
    Node& translate_RL1 = rotate_RL.addChild(mkU<TranslateNode>("translate Right Leg", 0, -1));
    Node& scale_RL = translate_RL1.addChild(mkU<ScaleNode>("scale Right Leg", 1, 2));
    scale_RL.setPolygon(m_geomSquare);
    scale_RL.setColor(glm::vec3(1, 1, 0.8)); // light yellow
    // right shoe 1*3
    Node& translate_RS = rotate_RL.addChild(mkU<TranslateNode>("translate Right Shoe", 0.75, -1.5));
    Node& scale_RS = translate_RS.addChild(mkU<ScaleNode>("scale Left Shoe", 0.5, 1));
    scale_RS.setPolygon(m_geomSquare);
    scale_RS.setColor(glm::vec3(0, 0, 0)); // black
    return torso;
}
void MyGL::traverse(const uPtr<Node> &node, glm::mat3 mat)
{
    mat = mat * node->transform();
    for (const uPtr<Node> &n : node->children)
    {
        traverse(n, mat);
    }
    if (node->getPolygon() != nullptr)
    {
        node->getPolygon()->setColor(node->getColor());
        prog_flat.setModelMatrix(mat);
        prog_flat.draw(*this, *node->getPolygon());
    }
}
void MyGL::setGeo(Node* node)
{
    if (node->getPolygon() == nullptr)
    {
            node->setPolygon(m_geomSquare);
    }
}












